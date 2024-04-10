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

int dp[2][1 + MAXN][1 + MAXN * MAXN];
int a[1 + MAXN], b[1 + MAXN];

int main() {
    timeBegin();
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, sum = 0;
    cin >> n;
    int now = 0, before = 1;
    memset(dp[now], -1, sizeof(dp[now]));
    dp[now][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        sum += b[i];
        swap(now, before);
        memset(dp[now], -1, sizeof(dp[now]));
        for (int j = 0; j <= i; j++) {
            for (int s = 0; s <= MAXN * i; s++) {
                dp[now][j][s] = dp[before][j][s];
                if (j > 0 && s >= b[i] && dp[before][j - 1][s - b[i]] != -1) {
                    dp[now][j][s] = max(dp[now][j][s], dp[before][j - 1][s - b[i]] + a[i]);
                }
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        int ans = 0;
        for (int s = 0; s <= sum; s++) {
            if (dp[now][k][s] != -1) {
                assert(dp[now][k][s] >= s);
                ans = max(ans, 2 * s + min(sum - s, 2 * (dp[now][k][s] - s)));
            }
        }
        cout << fixed << setprecision(6) << 0.5 * ans << " ";
    }
    return 0;
}