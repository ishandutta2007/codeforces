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

const int MAXN = 1000000;
const long long INF = 1e18;

long long v[1 + MAXN];

long long myGcd(long long a, long long b) {
    while (b) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

vector<long long> divisors(long long n) {
    vector<long long> ans;
    for (long long d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            ans.push_back(d);
            while (n % d == 0) {
                n /= d;
            }
        }
    }
    if (n != 1) {
        ans.push_back(n);
    }
    return ans;
}

long long setDiv(long long d, int n) {
    long long ans = 0, sum = 0;
    for (int i = 1; i < n; i++) {
        sum += v[i];
        ans += min(sum % d, d - sum % d);
    }
    return ans;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n;
    long long gcd = 0;
    long long sum = 0;
    vector<int> ones;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        gcd = myGcd(gcd, v[i]);
        sum += v[i];
        if (v[i] == 1) {
            ones.push_back(i);
        }
    }
    if (gcd > 1) {
        cout << "0\n";
    } else if (sum == 1) {
        cout << "-1\n";
    } else {
        vector<long long> div = divisors(sum);
        long long ans = INF;
        for (auto d : div) {
            ans = min(ans, setDiv(d, n));
        }
        cout << ans << "\n";
    }
    return 0;
}