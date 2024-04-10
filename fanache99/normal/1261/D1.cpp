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

const int MOD = 998244353;
const int MAXN = 200000;

int factorial[1 + MAXN], inverse[1 + MAXN], h[1 + MAXN];

int raiseToPower(int base, int power) {
    int answer = 1;
    while (power) {
        if (power % 2)
            answer = (1LL * answer * base) % MOD;
        base = (1LL * base * base) % MOD;
        power /= 2;
    }
    return answer;
}

void precompute(int n) {
    factorial[0] = inverse[0] = 1;
    for (int i = 1; i <= n; i++)
        factorial[i] = (1LL * factorial[i - 1] * i) % MOD;
    inverse[n] = raiseToPower(factorial[n], MOD - 2);
    for (int i = n - 1; i >= 1; i--)
        inverse[i] = (1LL * (i + 1) * inverse[i + 1]) % MOD;
}

int combinations(int n, int k) {
    if (k < 0 || n < 0 || k > n) {
        return 0;
    }
    int answer = (1LL * inverse[n - k] * inverse[k]) % MOD;
    answer = (1LL * answer * factorial[n]) % MOD;
    return answer;
}

void addTo(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

void subtractFrom(int &x, int y) {
    x -= y;
    if (x < 0) {
        x += MOD;
    }
}


int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream fout("input.i`n");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    precompute(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int d = 0;
    for (int i = 0; i < n; i++) {
        if (h[i] != h[(i + 1) % n]) {
            d++;
        }
    }
    int answer = 0;
    for (int i = 0; i < d; i++) {
        int j = d - i, current = 1LL * raiseToPower(k - 2, i) * combinations(d, i) % MOD;
        if (j % 2 == 1) {
            current = 1LL * current * raiseToPower(2, j - 1) % MOD;
        } else {
            int temp = raiseToPower(2, j);
            subtractFrom(temp, combinations(j, j / 2));
            temp = 1LL * temp * raiseToPower(2, MOD - 2) % MOD;
            current = 1LL * current * temp % MOD;
        }
        addTo(answer, current);
    }
    answer = 1LL * answer * raiseToPower(k, n - d) % MOD;
    cout << answer << "\n";
    //timeDuration();
    return 0;
}