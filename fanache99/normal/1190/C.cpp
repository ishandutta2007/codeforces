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
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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

const int MAXN = 100000;

char s[1 + MAXN];
vector<int> v[2];
int toLeft[2][1 + MAXN + 1], toRight[2][1 + MAXN + 1];

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, k;
    cin >> n >> k >> (s + 1);
    for (int i = 1; i <= n; i++) {
        v[s[i] - '0'].push_back(i);
    }
    if (v[0].empty() || v[1].empty() || v[0].back() - v[0][0] < k || v[1].back() - v[1][0] < k) {
        cout << "tokitsukaze\n";
    } else {
        toLeft[0][0] = toLeft[1][0] = 0;
        for (int i = 1; i <= n; i++) {
            toLeft[0][i] = toLeft[0][i - 1];
            toLeft[1][i] = toLeft[1][i - 1];
            toLeft[s[i] - '0'][i] = i;
        }
        toRight[0][n + 1] = toRight[1][n + 1] = n + 1;
        for (int i = n; i >= 1; i--) {
            toRight[0][i] = toRight[0][i + 1];
            toRight[1][i] = toRight[1][i + 1];
            toRight[s[i] - '0'][i] = i;
        }
        bool found = false;
        for (int i = 1; i + k - 1 <= n && !found; i++) {
            for (int j = 0; j < 2; j++) {
                int a0 = (toRight[j][1] < i ? toRight[j][1] : i);
                int b0 = (toLeft[j][n] > i + k - 1 ? toLeft[j][n] : i + k - 1);
                int a1 = (toRight[j ^ 1][1] < i ? toRight[j ^ 1][1] : toRight[j ^ 1][i + k]);
                int b1 = (toLeft[j ^ 1][n] > i + k - 1 ? toLeft[j ^ 1][n] : toLeft[j ^ 1][i - 1]);
                assert(a0 >= 1 && a0 <= n && b0 >= 1 && b0 <= n && a0 <= b0);
                assert(a1 >= 1 && a1 <= n && b1 >= 1 && b1 <= n && a1 <= b1);
                if (b0 - a0 >= k && b1 - a1 >= k) {
                    found = true;
                    break;
                }
            }
        }
        if (!found) {
            cout << "quailty\n";
        } else {
            cout << "once again\n";
        }
    }
    return 0;
}