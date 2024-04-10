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

int v[1 + MAXN];

long long best(int m, int n, int x, int a, int y, int b) {
    int xs = 0, ys = 0, xys = 0;
    vector<int> ps;
    for (int i = 1; i <= m; i++) {
        if (i % a == 0 && i % b == 0) {
            xys++;
        } else if (i % a == 0) {
            xs++;
        } else if (i % b == 0) {
            ys++;
        }
    }
    long long answer = 0;
    for (int i = 1; i <= xys; i++) {
        answer += 1LL * (x + y) * v[i] / 100;
    }
    for (int i = xys + 1; i <= xys + ys; i++) {
        answer += 1LL * y * v[i] / 100;
    }
    for (int i = xys + ys + 1; i <= xys + ys + xs; i++) {
        answer += 1LL * x * v[i] / 100;
    }
    return answer;
}

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
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        sort(v + 1, v + n + 1);
        reverse(v + 1, v + n + 1);
        int x, a, y, b;
        long long k;
        cin >> x >> a >> y >> b >> k;
        if (x > y) {
            swap(x, y);
            swap(a, b);
        }
        int left = 1, right = n, answer = n + 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (best(middle, n, x, a, y, b) >= k) {
                answer = middle;
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        if (answer == n + 1) {
            cout << "-1\n";
        } else {
            cout << answer << "\n";
        }
    }
    return 0;
}