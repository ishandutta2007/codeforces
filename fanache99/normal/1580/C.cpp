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
const int SQRT = 200;

int x[1 + MAXN], y[1 + MAXN];
int started[1 + MAXN];
int small[1 + SQRT][1 + SQRT];
int big[1 + MAXN + 1];

void update(int t, int p, int n, int add, int a, int b) {
    assert(p <= t);
    if (a + b > SQRT) {
        int u = p + a, v = p + a + b;
        while (u <= n) {
            if (v > t) {
                big[max(t, u)] += add;
                big[min(v, n + 1)] -= add;
            }
            u += (a + b);
            v += (a + b);
        }
    } else {
        for (int i = p + a; i < p + a + b; i++) {
            small[a + b][i % (a + b)] += add;
        }
    }
}

int main() {
    timeBegin();
    //  ifstream cin("input.txt");
//    ofstream cout("answer.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    int sum = 0;
    for (int i = 1; i <= m; i++) {
        int op, t;
        cin >> op >> t;
        if (op == 1) {
            started[t] = i;
        }
        op = (op == 1 ? 1 : -1);
        update(i, started[t], m, op, x[t], y[t]);
        sum += big[i];
        int ans = sum;
        for (int d = 1; d <= SQRT; d++) {
            ans += small[d][i % d];
        }
        cout << ans << "\n";
    }
    return 0;
}