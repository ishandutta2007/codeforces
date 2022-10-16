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

const int MAXN = 200;

struct V {
    int x, y;
};

V v[1 + MAXN];

int abs(int x) {
    if (x >= 0) {
        return x;
    } else {
        return -x;
    }
}

bool close(V a, V b, int k) {
    return abs(a.x - b.x) + abs(a.y - b.y) <= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //ifstream cin("input.txt");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> v[i].x >> v[i].y;
        }
        bool found = false;
        for (int i = 1; i <= n; i++) {
            bool bad = false;
            for (int j = 1; j <= n; j++) {
                if (!close(v[i], v[j], k)) {
                    bad = true;
                    break;
                }
            }
            if (!bad) {
                found = true;
                break;
            }
        }
        if (found) {
            cout << "1\n";
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}