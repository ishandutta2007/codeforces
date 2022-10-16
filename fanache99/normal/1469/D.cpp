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

int v[1 + MAXN];
vector<pair<int, int> > sol;

int dv(int x, int y) {
    return (x - 1) / y + 1;
}

void op(int x, int y, int n) {
    assert(x != y && x >= 1 && x <= n && y >= 1 && y <= n);
    v[x] = dv(v[x], v[y]);
    sol.push_back(make_pair(x, y));
}

bool check(int n) {
    bool found2 = false;
    for (int i = 1; i <= n; i++) {
        if (v[i] < 1 || v[i] > 2) {
            return false;
        }
        if (v[i] == 2) {
            if (!found2) {
                found2 = true;
            } else {
                return false;
            }
        }
    }
    return found2 && sol.size() <= n + 5;
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
        for (int i = 1; i <= n; i++) {
            v[i] = i;
        }
        sol.clear();
        int p = n;
        while (p != 2) {
            int i = p - 1;
            while (dv(p, i) <= i) {
                i--;
            }
            i++;
            for (int j = p - 1; j > i; j--) {
                op(j, p, n);
            }
            op(p, i, n);
            op(p, i, n);
            p = i;
        }
        assert(check(n));
        cout << sol.size() << "\n";
        for (auto it : sol) {
            cout << it.first << " " << it.second << "\n";
        }
    }
    return 0;
}