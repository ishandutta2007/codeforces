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

const int MAXVAL = 1000000;

int low[1 + MAXVAL];

void precompute() {
    for (int i = 2; i <= MAXVAL; i++) {
        if (!low[i]) {
            low[i] = i;
            for (int j = 2 * i; j <= MAXVAL; j += i) {
                if (!low[j]) {
                    low[j] = i;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //ifstream cin("input.txt");
    int tests;
    cin >> tests;
    precompute();
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        map<int, int> seen;
        for (int i = 1; i <= n; i++) {
            int x, y = 1;
            cin >> x;
            while (x != 1) {
                int z = low[x], p = 0;
                while (x % z == 0) {
                    x /= z;
                    p++;
                }
                if (p % 2 == 1) {
                    y *= z;
                }
            }
            seen[y]++;
        }
        int biggest = 0, odd = 0, even = 0;
        for (auto it : seen) {
            biggest = max(biggest, it.second);
            if (it.second % 2 == 0 || it.first == 1) {
                even += it.second;
            } else {
                odd = max(odd, it.second);
            }
        }
        int q;
        cin >> q;
        for (int i = 1; i <= q; i++) {
            long long t;
            cin >> t;
            if (t == 0) {
                cout << biggest << "\n";
            } else {
                cout << max(odd, even) << "\n";
            }
        }
    }
    return 0;
}