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

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("papagali.out");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        bool bad = false;
        for (int i = 0; i < k; i++) {
            bool foundZero = false, foundOne = false;
            for (int j = i; j < n; j += k) {
                if (s[j] == '0') {
                    foundZero = true;
                }
                if (s[j] == '1') {
                    foundOne = true;
                }
            }
            if (foundZero && foundOne) {
                bad = true;
            }
            char ch = '?';
            if (foundZero) {
                ch = '0';
            }
            if (foundOne) {
                ch = '1';
            }
            for (int j = i; j < n; j += k) {
                s[j] = ch;
            }
        }
        int zeros = 0, ones = 0;
        for (int i = 0; i < k; i++) {
            if (s[i] == '0') {
                zeros++;
            }
            if (s[i] == '1') {
                ones++;
            }
        }
        if (ones > k / 2 || zeros > k / 2 || bad) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}