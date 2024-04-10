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

const int MAXN = 2000;
const int INF = 1000000;
const int SIGMA = 26;

char a[1 + MAXN], b[1 + MAXN];
int ca[SIGMA], cb[SIGMA], dp[1 + MAXN + 1], newDp[1 + MAXN + 1];
vector<int> where[SIGMA];

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.txt");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n >> (a + 1) >> (b + 1);
        for (int i = 0; i < SIGMA; i++) {
            ca[i] = cb[i] = 0;
            where[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            ca[a[i] - 'a']++;
            cb[b[i] - 'a']++;
            where[a[i]-'a'].emplace_back(i);
        }
        bool bad = false;
        for (int i = 0; i < SIGMA; i++) {
            if (ca[i] != cb[i]) {
                bad = true;
            }
        }
        if (bad) {
            cout << "-1\n";
        } else {
            for (int i = 1; i <= n; i++) {
                dp[i] = INF;
            }
            dp[n + 1] = 0;
            for (int i = n; i >= 1; i--) {
                int ch = b[i] - 'a';
                for (int j = 1; j <= n + 1; j++) {
                    newDp[j] = INF;
                }
                int best = INF;
                for (int j = n + 1; j >= 1; j--) {
                    if (j <= where[ch][ca[ch] - 1] && a[j] == ch + 'a') {
                        newDp[j] = min(newDp[j], best);
                    }
                    best = min(best, dp[j]);
                }
                for (int j = where[ch][ca[ch] - 1] - 1; j >= 1; j--) {
                    newDp[j] = min(newDp[j], dp[j] + 1);
                }
                for (int j = 1; j <= n + 1; j++) {
                    dp[j] = newDp[j];
                }
                ca[ch]--;
            }
            cout << dp[1] << "\n";
        }
    }
    //timeDuration();
    return 0;
}