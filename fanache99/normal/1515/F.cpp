#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <unordered_map>

using namespace std;

clock_t timeStart, timeFinish;

void timeBegin() {
    timeStart = clock();
}

void timeEnd() {
    timeFinish = clock();
}

void timeDuration() {
    timeEnd();
    double time_taken = double(timeFinish - timeStart) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;
}

class InputReader {
public:
    InputReader() {
        input_file = stdin;
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }
    InputReader(const char *file_name) {
        input_file = fopen(file_name, "r");
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }
    inline InputReader &operator >>(int &n) {
        while((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
        n *= sign;
        return *this;
    }
private:
    FILE *input_file;
    static const int SIZE = 1 << 17;
    int cursor;
    char buffer[SIZE];
    inline void advance() {
        ++ cursor;
        if(cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int MAXN = 300000;

int v[1 + MAXN];
vector<pair<int, int> > g[1 + MAXN];
int dad[1 + MAXN];
long long total[1 + MAXN];
set<pair<long long, int> > h;

void initialize(int n) {
    for (int i = 1; i <= n; i++) {
        dad[i] = i;
        total[i] = v[i];
        h.insert({v[i], i});
    }
}

int findDad(int node) {
    if (dad[node] == node) {
        return node;
    }
    return dad[node] = findDad(dad[node]);
}

int join(int a, int b, int x) {
    if (g[a].size() > g[b].size()) {
        swap(a, b);
    }
    for (auto it : g[a]) {
        g[b].push_back(it);
    }
    dad[a] = b;
    total[b] += total[a] - x;
    return b;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, m, x;
    cin >> n >> m >> x;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back({b, i});
        g[b].push_back({a, i});
    }
    if (sum < 1LL * (n - 1) * x) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        initialize(n);
        for (int step = 1; step < n; step++) {
            int id = (*h.rbegin()).second;
            h.erase(*h.rbegin());
            while (!g[id].empty() && findDad(g[id].back().first) == id) {
                g[id].pop_back();
            }
            assert(!g[id].empty());
            int other = findDad(g[id].back().first);
            h.erase({total[other], other});
            assert(total[id] + total[other] >= x);
            cout << g[id].back().second << "\n";
            int newId = join(id, other, x);
            h.insert({total[newId], newId});
        }
    }
    return 0;
}