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

const int MAXN = 300000;

int p[1 + MAXN], w[1 + MAXN], q[1 + MAXN];
vector<pair<int, int> > sol;

int myAbs(int x) {
    return (x < 0 ? -x : x);
}

void doOp(int a, int b, int n) {
    assert(myAbs(a - b) >= n / 2);
    sol.push_back({a, b});
}

void doSwap(int a, int b, int n) {
    if (a > b) {
        swap(a, b);
    }
    if ((b - a) >= n / 2) {
        doOp(a, b, n);
    } else if (n - a >= n / 2 && n - b >= n / 2) {
        doOp(a, n, n);
        doOp(b, n, n);
        doOp(a, n, n);
    } else if (a - 1 >= n / 2 && b - 1 >= n / 2) {
        doOp(1, a, n);
        doOp(1, b, n);
        doOp(1, a, n);
    } else {
        doOp(1, b, n);
        doOp(1, n, n);
        doOp(a, n, n);
        doOp(1, n, n);
        doOp(1, b, n);
    }
    swap(p[a], p[b]);
    swap(w[p[a]], w[p[b]]);
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("abbreviation.out");
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        q[i] = p[i];
        w[p[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (w[i] != i) {
            doSwap(i, w[i], n);
        }
    }
    assert(sol.size() <= 5 * n);
    cout << sol.size() << "\n";
    for (auto it : sol) {
        cout << it.first << " " << it.second << "\n";
        assert(myAbs(it.first - it.second) >= n / 2);
        swap(q[it.first], q[it.second]);
    }
    for (int i = 1; i <= n; i++) {
        assert(q[i] == i);
    }
    //timeDuration();
    return 0;
}