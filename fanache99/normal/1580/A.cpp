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

const int MAXN = 400;
const int INF = 1e9;

char a[1 + MAXN][1 + MAXN];
int sum[1 + MAXN][1 + MAXN];

int getFull(int r1, int c1, int r2, int c2) {
    return sum[r2][c2] - sum[r2][c1 - 1] - sum[r1 - 1][c2] + sum[r1 - 1][c1 - 1];
}

int getEmpty(int r1, int c1, int r2, int c2) {
    return (r2 - r1 + 1) * (c2 - c1 + 1) - getFull(r1, c1, r2, c2);
}

int main() {
    timeBegin();
    //  ifstream cin("input.txt");
//    ofstream cout("answer.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> (a[i] + 1);
            for (int j = 1; j <= m; j++) {
                sum[i][j] = (a[i][j] - '0') + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
            }
        }
        int ans = INF;
        for (int r1 = 1; r1 <= n; r1++) {
            for (int r2 = r1 + 4; r2 <= n; r2++) {
                int best = INF;
                for (int c = 4; c <= m; c++) {
                    best = min(best, getEmpty(r1 + 1, c - 3, r2 - 1, c - 3) +
                                     getEmpty(r1, c - 2, r1, c - 2) +
                                     getEmpty(r2, c - 2, r2, c - 2) +
                                     getFull(r1 + 1, c - 2, r2 - 1, c - 2));
                    best += (getEmpty(r1, c - 1, r1, c - 1) +
                             getEmpty(r2, c - 1, r2, c - 1) +
                             getFull(r1 + 1, c - 1, r2 - 1, c - 1));
                    ans = min(ans, best + getEmpty(r1 + 1, c, r2 - 1, c));
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}