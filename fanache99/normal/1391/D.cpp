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

const int MAXN = 3;
const int MAXM = 1000000;

int dp[MAXM][1 << MAXN];

bool ok(int i0, int i1, int n) {
    if (n >= 2) {
        int temp = ((i0 >> 0) & 1) + ((i0 >> 1) & 1) + ((i1 >> 0) & 1) + ((i1 >> 1) & 1);
        if (temp % 2 == 0) {
            return false;
        }
    }
    if (n >= 3) {
        int temp = ((i0 >> 1) & 1) + ((i0 >> 2) & 1) + ((i1 >> 1) & 1) + ((i1 >> 2) & 1);
        if (temp % 2 == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("papagali.out");
    int n, m;
    cin >> n >> m;
    if (n >= 4 && m >= 4) {
        cout << "-1\n";
        return 0;
    }
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            a[i][j] -= '0';
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        dp[0][i] = 0;
        for (int j = 0; j < n; j++) {
            if (a[j][0] != ((i >> j) & 1)) {
                dp[0][i]++;
            }
        }
    }
    for (int k = 1; k < m; k++) {
        for (int i1 = 0; i1 < (1 << n); i1++) {
            dp[k][i1] = 2 * n * m;
            for (int i0 = 0; i0 < (1 << n); i0++) {
                if (ok(i0, i1, n)) {
                    int current = dp[k - 1][i0];
                    for (int j = 0; j < n; j++) {
                        if (a[j][k] != ((i1 >> j) & 1)) {
                            current++;
                        }
                    }
                    dp[k][i1] = min(dp[k][i1], current);
                }
            }
        }
    }
    int answer = 2 * n * m;
    for (int i = 0; i < (1 << n); i++) {
        answer = min(answer, dp[m - 1][i]);
    }
    cout << answer << "\n";
    //timeDuration();
    return 0;
}