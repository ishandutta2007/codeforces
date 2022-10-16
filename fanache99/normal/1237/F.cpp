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

const int MAXN = 3600;
const int MOD = 998244353;

bool row[1 + MAXN], column[1 + MAXN];
int row2[1 + MAXN][1 + MAXN], column2[1 + MAXN][1 + MAXN];
int comb[1 + MAXN][1 + MAXN], factorial[1 + MAXN];

void addTo(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

void precompute() {
    comb[0][0] = 1;
    factorial[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        comb[i][0] = 1;
        factorial[i] = 1LL * factorial[i - 1] * i % MOD;
        for (int j = 1; j <= i; j++) {
            comb[i][j] = comb[i - 1][j];
            addTo(comb[i][j], comb[i - 1][j - 1]);
        }
    }
}

void get2(int n, bool out[], int ways2[1 + MAXN][1 + MAXN], int &total) {
    ways2[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        if (!out[i]) {
            total++;
        }
        for (int j = 0; j <= n; j++) {
            ways2[i][j] = ways2[i - 1][j];
            if (i > 1 && !out[i] && !out[i - 1]) {
                addTo(ways2[i][j], ways2[i - 2][j - 1]);
            }
        }
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("abbreviation.out");
    int h, w, n;
    cin >> h >> w >> n;
    for (int i = 1; i <= n; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        row[r1] = row[r2] = true;
        column[c1] = column[c2] = true;
    }
    int rows = 0, columns = 0;
    precompute();
    get2(h, row, row2, rows);
    get2(w, column, column2, columns);
    int answer = 0;
    for (int r = 0; r <= h; r++) {
        for (int c = 0; c <= w; c++) {
            if (2 * r + c <= rows && r + 2 * c <= columns) {
                int current = row2[h][r];
                current = 1LL * current * comb[rows - 2 * r][c] % MOD;
                current = 1LL * current * column2[w][c] % MOD;
                current = 1LL * current * comb[columns - 2 * c][r] % MOD;
                current = 1LL * current * factorial[r] % MOD;
                current = 1LL * current * factorial[c] % MOD;
                addTo(answer, current);
            }
        }
    }
    cout << answer << "\n";
    //timeDuration();
    return 0;
}