#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[500];
vector<int> b, c;

int main() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d", a + i);
    }
    int val = a[0];
    for (int i = 1; i <= min(1000000, val); ++i) {
        if (val / i >= val % i) {
            b.pb(i);
        }
    }
    for (int num = val / 1000000; num > 0; --num) {
        for (int i = val / num; i > 0 && val / i == num && num >= val % i; --i) {
            b.pb(i);
        }
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i = 1; i < n; ++i) {
        c.clear();
        for (int x : b) {
            if (a[i] / x >= a[i] % x) {
                c.pb(x);
            }
        }
        b = c;
    }
    int mx = b.back();
    //cerr << mx << endl;
    LL ans = 0;
    forn(i, n) {
        ans += (a[i] + mx) / (mx + 1);
    }
    cout << ans << endl;
    return 0;
}