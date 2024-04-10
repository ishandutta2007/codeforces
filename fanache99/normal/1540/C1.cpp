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

const int MAXN = 100;
const int MAXVAL = 100;
const int MOD = 1000000007;

int c[1 + MAXN], b[1 + MAXN];
int dp[1 + MAXN][1 + MAXN * MAXVAL];
int sum[1 + MAXN][1 + MAXN * MAXVAL];

void sub(int &x, int y) {
    x -= y;
    if (x < 0) {
        x += MOD;
    }
}

void add(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

int compute(int n, int s, int x) {
    memset(dp, 0, sizeof(dp));
    memset(sum, 0, sizeof(sum));
    dp[0][0] = 1;
    for (int j = 0; j <= s; j++) {
        sum[0][j] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = max(0, i * x + b[i]); j <= s; j++) {
            dp[i][j] = sum[i - 1][j];
            if (j > c[i]) {
                sub(dp[i][j], sum[i - 1][j - c[i] - 1]);
            }
            sum[i][j] = dp[i][j];
            if (j > 0) {
                add(sum[i][j], sum[i][j - 1]);
            }
        }
    }
    return sum[n][s];
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, s = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        s += c[i];
    }
    for (int i = 2, bSum = 0; i <= n; i++) {
        cin >> b[i];
        bSum += b[i];
        b[i] = b[i - 1] + bSum;
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        cout << compute(n, s, x) << "\n";
    }
    return 0;
}