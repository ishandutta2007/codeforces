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

const int MAXH = 20;

int v[1 << MAXH], weight[1 << MAXH], target[1 << MAXH];

bool fTry(int n, int i) {
    if (weight[i] == target[i]) {
        return false;
    }
    while ((2 * i < n && v[2 * i] != 0) || (2 * i + 1 < n && v[2 * i + 1] != 0)) {
        if (v[2 * i] > v[2 * i + 1]) {
            i = 2 * i;
        } else {
            i = 2 * i + 1;
        }
        if (weight[i] == target[i]) {
            return false;
        }
    }
    return true;
}

void f(long long &sum, vector<int> &sol, int n, int i) {
    sol.push_back(i);
    sum += v[i];
    while ((2 * i < n && v[2 * i] != 0) || (2 * i + 1 < n && v[2 * i + 1] != 0)) {
        weight[i]--;
        if (v[2 * i] > v[2 * i + 1]) {
            v[i] = v[2 * i];
            i = 2 * i;
        } else {
            v[i] = v[2 * i + 1];
            i = 2 * i + 1;
        }
    }
    weight[i]--;
    v[i] = 0;
}

int main() {
    timeBegin();
    InputReader cin;
    //ofstream cout("output.out");
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    srand(time(0));
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int h, g;
        cin >> h >> g;
        int n = 1 << h, m = 1 << g;
        long long total = 0;
        for (int i = 1; i < n; i++) {
            cin >> v[i];
            total += v[i];
        }
        for (int i = n - 1; i >= 1; i--) {
            weight[i] = 1;
            if (2 * i < n) {
                weight[i] += weight[2 * i];
            }
            if (2 * i + 1 < n) {
                weight[i] += weight[2 * i + 1];
            }
            target[i] = 0;
            if (i < m) {
                target[i] = 1;
                if (2 * i < m) {
                    target[i] += target[2 * i];
                }
                if (2 * i + 1 < m) {
                    target[i] += target[2 * i + 1];
                }
            }
        }
        vector<int> sol;
        long long sum = 0;
        for (int i = 1; i < m; i++) {
            while (fTry(n, i)) {
                f(sum, sol, n, i);
            }
        }
        assert(sol.size() == n - m);
        cout << total - sum << "\n";
        for (auto it : sol) {
            cout << it << " ";
        }
        cout << "\n";
    }
    return 0;
}