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

int go[10] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

bool ok(int a, int b, int h, int m) {
    int a1 = a / 10, a2 = a % 10, b1 = b / 10, b2 = b % 10;
    if (go[a1] == -1 || go[a2] == -1 || go[b1] == -1 || go[b2] == -1) {
        return false;
    }
    int c = go[b2] * 10 + go[b1], d = go[a2] * 10 + go[a1];
    return c < h && d < m;
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
        int h, m;
        cin >> h >> m;
        char a1, a2, c, b1, b2;
        cin >> a1 >> a2 >> c >> b1 >> b2;
        int a = (a1 - '0') * 10 + a2 - '0';
        int b = (b1 - '0') * 10 + b2 - '0';
        while (!ok(a, b, h, m)) {
            b++;
            if (b == m) {
                b = 0;
                a++;
                if (a == h) {
                    a = 0;
                }
            }
        }
        if (a < 10) {
            cout << "0";
        }
        cout << a << ":";
        if (b < 10) {
            cout << "0";
        }
        cout << b << "\n";
    }
    //timeDuration();
    return 0;
}