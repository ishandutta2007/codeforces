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

const int MAXN = 200000;

int p[1 + MAXN], where[1 + MAXN];
int fenwick[1 + MAXN];

void update(int x, int n) {
    for (; x <= n; x += (x & -x)) {
        fenwick[x]++;
    }
}

int query(int x) {
    int answer = 0;
    for (; x > 0; x -= (x & -x)) {
        answer += fenwick[x];
    }
    return answer;
}

long long gauss(int a, int b) {
    return 1LL * b * (b + 1) / 2 - 1LL * a * (a - 1) / 2;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        where[p[i]] = i;
    }
    long long inv = 0;
    set<int> low, high;
    long long sumLow = 0, sumHigh = 0;
    for (int i = 1; i <= n; i++) {
        int x = where[i];
        inv += (query(n) - query(x));
        update(x, n);
        if (i == 1 || x < *low.rbegin()) {
            low.insert(x);
            sumLow += x;
        } else {
            high.insert(x);
            sumHigh += x;
        }
        if (high.size() > low.size()) {
            sumHigh -= *high.begin();
            sumLow += *high.begin();
            low.insert(*high.begin());
            high.erase(*high.begin());
        }
        if (low.size() > high.size() + 1) {
            sumLow -= *low.rbegin();
            sumHigh += *low.rbegin();
            high.insert(*low.rbegin());
            low.erase(*low.rbegin());
        }
        int m = *low.rbegin();
        long long move = gauss(m - low.size() + 1, m) - sumLow + sumHigh - gauss(m + 1, m + high.size());
        cout << inv + move << " ";
    }
    return 0;
}