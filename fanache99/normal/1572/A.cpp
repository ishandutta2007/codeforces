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

const int MAXN = 200000;

vector<int> in[1 + MAXN], out[1 + MAXN];
int deg[1 + MAXN];
int q[1 + MAXN], dp[1 + MAXN];

int main() {
    timeBegin();
    //ifstream cin("input.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int k;
            cin >> k;
            for (int j = 1; j <= k; j++) {
                int x;
                cin >> x;
                out[i].push_back(x);
                in[x].push_back(i);
                deg[i]++;
            }
        }
        int l = 1, r = 0, ans = 1;
        for (int i = 1; i <= n; i++) {
            if (deg[i] == 0) {
                r++;
                q[r] = i;
                dp[i] = 1;
            }
        }
        while (l <= r) {
            int node = q[l];
            l++;
            for (auto it : in[node]) {
                deg[it]--;
                if (deg[it] == 0) {
                    r++;
                    q[r] = it;
                    dp[it] = 1;
                    for (auto jt : out[it]) {
                        if (jt < it) {
                            dp[it] = max(dp[it], dp[jt]);
                        } else {
                            dp[it] = max(dp[it], dp[jt] + 1);
                        }
                    }
                    ans = max(ans, dp[it]);
                }
            }
        }
        if (r != n) {
            ans = -1;
        }
        cout << ans << "\n";
        for (int i = 1; i <= n; i++) {
            in[i].clear();
            out[i].clear();
            deg[i] = 0;
            dp[i] = 0;
        }
    }
    return 0;
}