#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const LL MX = LL(1e12);

int n, k;
string s, t;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> s >> t;
    --k;
    LL cur = 0, ans = n;
    forn(i, n) {
        LL old = cur;
        cur = 2 * cur + (t[i] - s[i]);
        ans += min((LL)k, cur - old) * (n - i);
        k -= min((LL)k, cur - old);
        cur = min(cur, MX);
    }
    cout << ans << endl;
    return 0;
}