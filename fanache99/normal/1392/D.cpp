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

const int MAXN = 200000;

char s[1 + MAXN];
int dp[1 + MAXN][2][2];

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("papagali.out");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n >> (s + 1);
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'L') {
                s[i] = 0;
            } else {
                s[i] = 1;
            }
        }
        int answer = n;
        for (int a = 0; a < 2; a++) {
            for (int b = 0; b < 2; b++) {
                for (int a0 = 0; a0 < 2; a0++) {
                    for (int b0 = 0; b0 < 2; b0++) {
                        dp[2][a0][b0] = n;
                    }
                }
                dp[2][a][b] = (s[1] != a) + (s[2] != b);
                for (int i = 3; i <= n; i++) {
                    for (int y = 0; y < 2; y++) {
                        for (int z = 0; z < 2; z++) {
                            dp[i][y][z] = n;
                            for (int x = 0; x < 2; x++) {
                                if (x + y + z != 0 && x + y + z != 3) {
                                    dp[i][y][z] = min(dp[i][y][z], dp[i - 1][x][y] + (s[i] != z));
                                }
                            }
                      }
                    }
                }
                for (int d = 0; d < 2; d++) {
                    if (a + b + d != 0 && a + b + d != 3) {
                        for (int c = 0; c < 2; c++) {
                            if (a + c + d != 0 && a + c + d != 3) {
                                answer = min(answer, dp[n][c][d]);
                            }
                        }
                    }
                }
            }
        }
        cout << answer << "\n";
    }
    //timeDuration();
    return 0;
}