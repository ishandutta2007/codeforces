#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

bool isPrime(int i) {
    for (int j = 2; j * j <= i; ++j) {
        if (i % j == 0) {
            return false;
        }
    }
    return true;
}

int gcd(int a, int b) {
    while (b) a %= b, swap(a, b);
    return a;
}

const int INF = int(1e9);

int main() {
    int num;
    cin >> num;
    if (num == 1) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 2; i <= 10000; ++i) {
        if (num % i != 0) {
            continue;
        }
        int mul = num / i;
        for (int x = (i + 1) / 2; ; ++x) {
            //2 / i - 1 / x
            //(2 * x - i) / (i * x)
            int num = 2 * x - i;
            int denom = i * x;
            int g = gcd(num, denom);
            num /= g;
            denom /= g;
            for (int y = x + 1; y <= 100000 && (LL)y * mul <= INF; ++y) {
                LL nnum = (LL)num * y - denom;
                LL ndenom = (LL)denom * y;
                if (nnum > 0 && ndenom % nnum == 0) {
                    ndenom /= nnum;
                    if (ndenom != x && ndenom != y && ndenom * mul <= INF) {
                        cout << x * mul << ' ' << y * mul << ' ' << ndenom * mul << endl;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}