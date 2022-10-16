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

const int MAXN = 200000;

char s[1 + MAXN];
int maxLeft[1 + MAXN], minLeft[1 + MAXN], sum[1 + MAXN];
int maxRight[1 + MAXN + 1], minRight[1 + MAXN + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //ifstream cin("input.txt");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, q;
        cin >> n >> q >> (s + 1);
        maxLeft[0] = minLeft[0] = sum[0] = 0;
        for (int i = 1; i <= n; i++) {
            int x = (s[i] == '+' ? 1 : -1);
            sum[i] = sum[i - 1] + x;
            maxLeft[i] = max(maxLeft[i - 1], sum[i]);
            minLeft[i] = min(minLeft[i - 1], sum[i]);
        }
        minRight[n + 1] = maxRight[n + 1] = 0;
        for (int i = n; i >= 1; i--) {
            int x = (s[i] == '+' ? 1 : -1);
            maxRight[i] = max(0, x + maxRight[i + 1]);
            minRight[i] = min(0, x + minRight[i + 1]);
        }
        for (int i = 1; i <= q; i++) {
            int l, r;
            cin >> l >> r;
            int b = max(maxLeft[l - 1], sum[l - 1] + maxRight[r + 1]);
            int a = min(minLeft[l - 1], sum[l - 1] + minRight[r + 1]);
            cout << b - a + 1 << "\n";
        }
    }
    return 0;
}