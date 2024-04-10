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

int x[1 + MAXN][1 + MAXN];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void mark(int n, int x, int y, vector<vector<int>> &s) {
    for (int i = 0; i < 4; i++) {
        int x0 = x + dx[i], y0 = y + dy[i];
        if (x0 >= 1 && x0 <= n && y0 >= 1 && y0 <= n) {
            s[x0][y0] ^= 1;
        }
    }
}

void print(vector<vector<int>> &s, int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << s[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

vector<vector<int>> attempt(int n) {
    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> ans(n + 1, vector<int>(n + 1, 0));
    for (int j = 1; j <= n; j++) {
        mark(n, 1, j,  s);
        ans[1][j] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1][j] == 0) {
                mark(n, i, j, s);
                ans[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            assert(s[i][j] == 1);
        }
    }
    return ans;
}

int main() {
    timeBegin();
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> x[i][j];
            }
        }
        vector<vector<int> > ans = attempt(n);
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (ans[i][j]) {
                    sum ^= x[i][j];
                }
            }
        }
        cout << sum << "\n";
    }
    return 0;
}