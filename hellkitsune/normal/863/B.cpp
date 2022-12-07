#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[100];
vector<int> v;

int solve() {
    int cur = 0;
    for (int i = 0; i < (int)v.size(); i += 2) {
        cur += v[i + 1] - v[i];
    }
    return cur;
}

int main() {
    cin >> n;
    n *= 2;
    forn(i, n) cin >> a[i];
    sort(a, a + n);
    int ans = int(1e9);
    forn(i, n) forn(j, i) {
        v.clear();
        forn(k, n) if (k != i && k != j) {
            v.pb(a[k]);
        }
        ans = min(ans, solve());
    }
    cout << ans << endl;
    return 0;
}