#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>

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
        while(buffer[cursor] < '0' || buffer[cursor] > '9') {
            advance();
        }
        n = 0;
        while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
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

const int MOD = 998244353;
const int MAXN = 3000;

char s[1 + MAXN], t[1 + MAXN];
int power2[1 + MAXN];

void addTo(int &x, int y) {
    x += y;
    if (x >= MOD)
        x -= MOD;
}

int dp[1 + MAXN][1 + MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //ifstream cin("input.in");
    cin >> s + 1 >> t + 1;
    int n = strlen(s + 1), m = strlen(t + 1);
    power2[0] = 1;
    for (int i = 1; i <= n; i++) {
        power2[i] = power2[i - 1];
        addTo(power2[i], power2[i - 1]);
    }
    for (int i = m; i <= n; i++)
        dp[i][0] = 1;
    for (int i = n; i >= 1; i--)
        for (int j = 0; j <= m; j++)
            if (dp[i][j]) {
                if (j < m && s[i] == t[j + 1])
                    addTo(dp[i - 1][j + 1], dp[i][j]);
                if (j == m)
                    addTo(dp[i - 1][j], dp[i][j]);
                if (i > m - j || s[i] == t[j + i])
                    addTo(dp[i - 1][j], dp[i][j]);
            }
    int answer = 0;
    for (int i = 0; i <= m; i++)
        addTo(answer, dp[0][i]);
    cout <<  answer << "\n";
    return 0;
}