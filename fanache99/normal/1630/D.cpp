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

const int MAXN = 1000000;
const int INF = 1e9;

int v[1 + MAXN], sum[1 + MAXN + 1];

int myGcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int myAbs(int x) {
    return (x < 0 ? -x : x);
}

int main() {
    timeBegin();
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, m;
        cin >> n >> m;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            ans += myAbs(v[i]);
        }
        int k = 0;
        for (int i = 1; i <= m; i++) {
            int d;
            cin >> d;
            k = myGcd(k, d);
        }
        for (int i = 1; i <= n; i++) {
            sum[i] += sum[i - 1];
            int p = ((v[i] < 0) ^ (sum[i] % 2));
            if (p == 1 && i + k - 1 <= n) {
                sum[i]++;
                sum[i + k]--;
                p = 0;
            }
            v[i] = (p == 0 ? myAbs(v[i]) : -myAbs(v[i]));
        }
        long long sum1 = 0, sum2 = 0;
        for (int i = n; i >= n - k + 1; i--) {
            int best = INF;
            for (int j = i; j >= 1; j -= k) {
                best = min(best, myAbs(v[j]));
            }
            if (v[i] >= 0) {
                sum1 += 2 * best;
            } else {
                sum2 += 2 * best;
            }
        }
        ans -= min(sum1, sum2);
        cout << ans << "\n";
        for (int i = 1; i <= n + 1; i++) {
            sum[i] = 0;
        }
    }
    return 0;
}