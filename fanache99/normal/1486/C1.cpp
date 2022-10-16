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

int ask(int a, int b) {
    if (a == b) {
        return 0;
    }
    cout << "? " << a << " " << b << "\n";
    cout.flush();
    int x;
    cin >> x;
    return x;
}

void answer(int x) {
    cout << "! " << x << "\n";
    cout.flush();
    exit(0);
}

const int MAXLOG = 20;

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("greutati.out");
    int n;
    cin >> n;
    int x = ask(1, n);
    if (x > 1 && ask(1, x) == x) {
        int y = 0;
        for (int bit = MAXLOG; bit >= 0; bit--) {
            if (x - y - (1 << bit) > 0) {
                int z = ask(x - y - (1 << bit), x);
                if (z != x) {
                    y += 1 << bit;
                }
            }
        }
        answer(x - y - 1);
    } else {
        int y = 0;
        for (int bit = MAXLOG; bit >= 0; bit--) {
            if (x + y + (1 << bit) <= n) {
                int z = ask(x, x + y + (1 << bit));
                if (z != x) {
                    y += 1 << bit;
                }
            }
        }
        answer(x + y + 1);
    }
    //timeDuration();
    return 0;
}