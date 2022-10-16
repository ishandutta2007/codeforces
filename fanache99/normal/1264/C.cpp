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

const int MOD = 998244353;
const int MAXN = 200000;

int raiseToPower(int base, int power) {
    int answer = 1;
    while (power) {
        if (power & 1) {
            answer = 1LL * answer * base % MOD;
        }
        base = 1LL * base * base % MOD;
        power >>= 1;
    }
    return answer;
}

int p[1 + MAXN], prod[1 + MAXN + 1], sum[1 + MAXN + 1];
bool active[1 + MAXN];
set<int> s;

void add(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

void sub(int &x, int y) {
    x -= y;
    if (x < 0) {
        x += MOD;
    }
}

int getProd(int a, int b) {
    return 1LL * prod[a] * raiseToPower(prod[b + 1], MOD - 2) % MOD;
}

int getSum(int a, int b) {
    return ((-1LL * getProd(a, b) * sum[b + 1] + sum[a] + 1) % MOD + MOD) % MOD;
}

int compute(int a, int b) {
    return (1LL * getSum(a, b) * raiseToPower(getProd(a, b), MOD - 2) % MOD + MOD - 1) % MOD;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, q, divide100 = raiseToPower(100, MOD - 2);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        p[i] = 1LL * p[i] * divide100 % MOD;
    }
    prod[n + 1] = 1;
    sum[n + 1] = 0;
    for (int i = n; i >= 1; i--) {
        prod[i] = 1LL * p[i] * prod[i + 1] % MOD;
        sum[i] = 1LL * p[i] * (1 + sum[i + 1]) % MOD;
    }
    s.insert(1);
    s.insert(n + 1);
    int answer = compute(1, n);
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        if (!active[x]) {
            auto it = s.lower_bound(x);
            int a = *prev(it), b = *it;
            sub(answer, compute(a, b - 1));
            add(answer, compute(a, x - 1));
            add(answer, compute(x, b - 1));
            s.insert(x);
            active[x] = true;
        } else {
            s.erase(x);
            active[x] = false;
            auto it = s.lower_bound(x);
            int a = *prev(it), b = *it;
            sub(answer, compute(a, x - 1));
            sub(answer, compute(x, b - 1));
            add(answer, compute(a, b - 1));
        }
        cout << answer << "\n";
    }
    return 0;
}