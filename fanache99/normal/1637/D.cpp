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
const int MAXVAL = 100;
const long long INF = 1e18;

int a[1 + MAXN], b[1 + MAXN];
long long dp[1 + MAXN][1 + MAXN * MAXVAL];

int main() {
    timeBegin();
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ans += a[i] * a[i] * (n - 1);
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            ans += b[i] * b[i] * (n - 1);
        }

        dp[0][0] = 0;
        for (int i = 1; i <= n * MAXVAL; i++) {
            dp[0][i] = INF;
        }

        for (int i = 1, sum = 0; i <= n; i++) {
            for (int j = 0; j <= n * MAXVAL; j++) {
                dp[i][j] = INF;
            }

            for (int aSum = 0; aSum <= sum; aSum++) {
                if (dp[i - 1][aSum] != INF) {
                    int bSum = sum - aSum;
                    dp[i][aSum + a[i]] = min(dp[i][aSum + a[i]], dp[i - 1][aSum] + 2 * aSum * a[i] + 2 * bSum * b[i]);
                    dp[i][aSum + b[i]] = min(dp[i][aSum + b[i]], dp[i - 1][aSum] + 2 * aSum * b[i] + 2 * bSum * a[i]);
                }
            }

            sum += a[i];
            sum += b[i];
        }

        long long best = INF;
        for (int i = 0; i <= n * MAXVAL; i++) {
            best = min(best, dp[n][i]);
        }
        assert(best != INF);
        cout << ans + best << "\n";
    }
    return 0;
}