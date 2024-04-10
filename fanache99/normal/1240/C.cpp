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

const int MAXN = 500000;
const long long INF = 1e18;

vector<pair<int, int> > g[1 + MAXN];
long long dp[1 + MAXN][2];

void DFS(int node, int father, int k) {
    vector<long long> sons;
    long long sum = 0;
    for (auto it : g[node]) {
        int son = it.first, cost = it.second;
        if (son != father) {
            DFS(son, node, k);
            long long withoutEdge = max(dp[son][0], dp[son][1]);
            long long withEdge = cost + dp[son][0];
            sum += withoutEdge;
            sons.push_back(withEdge - withoutEdge);
        }
    }
    sort(sons.begin(), sons.end());
    reverse(sons.begin(), sons.end());
    dp[node][0] = sum;
    for (int i = 0; i < k - 1 && i < sons.size() && sons[i] >= 0; i++) {
        dp[node][0] += sons[i];
    }
    if (sons.size() < k) {
        dp[node][1] = -INF;
    } else {
        dp[node][1] = sum;
        for (int i = 0; i < k; i++) {
            dp[node][1] += sons[i];
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
        for (int i = 1; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            g[a].push_back({b, c});
            g[b].push_back({a, c});
        }
        DFS(1, 0, k);
        cout << max(dp[1][0], dp[1][1]) << "\n";
        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }
    }
    return 0;
}