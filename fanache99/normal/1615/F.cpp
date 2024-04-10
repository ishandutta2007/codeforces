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

const int MAXN = 2000;
const int MOD = 1000000007;

char s[1 + MAXN], t[1 + MAXN];
int dp[1 + MAXN][1 + 4 * MAXN], sum[1 + MAXN][1 + 4 * MAXN];
// 0/+: odd on s, even on t
// 1/-: even on s, odd on t

bool ok(char a[], int p, int x) {
    char ch = x + '0';
    return a[p] == '?' || a[p] == ch;
}

void add(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
    if (x < 0) {
        x += MOD;
    }
}

int main() {
    timeBegin();
    //  ifstream cin("input.txt");
//    ofstream cout("answer.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n >> (s + 1) >> (t + 1);
        const int OFFSET = 2 * n;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= 4 * n; j++) {
                dp[i][j] = sum[i][j] = 0;
            }
        }
        dp[0][OFFSET + 0] = 1;
        sum[0][OFFSET + 0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = -2 * n; j <= 2 * n; j++) {
                if (dp[i - 1][OFFSET + j] == 0) {
                    continue;
                }
                for (int xs = 0; xs < 2; xs++) {
                    for (int xt = 0; xt < 2; xt++) {
                        if (!ok(s, i, xs) || !ok(t, i, xt)) {
                            continue;
                        }
                        int j0 = j, sgs = 0, sgt = 0;
                        if (xs != 0) {
                            if (i % 2 == 0) {
                                if (j0 <= 0) {
                                    sgs = -1;
                                } else {
                                    sgs = 1;
                                }
                                j0--;
                            } else {
                                if (j0 >= 0) {
                                    sgs = -1;
                                } else {
                                    sgs = 1;
                                }
                                j0++;
                            }
                        }
                        if (xt != 0) {
                            if (i % 2 == 0) {
                                if (j0 >= 0) {
                                    sgt = -1;
                                } else {
                                    sgt = 1;
                                }
                                j0++;
                            } else {
                                if (j0 <= 0) {
                                    sgt = -1;
                                } else {
                                    sgt = 1;
                                }
                                j0--;
                            }
                        }
                        add(dp[i][OFFSET + j0], dp[i - 1][OFFSET + j]);
                        add(sum[i][OFFSET + j0], sum[i - 1][OFFSET + j]);
                        add(sum[i][OFFSET + j0], 1LL * dp[i - 1][OFFSET + j] * (sgs * i + sgt * i) % MOD);
                    }
                }
            }
        }
        cout << sum[n][OFFSET + 0] << "\n";
    }
    return 0;
}