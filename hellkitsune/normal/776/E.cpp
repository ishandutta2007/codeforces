#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

bool pr[1000005];
vector<int> p;

void init() {
    forn(i, 1000005) {
        pr[i] = true;
    }
    pr[0] = pr[1] = false;
    forn(i, 2000) if (pr[i]) {
        for (int j = i * i; j < 1000005; j += i) {
            pr[j] = false;
        }
    }
    forn(i, 1000005) if (pr[i]) {
        p.pb(i);
    }
}

LL tot(LL num) {
    LL res = 1;
    for (LL x : p) {
        if (x * x > num) {
            break;
        }
        if (num % x == 0) {
            res *= x - 1;
            num /= x;
            while (num % x == 0) {
                res *= x;
                num /= x;
            }
        }
    }
    if (num > 1) {
        res *= num - 1;
    }
    return res;
}

LL n, k;

const LL MOD = LL(1e9) + 7;

int main() {
    init();
    cin >> n >> k;
    k = (k + 1) / 2;
    for (LL x = 0; x < k; ++x) {
        if (n == 1) {
            break;
        }
        n = tot(n);
    }
    cout << n % MOD << endl;
    return 0;
}