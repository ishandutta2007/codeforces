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

const int MAXN = 100000;

int a[1 + 10 * MAXN], b[1 + 10 * MAXN];

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, aSum = 0, bSum = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            aSum += a[i];
        }
        sort(a + 1, a + n + 1);
        int ap = 0;
        while (ap + 1 <= n / 4) {
            ap++;
            aSum -= a[ap];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        sort(b + 1, b + n + 1);
        reverse(b + 1, b + n + 1);
        int bp = 0;
        while (bp + 1 <= n - n / 4) {
            bp++;
            bSum += b[bp];
        }
        int ans = 0;
        while (aSum < bSum) {
            ans++;
            n++;
            a[n] = 100;
            b[n] = 0;
            aSum += 100;
            while (ap + 1 <= n / 4) {
                ap++;
                aSum -= a[ap];
            }
            while (bp + 1 <= n - n / 4) {
                bp++;
                bSum += b[bp];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}