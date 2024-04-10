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
#include <bitset>
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

const int MAXN = 100000;
const int MAXLOG = 60;

long long v[1 + MAXN];
int howMany[MAXLOG];
vector<int> g[1 + MAXN];
int d[1 + MAXN];

int solve(int n, int a, int b) {
    for (int i = 1; i <= n; i++) {
        d[i] = n + 1;
    }
    d[a] = 1;
    queue<int> q;
    q.push(a);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto other : g[node]) {
            if (d[other] == n + 1 && (node != a || other != b)) {
                d[other] = d[node] + 1;
                q.push(other);
            }
        }
    }
    return d[b];
}

void clear0(int &n) {
    int m = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] > 0) {
            v[++m] = v[i];
        }
    }
    n = m;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream fout("input.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    clear0(n);
    for (int i = 1; i <= n; i++) {
        for (int bit = 0; bit < MAXLOG; bit++) {
            if ((v[i] >> bit) & 1) {
                howMany[bit]++;
                if (howMany[bit] >= 3) {
                    cout << "3\n";
                    return 0;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if ((v[i] & v[j]) != 0) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    int best = n + 1;
    for (int i = 1; i <= n; i++) {
        for (auto j : g[i]) {
            best = min(best, solve(n, i, j));
        }
    }
    if (best == n + 1) {
        cout << "-1\n";
    } else {
        cout << best << "\n";
    }
    //timeDuration();
    return 0;
}