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

int abs(int x) {
    return x > 0 ? x : -x;
}

int gcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //ifstream cin("input.txt");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        map<pair<int, int>, pair<int, int> > m;
        for (int i = 1; i <= n; i++) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            int dx = x2 - x1, dy = y2 - y1;
            int d = gcd(abs(dx), abs(dy));
            dx /= d;
            dy /= d;
            int adx = abs(dx), ady = abs(dy);
            if (dx == 0) {
                if (dy > 0) {
                    m[make_pair(adx, ady)].first++;
                } else {
                    m[make_pair(adx, ady)].second++;
                }
            } else if (dy == 0) {
                if (dx > 0) {
                    m[make_pair(adx, ady)].first++;
                } else {
                    m[make_pair(adx, ady)].second++;
                }
            } else {
                if (dx > 0 && dy > 0) {
                    m[make_pair(adx, ady)].first++;
                } else if (dx < 0 && dy < 0) {
                    m[make_pair(adx, ady)].second++;
                } else if (dx > 0 && dy < 0) {
                    m[make_pair(-adx, ady)].first++;
                } else {
                    m[make_pair(-adx, ady)].second++;
                }
            }
        }
        long long answer = 0;
        for (auto it : m) {
            answer += 1LL * it.second.first * it.second.second;
        }
        cout << answer << "\n";
    }
    return 0;
}