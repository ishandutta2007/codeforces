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

const int MAXN = 1000000;
const int MOD = 998244353;

int dp[1 + MAXN][2], sum[1 + MAXN][2];

void add(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

void sub(int &x, int y) {
    x -= y;
    if (x < 0) {
        x += MOD;
    }
}

int raiseToPower(int base, int power) {
    int answer = 1;
    while (power) {
        if (power % 2)
            answer = (1LL * answer * base) % MOD;
        base = (1LL * base * base) % MOD;
        power /= 2;
    }
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
    dp[0][0] = sum[0][0] = 1;
    dp[0][1] = sum[0][1] = 0;
    int div2 = raiseToPower(2, MOD - 2);
    int div6 = raiseToPower(6, MOD - 2);
    for (int i = 1; i <= n; i++) {
        // i -> i - 1
        {
            add(dp[i][0], dp[i - 1][0]);
        }

        // i -> i - 1, i - 2
        if (i > 1) {
            add(dp[i][0], 1LL * dp[i - 1][0] * sum[i - 2][0] % MOD);
        }

        // i -> i - 1, i - 1
        {
            int x = 1LL * dp[i - 1][0] * (dp[i - 1][0] + 1) % MOD * div2 % MOD;
            add(dp[i][0], x);
        }

        // i -> i - 1, i - 2, i - 2
        if (i > 1) {
            int x = 1LL * dp[i - 1][0] * sum[i - 2][0] % MOD * (sum[i - 2][0] + 1) % MOD * div2 % MOD;
            add(dp[i][1], x);
        }

        // i -> i - 1, i - 1, i - 2
        if (i > 1) {
            int x = 1LL * dp[i - 1][0] * (dp[i - 1][0] + 1) % MOD * div2 % MOD * sum[i - 2][0] % MOD;
            add(dp[i][1], x);
        }

        // i -> i - 1, i - 1, i - 1
        {
            int x = 1LL * dp[i - 1][0] * (dp[i - 1][0] + 1) % MOD * (dp[i - 1][0] + 2) % MOD * div6 % MOD;
            add(dp[i][1], x);
        }

        sum[i][0] = sum[i - 1][0];
        add(sum[i][0], dp[i][0]);
        sum[i][1] = sum[i - 1][1];
        add(sum[i][1], dp[i][1]);
    }
    int ans = dp[n][0];
    add(ans, dp[n][1]);
    add(ans, ans);
    sub(ans, 1);
    for (int i = 1; i <= n - 1; i++) {
        int x = dp[i][0];
        sub(x, dp[i - 1][0]);
        int y = dp[n - i - 1][0];
        sub(y, 1);
        add(ans, 1LL * x * y % MOD);
    }
    for (int i = 1; 2 * i + 1 <= n; i++) {
        int x = dp[i][0];
        sub(x, dp[i - 1][0]);
        //add(ans, 1LL * x * x % MOD);
    }
    cout << ans << "\n";
    return 0;
}