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

const int MAXN = 400000;

struct Pair {
    int val;
    int cnt;

    bool operator < (const Pair &other) const {
        return cnt > other.cnt;
    }
};

Pair v[1 + MAXN];
int thisCnt[1 + MAXN];
long long sum[1 + MAXN];

void solve(int rows, int cols, int m) {
    if (rows > cols) {
        swap(rows, cols);
    }
    vector<vector<int>> ans(rows, vector<int>(cols, 0));
    sort(v + 1, v + m + 1);

    int r = rows - 1, c = cols - 1;
    for (int i = 1, j = 0; i <= rows * cols; i++) {
        r = (r + 1) % rows;
        c = (c + 1) % cols;
        if (ans[r][c] != 0) {
            assert(r == 0);
            int steps = 0;
            while (steps < rows && ans[r][c] != 0) {
                c = (c + 1) % cols;
                steps++;
            }
            assert(ans[r][c] == 0);
        }

        if (v[j].cnt == 0) {
            j++;
            v[j].cnt = min(v[j].cnt, rows);
        }
        ans[r][c] = v[j].val;
        v[j].cnt--;
    }

    cout << rows * cols << "\n" << rows << " " << cols << "\n";
    for (int i = 0; i < rows; i++, cout << "\n") {
        for (int j = 0; j < cols; j++) {
            cout << ans[i][j] << " ";
        }
    }
}

int main() {
    timeBegin();
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    map<int, int> f;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        f[x]++;
    }

    int m = 0;
    for (auto it : f) {
        v[++m] = {it.first, it.second};
        thisCnt[v[m].cnt]++;
    }

    for (int i = 1, add = m; i <= n; i++) {
        sum[i] = sum[i - 1] + add;
        add -= thisCnt[i];
    }

    long long best = 0;
    int rows, cols;
    for (int r = 1, c = n; r <= n && c > 0; r++) {
        while (c > 0 && sum[min(r, c)] < 1LL * r * c) {
            c--;
        }
        if (c > 0 && 1LL * r * c > best) {
            best = 1LL * r * c;
            rows = r;
            cols = c;
        }
    }
    assert(best > 0);

    solve(rows, cols, m);
    return 0;
}