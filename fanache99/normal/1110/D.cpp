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

const int MAXM = 1000000;
const int INF = 1000000000;

int f[1 + MAXM];
int dp[1 + MAXM][3][3];

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("abbreviation.out");
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        f[x]++;
    }
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            dp[0][a][b] = -INF;
        }
    }
    dp[0][0][0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int b = 0; b < 3; b++) {
            for (int c = 0; c < 3; c++) {
                dp[i][b][c] = -INF;
                for (int a = 0; a < 3; a++) {
                    if (a + b + c <= f[i] && dp[i - 1][a][b] >= 0) {
                        int x = f[i] - a - b - c;
                        dp[i][b][c] = max(dp[i][b][c], dp[i - 1][a][b] + x / 3 + c);
                    }
                }
            }
        }
    }
    cout << dp[m][0][0] << "\n";
    //timeDuration();
    return 0;
}