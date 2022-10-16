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

const int MAXN = 500000;

char s[1 + MAXN], t[1 + MAXN], suf[1 + MAXN];
int fs[2], ft[2], fsuf[2], pi[1 + MAXN];

void getPi(char s[], int n) {
    pi[1] = 0;
    for (int j = 2, i = 0; j <= n; j++) {
        while (i > 0 && s[i + 1] != s[j]) {
            i = pi[i];
        }
        if (s[i + 1] == s[j]) {
            i++;
        }
        pi[j] = i;
    }
}

void dump() {
    string s;
    for (int j = 0; j < 2; j++) {
        for (int i = 1; i <= fs[j]; i++) {
            s.push_back('0' + j);
        }
    }
    cout << s;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    cin >> (s + 1) >> (t + 1);
    int n = strlen(s + 1), m = strlen(t + 1);
    for (int i = 1; i <= n; i++) {
        fs[s[i] - '0']++;
    }
    for (int i = 1; i <= m; i++) {
        ft[t[i] - '0']++;
    }
    getPi(t, m);
    if (fs[0] < ft[0] || fs[1] < ft[1]) {
        dump();
    } else {
        cout << (t + 1);
        fs[0] -= ft[0];
        fs[1] -= ft[1];
        int k = m - pi[m];
        for (int i = pi[m] + 1; i <= m; i++) {
            suf[i - pi[m]] = t[i];
            fsuf[t[i] - '0']++;
        }
        while (fs[0] >= fsuf[0] && fs[1] >= fsuf[1]) {
            cout << (suf + 1);
            fs[0] -= fsuf[0];
            fs[1] -= fsuf[1];
        }
        dump();
    }
    return 0;
}