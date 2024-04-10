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

using namespace std;

clock_t timeStart, timeFinish;

void timeBegin() {
    timeStart = clock();
}

void timeEnd() {
    timeFinish = clock();
}

void timeDuration() {
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
    inline InputReader &operator >>(int &n) {
        while((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
        n *= sign;
        return *this;
    }
    inline InputReader &operator >>(long long &n) {
        while((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
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
        ++ cursor;
        if(cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int MAXN = 1000000;
const long long INF = 1000000000000000000LL;

int v[1 + MAXN];
long long dp[1 + MAXN][2], sum[1 + MAXN];

int main() {
    timeBegin();
    InputReader cin;
    //ofstream cout("papagali.out");
    int n, r1, r2, r3, d;
    cin >> n >> r1 >> r2 >> r3 >> d;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    dp[1][0] = 1LL * v[1] * r1 + r3;
    dp[1][1] = min(1LL * r2, 1LL * v[1] * r1 + r1);
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i][1] = INF;
        dp[i][0] = min(dp[i][0], dp[i - 1][0] + d + 1LL * v[i] * r1 + r3);
        dp[i][1] = min(dp[i][1], dp[i - 1][0] + d + min(1LL * r2, 1LL * v[i] * r1 + r1));
        dp[i][0] = min(dp[i][0], dp[i - 1][1] + r1 + 3LL * d + min(1LL * v[i] * r1 + r3, min(1LL * r2 + r1, 1LL * v[i] * r1 + 2 * r1)));
    }
    sum[n] = min(1LL * v[n] * r1 + r3, 2LL * d + min(1LL * r2 + r1, 1LL * v[n] * r1 + 2 * r1));
    for (int i = n - 1; i >= 1; i--) {
        sum[i] = sum[i + 1] + min(1LL * v[i] * r1 + r3, min(1LL * r2 + r1, 1LL * v[i] * r1 + 2 * r1));
    }
    long long answer = min(dp[n][0], dp[n][1] + 2LL * d + r1);
    for (int i = 1; i < n; i++) {
        answer = min(answer, dp[i][1] + 2LL * d * (n - i) + sum[i + 1] + r1);
    }
    cout << answer << "\n";
    //timeDuration();
    return 0;
}