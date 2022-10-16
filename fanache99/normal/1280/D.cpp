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

const int MAXN = 3000;
const long long INF = 1e15;

int v[1 + MAXN];
vector<int> g[1 + MAXN];
int weight[1 + MAXN];
pair<int, long long> dp[1 + MAXN][1 + MAXN];
pair<int, long long> temp[1 + MAXN];

void DFS(int node, int father) {
    weight[node] = 1;
    dp[node][1] = {0, v[node]};
    for (auto son : g[node]) {
        if (son != father) {
            DFS(son, node);
            for (int i = 1; i <= weight[node] + weight[son]; i++) {
                temp[i] = {0, -INF};
            }
            for (int i = 1; i <= weight[node]; i++) {
                for (int j = 1; j <= weight[son]; j++) {
                    temp[i + j] = max(temp[i + j], {dp[node][i].first + dp[son][j].first + (dp[son][j].second > 0), dp[node][i].second});
                    temp[i + j - 1] = max(temp[i + j - 1], {dp[node][i].first + dp[son][j].first, dp[node][i].second + dp[son][j].second});
                }
            }
            weight[node] += weight[son];
            for (int i = 1; i <= weight[node]; i++) {
                dp[node][i] = temp[i];
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
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            v[i] = x - v[i];
        }
        for (int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        DFS(1, 0);
        cout << dp[1][k].first + (dp[1][k].second > 0) << "\n";
        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }
    }
    return 0;
}