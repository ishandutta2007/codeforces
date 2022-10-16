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
#include <unordered_set>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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

    inline InputReader &operator>>(int &n) {
        while ((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while ('0' <= buffer[cursor] && buffer[cursor] <= '9') {
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
        ++cursor;
        if (cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int MAXN = 200000;
const int MAXM = 200000;

vector<pair<int, int> > g[1 + MAXN];
int active, answer[1 + MAXM], deg[1 + MAXN], id;
int from[1 + MAXM], to[1 + MAXM], k;
bool out[1 + MAXN];

void go(int node) {
    out[node] = true;
    active--;
    for (auto it : g[node]) {
        if (it.second <= id) {
            deg[it.first]--;
            if (!out[it.first] && deg[it.first] < k) {
                go(it.first);
            }
        }
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, m;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        from[i] = a;
        to[i] = b;
        deg[a]++;
        deg[b]++;
        g[b].push_back(make_pair(a, i));
        g[a].push_back(make_pair(b, i));
    }
    active = n;
    id = m;
    for (int i = 1; i <= n; i++) {
        if (!out[i] && deg[i] < k) {
            go(i);
        }
    }
    answer[m] = active;
    for (int i = m; i > 1; i--) {
        id = i - 1;
        if (!out[to[i]] && !out[from[i]]) {
            deg[from[i]]--;
            deg[to[i]]--;
            if (!out[from[i]] && deg[from[i]] < k) {
                go(from[i]);
            }
            if (!out[to[i]] && deg[to[i]] < k) {
                go(to[i]);
            }
        }
        answer[i - 1] = active;
    }
    for (int i = 1; i <= m; i++) {
        cout << answer[i] << "\n";
    }
    return 0;
}