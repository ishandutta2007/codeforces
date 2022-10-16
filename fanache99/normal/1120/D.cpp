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
const long long INF = 1e18;

int c[1 + MAXN];
vector<int> g[1 + MAXN], sol;
long long dp[1 + MAXN][2];
bool seen[1 + MAXN][2];

void DFS(int node, int father) {
    if (node != 1 && g[node].size() == 1) {
        dp[node][0] = c[node];
        dp[node][1] = 0;
        return;
    }
    long long sum0 = 0, best = INF;
    for (auto son : g[node]) {
        if (son != father) {
            DFS(son, node);
            sum0 += dp[son][0];
            best = min(best, dp[son][1] - dp[son][0]);
        }
    }
    dp[node][0] = min(sum0, c[node] + sum0 + best);
    dp[node][1] = sum0 + best;
}

void DFS2(int node, int father, int type) {
    if (seen[node][type]) {
        return;
    }
    seen[node][type] = true;
    if (node != 1 && g[node].size() == 1) {
        if (type == 0) {
            sol.push_back(node);
        }
        return;
    }
    long long sum0 = 0, best = INF, howMany = 0;
    for (auto son : g[node]) {
        if (son != father) {
            sum0 += dp[son][0];
            if (dp[son][1] - dp[son][0] < best) {
                best = dp[son][1] - dp[son][0];
                howMany = 1;
            } else if (dp[son][1] - dp[son][0] == best) {
                howMany++;
            }
        }
    }
    if (type == 0) {
        if (sum0 == dp[node][0]) {
            for (auto son : g[node]) {
                if (son != father) {
                    DFS2(son, node, 0);
                }
            }
        }
        if (c[node] + sum0 + best == dp[node][0]) {
            sol.push_back(node);
            for (auto son : g[node]) {
                if (son != father) {
                    if (dp[son][1] - dp[son][0] == best) {
                        DFS2(son, node, 1);
                        if (howMany > 1) {
                            DFS2(son, node, 0);
                        }
                    } else {
                        DFS2(son, node, 0);
                    }
                }
            }
        }
    } else {
        for (auto son : g[node]) {
            if (son != father) {
                if (dp[son][1] - dp[son][0] == best) {
                    DFS2(son, node, 1);
                    if (howMany > 1) {
                        DFS2(son, node, 0);
                    }
                } else {
                    DFS2(son, node, 0);
                }
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
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    DFS(1, 0);
    DFS2(1, 0, 0);
    sort(sol.begin(), sol.end());
    cout << dp[1][0] << " " << sol.size() << "\n";
    for (auto it : sol) {
        cout << it << " ";
    }
    return 0;
}