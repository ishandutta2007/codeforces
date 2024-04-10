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
#include <unordered_set>

using namespace std;

class InputReader {
public:
    InputReader() {}
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

const int MAXN = 100000;
const int INF = 1000000000;

int v[1 + MAXN], have[1 + 2 * MAXN];
int dp[1 + 2 * MAXN + 1][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //ifstream cin("input.txt");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            have[v[i]]++;
        }
        dp[2 * n + 1][0] = 0;
        dp[2 * n + 1][1] = -INF;
        for (int i = 2 * n; i >= 1; i--) {
            if (!have[i]) {
                dp[i][0] = max(dp[i + 1][0], dp[i + 1][1]);
                dp[i][1] = -INF;
            } else if (have[i] == 1) {
                dp[i][0] = max(1 + dp[i + 1][0], dp[i + 1][1]);
                dp[i][1] = 1 + max(dp[i + 1][0], dp[i + 1][1]);
            } else {
                dp[i][0] = max(1 + dp[i + 1][0], dp[i + 1][1]);
                dp[i][1] = max(1 + max(dp[i + 1][0], dp[i + 1][1]), 1 + max(1 + dp[i + 1][0], dp[i + 1][1]));
            }
        }
        cout << max(dp[1][0], dp[1][1]) << "\n";
        for (int i = 1; i <= 2 * n; i++) {
            have[i] = 0;
        }
    }
    return 0;
}