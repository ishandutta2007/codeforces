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

const int MAXN = 5000;

char s[1 + MAXN], t[1 + MAXN];

bool start(int st, int n) {
    for (int j = st, i = 1; i <= n; j = (j == n ? 1 : j + 1), i++) {
        t[i] = s[j];
    }
    bool found = false;
    for (int i = 1; i <= n; i++) {
        if (s[i] != t[i]) {
            found = true;
        }
    }
    if (!found) {
        return false;
    }
    for (int i = 1; i < n - i + 1; i++) {
        if (t[i] != t[n - i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    cin >> (s + 1);
    int n = strlen(s + 1);
    bool found = false;
    for (int i = 2; i <= n; i++) {
        if (2 * i - 1 != n && s[i] != s[1]) {
            found = true;
        }
    }
    if (!found) {
        cout << "Impossible\n";
    } else {
        for (int i = 1; i <= n; i++) {
            if (start(i, n)) {
                cout << "1\n";
                return 0;
            }
        }
        cout << "2\n";
    }
    return 0;
}