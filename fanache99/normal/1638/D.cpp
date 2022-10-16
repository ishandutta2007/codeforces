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
#include <bitset>
#include <unordered_map>
#include <complex>
#include <unordered_set>
#include <chrono>
#include <random>

using namespace std;

clock_t timeStart, timeFinish;

void timeBegin() {
    timeStart = clock();
}

void timeEnd() {
    timeFinish = clock();
}

void timeDuration() {
    timeEnd();
    double time_taken = double(timeFinish - timeStart) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;
}

class InputReader {
public:
    InputReader() {
        input_file = stdin;
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }

    InputReader(const char *file_name) {
        input_file = fopen(file_name, "r");
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }

    template<typename T>
    inline InputReader &operator>>(T &n) {
        while ((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while ('0' <= buffer[cursor] && buffer[cursor] <= '9') {
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
        ++cursor;
        if (cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int MAXN = 1000;
const int MAXM = 1000;

int c[1 + MAXN][1 + MAXN], d[1 + MAXN][1 + MAXM], cp[1 + MAXN][1 + MAXM];

struct Op {
    int x;
    int y;
    int c;
};

int ok(int i, int j, int n, int m) {
    if (i <= 0 || j <= 0 || i >= n || j >= m) {
        return 0;
    }
    vector<int> v = {c[i][j], c[i + 1][j], c[i][j + 1], c[i + 1][j + 1]};
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    if (v.back() != 0 && (v.size() == 1 || (v.size() == 2 && v[0] == 0))) {
        return v.back();
    } else {
        return 0;
    }
}

void check(vector<Op> &sol, int n, int m) {
    assert(sol.size() <= n * m);
    for (auto it : sol) {
        auto [i, j, col] = it;
        assert(i >= 1 && i < n && j >= 1 && j < m);
        d[i][j] = d[i + 1][j] = d[i][j + 1] = d[i + 1][j + 1] = col;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            assert(cp[i][j] == d[i][j]);
        }
    }
}

int main() {
    timeBegin();
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
            cp[i][j] = c[i][j];
        }
    }
    vector<Op> sol;
    queue<Op> q;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int col = ok(i, j, n, m);
            if (col != 0) {
                q.push({i, j, col});
            }
        }
    }
    while (!q.empty()) {
        int i = q.front().x, j = q.front().y, col = q.front().c;
        q.pop();
        if (c[i][j] == 0 && c[i + 1][j] == 0 && c[i][j + 1] == 0 && c[i + 1][j + 1] == 0) {
            continue;
        }
        sol.push_back({i, j, col});
        c[i][j] = c[i + 1][j] = c[i][j + 1] = c[i + 1][j + 1] = 0;
        for (int i0 = i - 1; i0 <= i + 1; i0++) {
            for (int j0 = j - 1; j0 <= j + 1; j0++) {
                int col0 = ok(i0, j0, n, m);
                if (col0 != 0) {
                    q.push({i0, j0, col0});
                }
            }
        }
    }
    reverse(sol.begin(), sol.end());

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (c[i][j] != 0) {
                cout << "-1\n";
                exit(0);
            }
        }
    }
    check(sol, n, m);
    cout << sol.size() << "\n";
    for (auto it : sol) {
        cout << it.x << " " << it.y << " " << it.c << "\n";
    }
    return 0;
}