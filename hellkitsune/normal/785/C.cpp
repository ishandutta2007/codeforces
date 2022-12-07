#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL n, m;

int main() {
    cin >> n >> m;
    if (m >= n) {
        cout << n << endl;
        return 0;
    }
    n -= m;
    LL lo = 0, hi = 2.5e9, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (mid * (mid + 1) / 2 >= n) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo + m << endl;
    return 0;
}