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

const int MAXN = 50;

vector<int> g[1 + MAXN];
int n, weight[1 + MAXN];
long double fact[1 + MAXN], comb[1 + MAXN][1 + MAXN], dp[1 + MAXN][1 + MAXN], temp[1 + MAXN];
long double total[1 + MAXN];

void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
    }
    for (int i = 0; i <= n; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
        }
    }
}

void DFS(int node, int father) {
    for (int i = 0; i <= n; i++) {
        dp[node][i] = 0;
    }
    weight[node] = 1;
    dp[node][0] = 1;
    for (auto son : g[node]) {
        if (son != father) {
            DFS(son, node);
            for (int i = 0; i <= weight[son]; i++) {
                temp[i] = dp[son][i] * (weight[son] - i);
                for (int j = 0; j < i; j++) {
                    temp[i] += dp[son][j] * 0.5;
                }
            }
            for (int i = 0; i <= n; i++) {
                total[i] = 0;
            }
            for (int i = 0; i < weight[node]; i++) {
                for (int j = 0; j <= weight[son]; j++) {
                    total[i + j] += dp[node][i] * temp[j] * comb[i + j][i] * comb[weight[node] - i - 1 + weight[son] - j][weight[node] - i - 1];
                }
            }
            weight[node] += weight[son];
            for (int i = 0; i < weight[node]; i++) {
                dp[node][i] = total[i];
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
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    precompute();
    for (int i = 1; i <= n; i++) {
        DFS(i, 0);

        cout << fixed << setprecision(12) << dp[i][n - 1] / fact[n - 1] << "\n";
    }
    return 0;
}