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

const int MAXN = 200;
const int MOD = 1000000007;

void addTo(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

int raiseToPower(int base, int power) {
    int answer = 1;
    while (power) {
        if (power & 1) {
            answer = 1LL * answer * base % MOD;
        }
        base = 1LL * base * base % MOD;
        power >>= 1;
    }
    return answer;
}

vector<int> g[1 + MAXN];
int depth[1 + MAXN];
int dp[1 + MAXN][1 + MAXN];

void precompute(int n) {
    for (int j = 1; j <= n; j++) {
        dp[0][j] = 1;
    }
    int div2 = raiseToPower(2, MOD - 2);
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0;
        for (int j = 1; j <= n; j++) {
            dp[i][j] = 1LL * (dp[i - 1][j] + dp[i][j - 1]) * div2 % MOD;
        }
    }
}

vector<int> DFS(int node, int father, int &answer) {
    depth[node] = depth[father] + 1;
    vector<int> nodes = {node};
    for (auto son : g[node]) {
        if (son != father) {
            vector<int> sons = DFS(son, node, answer);
            for (auto a : nodes) {
                for (auto b : sons) {
                    int x = depth[a] - depth[node], y = depth[b] - depth[node];
                    addTo(answer, (a > b ? dp[x][y] : dp[y][x]));
                }
            }
            for (auto it : sons) {
                nodes.push_back(it);
            }
        }
    }
    return nodes;
}

int root(int r) {
    int answer = 0;
    DFS(r, 0, answer);
    return answer;
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
    precompute(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        addTo(answer, root(i));
    }
    answer = 1LL * answer * raiseToPower(n, MOD - 2) % MOD;
    cout << answer << "\n";
    return 0;
}