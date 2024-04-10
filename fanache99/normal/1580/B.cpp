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

const int MAXN = 100;

int MOD;
int dp[1 + MAXN][1 + MAXN][1 + MAXN];
int c[1 + MAXN][1 + MAXN], fact[1 + MAXN];

int doDp(int m, int n, int k) {
    if (dp[m][n][k] != -1) {
        return dp[m][n][k];
    }
    int ans;
    if (n == 0) {
        ans = 1;
    } else if (k > 0 && n < m) {
        ans = 0;
    } else if (m == 1) {
        ans = (k == 1 ? fact[n] : 0);
    } else {
        ans = 0;
        for (int p = 1; p <= n; p++) {
            int add = 0;
            for (int a = max(0, k + p - n); a <= min(k, p - 1); a++) {
                add = (1LL * doDp(m - 1, p - 1, a) * doDp(m - 1, n - p, k - a) % MOD + add) % MOD;
            }
            ans = (1LL * add * c[n - 1][p - 1] + ans) % MOD;
        }
    }
    dp[m][n][k] = ans;
    return ans;
}

int main() {
    timeBegin();
    InputReader cin;
    //  ifstream cin("input.txt");
//    ofstream cout("answer.txt");
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    srand(time(0));
    int n, m, k;
    cin >> n >> m >> k >> MOD;
    fact[0] = c[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        c[i][0] = c[i][i] = 1;
        fact[i] = 1LL * fact[i - 1] * i % MOD;
        for (int j = 1; j < i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << doDp(m, n, k) << "\n";
    return 0;
}