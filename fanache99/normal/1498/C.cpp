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

const int MOD = 1000000007;
const int MAXN = 1000;
const int MAXK = 1000;

int dp[1 + MAXK][1 + MAXN], sum[1 + MAXK][1 + MAXN];

void addTo(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

void subtractFrom(int &x, int y) {
    x -= y;
    if (x < 0) {
        x += MOD;
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream fout("input.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, k;
        cin >> n >> k;
        for (int j = 0; j <= n; j++) {
            dp[1][j] = 1;
            sum[1][j] = j + 1;
        }
        for (int i = 2; i <= k; i++) {
            dp[i][0] = sum[i][0] = 1;
            for (int j = 1; j <= n; j++) {
                dp[i][j] = 1;
                addTo(dp[i][j], sum[i - 1][n - 1]);
                if (j != n) {
                    subtractFrom(dp[i][j], sum[i - 1][n - j - 1]);
                }
                sum[i][j] = sum[i][j - 1];
                addTo(sum[i][j], dp[i][j]);
            }
        }
        cout << dp[k][n] << "\n";
    }
    //timeDuration();
    return 0;
}