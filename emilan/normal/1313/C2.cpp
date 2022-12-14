#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    vector<ll> al(n), ar(n);
    vii st;
    ll cur = 0;
    rep(i, n) {
        int cnt = 1;
        while (!st.empty() && st.back().fi > a[i]) {
            cnt += st.back().se;
            cur -= (ll)st.back().se * st.back().fi;
            st.pop_back();
        }   
        cur += (ll)a[i] * cnt;
        st.eb(a[i], cnt);
        al[i] = cur;
    }
    st.clear();
    cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        int cnt = 1;
        while (!st.empty() && st.back().fi > a[i]) {
            cnt += st.back().se;
            cur -= (ll)st.back().se * st.back().fi;
            st.pop_back();
        }   
        cur += (ll)a[i] * cnt;
        st.eb(a[i], cnt);
        ar[i] = cur;
    }

    int idx = 0;
    ll mx = 0;
    rep(i, n) {
        ll cur = al[i] + ar[i] - a[i];
        if (cur > mx) {
            mx = cur;
            idx = i;
        }
    }

    for (int i = idx - 1; i >= 0; i--) {
        a[i] = min(a[i], a[i + 1]);
    }
    for (int i = idx + 1; i < n; i++) {
        a[i] = min(a[i], a[i - 1]);
    }

    for (int i : a) cout << i << ' ';

    return 0;
}