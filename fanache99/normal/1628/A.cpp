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
#include <chrono>
#include <random>

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

    template<typename T>
    inline InputReader &operator>>(T &n) {
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

const int MAXN = 200000;

int v[1 + MAXN];
int suff[1 + MAXN + 1];
int f[1 + MAXN + 1];

int main() {
    timeBegin();
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        suff[n + 1] = 0;
        for (int i = n; i >= 1; i--) {
            f[v[i]]++;
            suff[i] = suff[i + 1];
            while (f[suff[i]] > 0) {
                suff[i]++;
            }
        }
        for (int i = 0; i <= n + 1; i++) {
            f[i] = 0;
        }
        vector<int> b;
        for (int i = 1, j; i <= n; i = j + 1) {
            j = i;
            f[v[i]]++;
            int mex = 0;
            while (f[mex] > 0) {
                mex++;
            }
            while (mex < suff[i]) {
                j++;
                f[v[j]]++;
                while (f[mex] > 0) {
                    mex++;
                }
            }
            assert(j <= n);
            b.push_back(mex);
            for (int k = i; k <= j; k++) {
                f[v[k]] = 0;
            }
        }
        cout << b.size() << "\n";
        for (auto it : b) {
            cout << it << " ";
        }
        cout << "\n";
    }
    return 0;
}