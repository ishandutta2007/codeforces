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
#include <functional>
#include <random>

using namespace std;
using namespace std::chrono;

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

bool dp[1 + MAXN][1 + MAXN][2];

int main() {
    // ifstream cin("input.txt");
//    ofstream cout("output.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, odd = 0, even = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        dp[0][0][0] = true;
        dp[0][0][1] = false;

        for (int s = 1; s <= n; s++) {
            for (int i = 0; i <= s; i++) {
                int j = s - i;
                for (int x = 0; x < 2; x++) {
                    // Alice's turn.
                    if ((n - s) % 2 == 0) {
                        if (i == 0) {
                            dp[i][j][x] = dp[i][j - 1][x ^ 1];
                        } else if (j == 0) {
                            dp[i][j][x] = dp[i - 1][j][x];
                        } else {
                            dp[i][j][x] = dp[i - 1][j][x] || dp[i][j - 1][x ^ 1];
                        }
                    } else {
                        if (i == 0) {
                            dp[i][j][x] = dp[i][j - 1][x];
                        } else if (j == 0) {
                            dp[i][j][x] = dp[i - 1][j][x];
                        } else {
                            dp[i][j][x] = dp[i - 1][j][x] && dp[i][j - 1][x];
                        }
                    }
                }
            }
        }

        cout << (dp[even][odd][0] ? "Alice" : "Bob") << "\n";
    }

    auto stopTime = high_resolution_clock::now();
//    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}