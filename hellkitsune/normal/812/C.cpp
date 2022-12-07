#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, s;
int a[100000];
LL b[100000];

LL solve(int cnt) {
    forn(i, n) b[i] = a[i] + (LL)(i + 1) * cnt;
    sort(b, b + n);
    LL res = 0;
    forn(i, cnt) res += b[i];
    return res;
}

int main() {
    scanf("%d%d", &n, &s);
    forn(i, n) scanf("%d", a + i);
    int lo = 0, hi = n, mid;
    int sum = 0;
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        LL res = solve(mid);
        if (res <= s) {
            lo = mid;
            sum = res;
        } else {
            hi = mid - 1;
        }
    }
    cout << lo << ' ' << sum << endl;
    return 0;
}