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

const int MAXR = 500;
const int MAXN = 100000;

int x[1 + MAXN], y[1 + MAXN], t[1 + MAXN], dp[1 + MAXN];

int abs(int x) {
    if (x > 0) {
        return x;
    } else {
        return -x;
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("papagali.out");
    int r, n;
    cin >> r >> n;
    int answer = 0;
    x[0] = y[0] = 1;
    for (int i = 1, j = 1, best = 0; i <= n; i++) {
        cin >> t[i] >> x[i] >> y[i];
        while (j < i && t[i] - t[j] >= 2 * (r - 1))  {
            best = max(best, dp[j]);
            j++;
        }
        if (t[i] < abs(x[i] - 1) + abs(y[i] - 1)) {
            dp[i] = -1;
        } else {
            dp[i] = best + 1;
            for (int k = j; k < i; k++) {
                if (dp[k] != -1 && t[i] - t[k] >= abs(x[i] - x[k]) + abs(y[i] - y[k])) {
                    dp[i] = max(dp[i], dp[k] + 1);
                }
            }
            answer = max(answer, dp[i]);
        }
    }
    cout << answer << "\n";
    return 0;
}