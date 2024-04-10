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
const int MAXVAL = 300000;
const int SQRT = 1000;

int v[1 + MAXN];
int rem[1 + SQRT][1 + SQRT];
long long fenwickCount[1 + MAXVAL];
bool have[SQRT];
long long fenwickSum[1 + MAXVAL], fenwickSub[1 + MAXVAL];

void update(int x, long long fenwick[], long long add) {
    for (; x <= MAXVAL; x += (x & -x)) {
        fenwick[x] += add;
    }
}

long long query(int x, long long fenwick[]) {
    long long sum = 0;
    for (; x > 0; x -= (x & -x)) {
        sum += fenwick[x];
    }
    return sum;
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
        cin >> v[i];
    }
    int big = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] <= SQRT) {
            for (int r = 0; r < v[i]; r++) {
                ans += 1LL * r * rem[v[i]][r];
            }
        } else {
            for (int c = 0; c * v[i] <= MAXVAL; c++) {
                int l = max(1, c * v[i]), r = min(MAXVAL, (c + 1) * v[i] - 1);
                long long count = query(r, fenwickCount) - query(l - 1, fenwickCount);
                long long sum = query(r, fenwickSum) - query(l - 1, fenwickSum);
                ans += sum - count * c * v[i];
            }
        }
        for (int x = 0; x <= SQRT; x++) {
            if (have[x]) {
                ans += v[i] % x;
            }
        }
        ans += 1LL * v[i] * big - query(v[i], fenwickSub);
        cout << ans << " ";
        for (int x = 1; x <= SQRT; x++) {
            rem[x][v[i] % x]++;
        }
        update(v[i], fenwickCount, 1);
        update(v[i], fenwickSum, v[i]);
        if (v[i] <= SQRT) {
            have[v[i]] = true;
        } else {
            big++;
            for (int c = 1; c * v[i] <= MAXVAL; c++) {
                int l = max(1, c * v[i]);
                update(l, fenwickSub, v[i]);
            }
        }
    }
    return 0;
}