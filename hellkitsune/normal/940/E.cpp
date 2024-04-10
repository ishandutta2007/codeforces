#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, c;
int a[100005];
multiset<int> se;
LL d[100005];

int main() {
    scanf("%d%d", &n, &c);
    forn(i, n) scanf("%d", a + i);
    forn(i, min(n, c - 1)) {
        se.insert(a[i]);
    }
    forn(i, n) {
        d[i + 1] = max(d[i + 1], d[i]);
        if (i + c - 1 < n) {
            se.insert(a[i + c - 1]);
            d[i + c] = max(d[i + c], d[i] + (*se.begin()));
        }
        auto it = se.find(a[i]);
        se.erase(it);
    }
    LL ans = -d[n];
    forn(i, n) ans += a[i];
    cout << ans << endl;
    return 0;
}