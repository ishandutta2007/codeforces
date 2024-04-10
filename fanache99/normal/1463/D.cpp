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

const int MAXN = 200000;

int v[1 + MAXN], w[1 + MAXN];
bool in[1 + 2 * MAXN];

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
            in[v[i]] = true;
        }
        sort(v + 1, v + n + 1);
        for (int i = 1, j = 0; i <= 2 * n; i++) {
            if (!in[i]) {
                j++;
                w[j] = i;
            }
        }
        int left = 0, right = n, bestMin = 0, bestMax = 0;
        while (left <= right) {
            int middle = (left + right) / 2;
            bool bad = false;
            for (int i = middle; i >= 1; i--) {
                if (v[i] > w[i + n - middle]) {
                    bad = true;
                    break;
                }
            }
            if (!bad) {
                bestMin = middle;
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        left = 0;
        right = n;
        while (left <= right) {
            int middle = (left + right) / 2;
            bool bad = false;
            for (int i = n - middle + 1; i <= n; i++) {
                if (v[i] < w[i - n + middle]) {
                    bad = true;
                    break;
                }
            }
            if (!bad) {
                bestMax = middle;
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        cout << max(0, bestMin - (n - bestMax) + 1) << "\n";
        for (int i = 1; i <= 2 * n; i++) {
            in[i] = false;
        }
    }
    return 0;
}