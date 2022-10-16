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

const int MAXN = 1000;

int ans[1 + MAXN][1 + MAXN];
int cMax = 0;
int group[1 + MAXN];

void solve(int a, int b, int k, int c) {
    if (a == b) {
        return;
    }
    cMax = max(c, cMax);
    int n = b - a + 1;
    if (n <= k) {
        for (int i = a; i <= b; i++) {
            for (int j = i + 1; j <= b; j++) {
                ans[i][j] = c;
            }
        }
        return;
    }
    int d = n / k;
    for (int i = 0, x = a; i < k; i++) {
        int l = (i < n % k ? d + 1 : d);
        int y = x + l - 1;
        solve(x, y, k, c + 1);
        for (int j = x; j <= y; j++) {
            group[j] = i;
        }
        x = y + 1;
    }
    for (int i = a; i <= b; i++) {
        for (int j = i + 1; j <= b; j++) {
            if (group[i] != group[j]) {
                ans[i][j] = c;
            }
        }
    }
}

int main() {
    timeBegin();
   // ifstream cin("input.txt");
//    ofstream cout("answer.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, k;
    cin >> n >> k;
    vector<int> v;
    solve(1, n, k, 1);
    cout << cMax << "\n";
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cout << ans[i][j] << " ";
        }
    }
    cout << "\n";
    return 0;
}