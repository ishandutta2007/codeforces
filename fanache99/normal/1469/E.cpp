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

const int MAXN = 1000000;
const int MAXLOG = 20;

char s[1 + MAXN], sol[1 + MAXN + 1];
int pi[1 + MAXN];
unsigned int sum[1 + MAXN];
bool seen[MAXN];

bool check(int n, int k) {
    for (int i = 0; i < (1 << k); i++) {
        seen[i] = false;
    }
    for (int i = k; i <= n; i++) {
        seen[sum[i] - sum[i - k] * (1 << k)] = true;
    }
    for (int i = 0; i < (1 << k); i++) {
        if (!seen[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //ifstream cin("input.txt");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, k;
        cin >> n >> k >> (s + 1);
        for (int i = 1; i <= n; i++) {
            sum[i] = 2 * sum[i - 1] + s[i] - '0';
        }
        if (k <= MAXLOG && (1 << k) <= n - k + 1) {
            if (!check(n, k)) {
                cout << "NO\n";
                continue;
            }
        }
        int p = 1;
        pi[0] = 0;
        while (k - p > MAXLOG || (1 << (k - p)) > n - k + 1) {
            sol[p] = '0';
            pi[p] = p - 1;
            p++;
        }
        while (p <= k) {
            sol[p] = '0';
            pi[p] = pi[p - 1];
            while (pi[p] > 0 && sol[pi[p] + 1] != sol[p]) {
                pi[p] = pi[pi[p]];
            }
            if (p != 1 && sol[pi[p] + 1] == sol[p]) {
                pi[p]++;
            }
            int m = k - p;
            for (int i = 0; i < (1 << m); i++) {
                seen[i] = false;
            }
            for (int j = 1, i = 0; j <= n; j++) {
                while (i > 0 && sol[i + 1] == s[j]) {
                    i = pi[i];
                }
                if (sol[i + 1] != s[j]) {
                    i++;
                }
                if (i == p) {
                    i = pi[i];
                    if (j + m <= n) {
                        seen[sum[j + m] - sum[j] * (1 << m)] = true;
                    }
                }
            }
            bool found = false;
            for (int i = 0; i < (1 << m); i++) {
                if (!seen[i]) {
                    found = true;
                }
            }
            if (!found) {
                sol[p] = '1';
                pi[p] = pi[p - 1];
                while (pi[p] > 0 && sol[pi[p] + 1] != sol[p]) {
                    pi[p] = pi[pi[p]];
                }
                if (p != 1 && sol[pi[p] + 1] == sol[p]) {
                    pi[p]++;
                }
            }
            p++;
        }
        sol[k + 1] = NULL;
        cout << "YES\n" << (sol + 1) << "\n";
    }
    return 0;
}