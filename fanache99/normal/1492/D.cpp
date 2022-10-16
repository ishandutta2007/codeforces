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

const int MAXN = 200000;

char x[1 + MAXN + 1], y[1 + MAXN + 1];
int z[1 + MAXN];

void noSol() {
    cout << "No\n";
    exit(0);
}

void check(int n, int a, int b, int k) {
    int zx = 0, zy = 0, ox = 0, oy = 0;
    bool bigger = false;
    assert(x[1] == '1' && y[1] == '1');
    for (int i = 1; i <= n; i++) {
        if (x[i] == '0') {
            zx++;
        } else {
            ox++;
        }
        if (y[i] == '0') {
            zy++;
        } else {
            oy++;
        }
        if (!bigger) {
            assert(y[i] <= x[i]);
            if (y[i] < x[i]) {
                bigger = true;
            }
        }
    }
    int oz = 0;
    for (int i = n, r = 0; i >= 1; i--) {
        z[i] = x[i] - y[i] - r;
        if (z[i] < 0) {
            r = 1;
            z[i] += 2;
        } else {
            r = 0;
        }
        if (z[i] == 1) {
            oz++;
        }
    }
    assert(zx == a && ox == b && zy == a && oy == b && oz == k);
}

void print(int n, int a, int b, int k) {
    check(n, a, b, k);
    x[n + 1] = y[n + 1] = 0;
    cout << "Yes\n" << (x + 1) << "\n" << (y + 1) << "\n";
    exit(0);
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("greutati.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b, k;
    cin >> a >> b >> k;
    int ca = a, cb = b, ck = k;
    int n = a + b;
    x[1] = y[1] = '1';
    b--;
    if (k == 0) {
        for (int i = 2; i <= b + 1; i++) {
            x[i] = y[i] = '1';
        }
        for (int i = b + 2; i <= n; i++) {
            x[i] = y[i] = '0';
        }
        print(n, ca, cb, ck);
    } else if (a == 0 || b == 0 || k >= n - 1) {
        noSol();
    } else {
        x[n] = '0';
        y[n] = '1';
        a--;
        b--;
        for (int i = n - 1; i >= n - k + 1; i--) {
            if (a != 0) {
                x[i] = y[i] = '0';
                a--;
            } else {
                x[i] = y[i] = '1';
                b--;
            }
        }
        x[n - k] = '1';
        y[n - k] = '0';
        for (int i = n - k - 1; i >= 2; i--) {
            if (a != 0) {
                x[i] = y[i] = '0';
                a--;
            } else {
                x[i] = y[i] = '1';
                b--;
            }
        }
        print(n, ca, cb, ck);
    }
    //timeDuration();
    return 0;
}