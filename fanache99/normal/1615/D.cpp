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
#include <complex>
#include <unordered_set>
#include <chrono>
#include <random>

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

    template<typename T>
    inline InputReader &operator>>(T &n) {
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
const int MAXLOG = 20;

char a[1 + MAXN], b[1 + MAXN];
vector<pair<int, int> > g[1 + MAXN], t[1 + MAXN];
int xorSum[1 + MAXN], dad[1 + MAXN], edge[1 + MAXN];

void DFS(int node, int father) {
    for (auto [son, c] : t[node]) {
        if (son != father) {
            dad[son] = node;
            edge[son] = c;
            if (c != -1) {
                g[son].push_back({node, 0});
                g[node].push_back({son, 0});
            } else {
                c = 0;
            }
            xorSum[son] = xorSum[node] ^ c;
            DFS(son, node);
        }
    }
}

bool seen[1 + MAXN];
int col[1 + MAXN];
bool bad;

void DFS2(int node, int c) {
    col[node] = c;
    seen[node] = true;
    for (auto [it, p] : g[node]) {
        if (!seen[it]) {
            DFS2(it, c ^ p);
        } else {
            if (col[it] ^ col[node] != p) {
                bad = true;
            }
        }
        if (bad) {
            break;
        }
    }
}

void solve(int n) {
    bad = false;
    for (int i = 1; i <= n && !bad; i++) {
        if (!seen[i]) {
            DFS2(i, 0);
        }
    }
}

int main() {
    timeBegin();
    //  ifstream cin("input.txt");
//    ofstream cout("answer.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            t[a].push_back({b, c});
            t[b].push_back({a, c});
        }
        xorSum[1] = dad[1] = edge[1] = 0;
        DFS(1, 0);
        for (int i = 1; i <= m; i++) {
            int a, b, p;
            cin >> a >> b >> p;
            int q = __builtin_popcount(xorSum[a] ^ xorSum[b]) % 2;
            int r = p ^ q;
            g[a].push_back({b, r});
            g[b].push_back({a, r});
        }
        solve(n);
        if (bad) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 2; i <= n; i++) {
                if (col[i] == col[dad[i]]) {
                    cout << i << " " << dad[i] << " " << max(edge[i], 0) << "\n";
                } else {
                    assert(edge[i] == -1);
                    cout << i << " " << dad[i] << " 1\n";
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            t[i].clear();
            g[i].clear();
            seen[i] = false;
        }
    }
    return 0;
}