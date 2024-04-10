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

const int MAXM = 2000;
const int MAXN = 12;

struct Col {
    vector<int> r;
    int mx;

    bool operator < (const Col& other) const {
        return mx > other.mx;
    }
};

Col c[1 + MAXM];
int dp[1 + MAXM][1 << MAXN], best[1 << MAXN];

int main() {
    timeBegin();
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, m;
        cin >> n >> m;
        for (int j = 1; j <= m; j++) {
            c[j].r.resize(n);
            c[j].mx = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> c[j].r[i];
                c[j].mx = max(c[j].mx, c[j].r[i]);
            }
        }
        sort(c + 1, c + m + 1);
        for (int mask = 0; mask < (1 << n); mask++) {
            dp[0][mask] = 0;
        }
        m = min(n, m);
        for (int j = 1; j <= m; j++) {
            for (int mask = 0; mask < (1 << n); mask++) {
                best[mask] = 0;
                for (int d = 0; d < n; d++) {
                    int curr = 0;
                    for (int i = 0; i < n; i++) {
                        if ((mask >> i) & 1) {
                            curr += c[j].r[(i + d) % n];
                        }
                    }
                    best[mask] = max(best[mask], curr);
                }
            }
            for (int mask = 0; mask < (1 << n); mask++) {
                dp[j][mask] = dp[j - 1][mask];
                for (int subMask = mask; subMask != 0; subMask = (mask & (subMask - 1))) {
                    dp[j][mask] = max(dp[j][mask], best[subMask] + dp[j - 1][mask ^ subMask]);
                }
            }
        }
        cout << dp[m][(1 << n) - 1] << "\n";
    }
    return 0;
}