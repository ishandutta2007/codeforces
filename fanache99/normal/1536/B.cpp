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
#include <unordered_map>
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

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        string s;
        cin >> n >> s;
        bool found = false;
        for (char c1 = 'a'; c1 <= 'z' && !found; c1++) {
            bool bad = false;
            for (int i = 0; i < n; i++) {
                if (s[i] == c1) {
                    bad = true;
                }
            }
            if (!bad) {
                found = true;
                cout << c1 << "\n";
            }
        }
        for (char c1 = 'a'; c1 <= 'z' && !found; c1++) {
            for (char c2 = 'a'; c2 <= 'z' && !found; c2++) {
                bool bad = false;
                for (int i = 0; i < n - 1; i++) {
                    if (s[i] == c1 && s[i + 1] == c2) {
                        bad = true;
                    }
                }
                if (!bad) {
                    found = true;
                    cout << c1 << c2 << "\n";
                }
            }
        }
        for (char c1 = 'a'; c1 <= 'z' && !found; c1++) {
            for (char c2 = 'a'; c2 <= 'z' && !found; c2++) {
                for (char c3 = 'a'; c3 <= 'z' && !found; c3++) {
                    bool bad = false;
                    for (int i = 0; i < n - 2; i++) {
                        if (s[i] == c1 && s[i + 1] == c2 && s[i + 2] == c3) {
                            bad = true;
                        }
                    }
                    if (!bad) {
                        found = true;
                        cout << c1 << c2 << c3 << "\n";
                    }
                }
            }
        }
    }
    return 0;
}