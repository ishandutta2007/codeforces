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
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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

    inline InputReader &operator>>(int &n) {
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

const int MAXN = 2000;
const int MOD = 1000000007;

char a[1 + MAXN][1 + MAXN];
int dpDown[1 + MAXN][1 + MAXN], dpRight[1 + MAXN][1 + MAXN];
int sumDown[1 + MAXN + 1][1 + MAXN + 1], sumRight[1 + MAXN + 1][1 + MAXN + 1];
int toDown[1 + MAXN + 1][1 + MAXN + 1], toRight[1 + MAXN + 1][1 + MAXN + 1];

void add(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

void sub(int &x, int y) {
    x -= y;
    if (x < 0) {
        x += MOD;
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> (a[i] + 1);
    }
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            toDown[i][j] = toDown[i + 1][j];
            toRight[i][j] = toRight[i][j + 1];
            if (a[i][j] == 'R') {
                toDown[i][j]++;
                toRight[i][j]++;
            }
        }
    }
    if (n == 1 && m == 1) {
        cout << "1\n";
    } else if (a[n][m] == 'R') {
        cout << "0\n";
    } else {
        dpDown[n][m] = dpRight[n][m] = sumDown[n][m] = sumRight[n][m] = 1;
        for (int i = n - 1; i >= 1 && a[i][m] == '.'; i--) {
            dpDown[i][m] = sumDown[i][m] = 1;
            dpRight[i][m] = sumRight[i][m] = 0;
        }
        for (int j = m - 1; j >= 1 && a[n][j] == '.'; j--) {
            dpRight[n][j] = sumRight[n][j] = 1;
            dpDown[n][j] = sumDown[n][j] = 0;
        }
        for (int i = n - 1; i >= 1; i--) {
            for (int j = m - 1; j >= 1; j--) {
                int x = toDown[i + 1][j];
                add(dpDown[i][j], sumRight[i + 1][j]);
                sub(dpDown[i][j], sumRight[n - x + 1][j]);
                int y = toRight[i][j + 1];
                add(dpRight[i][j], sumDown[i][j + 1]);
                sub(dpRight[i][j], sumDown[i][m - y + 1]);
                sumDown[i][j] = sumDown[i][j + 1];
                add(sumDown[i][j], dpDown[i][j]);
                sumRight[i][j] = sumRight[i + 1][j];
                add(sumRight[i][j], dpRight[i][j]);
            }
        }
        int answer = 0;
        add(answer, dpDown[1][1]);
        add(answer, dpRight[1][1]);
        cout << answer << "\n";
    }
    return 0;
}