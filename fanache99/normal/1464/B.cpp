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
const long long INF = 1000000000000000000LL;

char s[1 + MAXN];
long long sum[1 + MAXN][2], add[1 + MAXN][2];
long long sumLeft[1 + MAXN][2], sumRight[1 + MAXN + 1][2];
int pos[1 + MAXN];
int c[2][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //ifstream cin("input.txt");
    int c01, c10, k = 0;
    cin >> (s + 1) >> c[0][1] >> c[1][0];
    int n = strlen(s + 1);
    long long fixed = 0;
    for (int i = 1; i <= n; i++) {
        sum[i][0] = sum[i - 1][0];
        sum[i][1] = sum[i - 1][1];
        if (s[i] != '?') {
            s[i] -= '0';
            fixed += 1LL * c[1 - s[i]][s[i]] * sum[i - 1][1 - s[i]];
            sum[i][s[i]]++;
        } else {
            s[i] = -1;
            k++;
            pos[k] = i;
        }
    }
    for (int i = 1; i <= k; i++) {
        for (int ch = 0; ch < 2; ch++) {
            add[i][ch] = 1LL * c[1 - ch][ch] * sum[pos[i] - 1][1 - ch] + 1LL * c[ch][1 - ch] * (sum[n][1 - ch] - sum[pos[i]][1 - ch]);
            sumLeft[i][ch] = sumLeft[i - 1][ch] + add[i][ch];
        }
    }
    for (int i = k; i >= 1; i--) {
        for (int ch = 0; ch < 2; ch++) {
            sumRight[i][ch] = sumRight[i + 1][ch] + add[i][ch];
        }
    }
    long long best = INF;
    for (int i = 0; i <= k; i++) {
        for (int ch = 0; ch < 2; ch++) {
            best = min(best, sumLeft[i][ch] + sumRight[i + 1][1 - ch] + 1LL * c[ch][1 - ch] * i * (k - i));
            best = min(best, sumLeft[i][1 - ch] + sumRight[i + 1][ch] + 1LL * c[1 - ch][ch] * i * (k - i));
        }
    }
    cout << fixed + best << "\n";
    return 0;
}