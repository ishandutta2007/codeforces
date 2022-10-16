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

const int MAXN = 5000;

char s[1 + MAXN];
int dx[255], dy[255];

void initialize() {
    dx['L'] = -1;
    dx['R'] = 1;
    dy['D'] = -1;
    dy['U'] = 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //ifstream cin("input.txt");
    initialize();
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        cin >> (s + 1);
        int n = strlen(s + 1);
        int x = 0, y = 0;
        vector<pair<int, int> > v;
        for (int i = 1; i <= n; i++) {
            x += dx[s[i]];
            y += dy[s[i]];
            v.push_back(make_pair(x, y));
        }
        bool found = false;
        for (auto it : v) {
            int x0 = it.first, y0 = it.second;
            if (x0 == 0 && y0 == 0) {
                continue;
            }
            x = y = 0;
            for (int i = 1; i <= n; i++) {
                x += dx[s[i]];
                y += dy[s[i]];
                if (x == x0 && y == y0) {
                    x -= dx[s[i]];
                    y -= dy[s[i]];
                }
            }
            if (x == 0 && y == 0) {
                found = true;
                cout << x0 << " " << y0 << "\n";
                break;
            }
        }
        if (!found) {
            cout << "0 0\n";
        }
    }
    return 0;
}