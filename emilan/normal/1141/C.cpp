#include <bits/stdc++.h>
using namespace std;

#define int ll
#define vt vector
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define X first
#define Y second
#define F first
#define S second
#define rep(i, st, n) for (int i=(st); i<(n); ++i)
#define debug(x) std::cerr << #x << ": " << x << endl
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define CS <<" "<<
#define CE <<"\n"

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define die return void(cout << -1)

int T = 1;

void solve() {
    int n;
    cin >> n;
    vt<int> a(n - 1);
    for (int &x : a) cin >> x;

    vt<int> p(n);
    p[1] = a[0];
    for (int i = 1; i < n - 1; i++) {
        p[i + 1] = p[i] + a[i];
    }

    int mn = *min_element(all(p));
    for (int &x : p) x += -mn + 1;

    if (*max_element(all(p)) > n) die;

    set<int> s(all(p));
    if (sz(s) != n) die;

    for (int &x : p) cout << x << ' ';
}

signed main() {

    IOS;

    rep(tc, 1, T+1){
        // cout << "Case #" << tc << ": ";
        solve();
    }

}