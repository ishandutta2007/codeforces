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

const int MOD = 1000000007;
const int MAXLOG = 70;

int prob[1 + MAXLOG];
int divide[1 + MAXLOG];

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

void addTo(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

int power(int x, int p, int k) {
    for (int i = 0; i < p; i++) {
        prob[i] = 0;
    }
    prob[p] = 1;
    for (int r = 1; r <= k; r++) {
        for (int i = p, sum = 0; i >= 0; i--) {
            addTo(sum, 1LL * prob[i] * divide[i + 1] % MOD);
            prob[i] = sum;
        }
    }
    int answer = 0;
    for (int i = 0, val = 1; i <= p; i++) {
        addTo(answer, 1LL * val * prob[i] % MOD);
        val = 1LL * val * x % MOD;
    }
    return answer;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream fout("input.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 1; i <= MAXLOG; i++) {
        divide[i] = raiseToPower(i, MOD - 2);
    }
    long long n;
    int k;
    cin >> n >> k;
    int answer = 1;
    for (int d = 2; 1LL * d * d <= n; d++) {
        if (n % d == 0) {
            int p = 0;
            while (n % d == 0) {
                p++;
                n /= d;
            }
            answer = 1LL * answer * power(d, p, k) % MOD;
        }
    }
    if (n != 1) {
        answer = 1LL * answer * power(n % MOD, 1, k) % MOD;
    }
    cout << answer << "\n";
    //timeDuration();
    return 0;
}