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

using namespace std;

clock_t timeStart, timecinish;

void timeBegin() {
    timeStart = clock();
}

void timeEnd() {
    timecinish = clock();
}

void timeDuration() {
    timeEnd();
    double time_taken = double(timecinish - timeStart) / double(CLOCKS_PER_SEC);
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

const int MAXN = 50;

char s[1 + MAXN];

bool check(int n, char a, char b, char c) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'A') {
            if (a == '(') {
                sum++;
            } else {
                sum--;
            }
        }
        if (s[i] == 'B') {
            if (b == '(') {
                sum++;
            } else {
                sum--;
            }
        }
        if (s[i] == 'C') {
            if (c == '(') {
                sum++;
            } else {
                sum--;
            }
        }
        if (sum < 0) {
            return false;
        }
    }
    return (sum == 0);
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("greutati.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        cin >> (s + 1);
        int n = strlen(s + 1);
        if (check(n, '(', '(', '(') || check(n, '(', '(', ')') ||
            check(n, '(', ')', '(') || check(n, '(', ')', ')') ||
            check(n, ')', '(', '(') || check(n, ')', '(', ')') ||
            check(n, ')', ')', '(') || check(n, ')', ')', ')')) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    //timeDuration();
    return 0;
}