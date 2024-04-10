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

const int MAXN = 25;

long long comb[1 + 2 * MAXN][1 + 2 * MAXN], a[1 + MAXN][1 + MAXN];

void solve(int n, long long x) {
    long long sum = 0, cx = x;
    int r = 1, c = 1;
    cout << r << " " << c << "\n";
    for (int i = 1; i <= 2 * n - 2; i++) {
        if (r < n && x < comb[(n - r) + (n - c) - 1][n - r - 1]) {
            r++;
        } else {
            x -= comb[(n - r) + (n - c) - 1][n - r - 1];
            c++;
        }
        cout << r << " " << c << "\n";
        sum += a[r][c];
    }
    assert(sum == cx);
    cout.flush();
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("papagali.out");
    int n;
    cin >> n;
    comb[0][0] = 1;
    for (int i = 1; i <= 2 * n - 1; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        a[i][1] = a[n][i] = 0;
    }
    for (int i = n - 1; i >= 1; i--) {
        long long sum = 0, minusBase = 0;
        for (int c = 1; c <= n; c++) {
            sum += a[i + 1][c];
        }
        for (int r = i + 2; r <= n; r++) {
            sum += a[r][n];
        }
        for (int j = 2; j <= n; j++) {
            sum -= a[i + 1][j - 2];
            sum += a[i][j - 1];
            minusBase += a[i][j - 1];
            long long minus = minusBase;
            for (int r = i + 1; r <= n; r++) {
                minus += a[r][j];
            }
            a[i][j] = sum + 1 - minus;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout.flush();
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        long long x;
        cin >> x;
        solve(n, x);
    }
    //timeDuration();
    return 0;
}