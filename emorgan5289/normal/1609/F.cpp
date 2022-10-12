#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

// Transform the contents of [first, last) into elements of [0..N],
// while preserving the relative ordering/equality of the data.
// Runs in O(nlogn).

template<typename it1, typename it2, typename cmp = less<>>
void compress(it1 first, it1 last, it2 result, cmp ord = less<>()) {
    using T = typename iterator_traits<it1>::value_type;
    map<T, vector<it2>, cmp> m(ord);
    for (it1 i = first; i != last; i++)
        m[*i].push_back(result+(i-first));
    int t = 0;
    for (auto& [_, v] : m) {
        for (auto& i : v) *i = t;
        t++;
    }
}

const ll N = 1ll<<20, K = 61;
ll a[N];
int pc[N];
ll ans = 0;

void dfs(int l, int r) {
    if (l == r) return;
    if (l+1 == r) {
        ans++;
        return;
    }
    int m = (l+r)/2;
    // [l, m) and [m, r)
    // debug(l, m, r);

    vector<array<ll, 4>> vl, vr;
    ll la, ra, lp, rp;
    la = inf_ll, ra = -inf_ll;
    lp = 0, rp = 0;
    for (int i = m-1; i >= l; i--) {
        if (a[i] < la) la = a[i], lp = pc[i];
        if (a[i] > ra) ra = a[i], rp = pc[i];
        vl.pb({la, ra, lp, rp});
    }
    la = inf_ll, ra = -inf_ll;
    lp = 0, rp = 0;
    for (int i = m; i < r; i++) {
        if (a[i] < la) la = a[i], lp = pc[i];
        if (a[i] > ra) ra = a[i], rp = pc[i];
        vr.pb({la, ra, lp, rp});
    }
    ll j, jl, jr;
    vector<ll> c;
    // debug(vl);
    // debug(vr);

    // l fully contained in r
    j = 0;
    for (int i = 0; i < vr.size(); i++) {
        while (j < vl.size() && vl[j][0] >= vr[i][0] && vl[j][1] <= vr[i][1])
            j++;
        if (vr[i][2] == vr[i][3])
            ans += j;
    }

    // r fully contained in l, but not exactly equal
    j = 0;
    for (int i = 0; i < vl.size(); i++) {
        while (j < vr.size() && vr[j][0] >= vl[i][0] && vr[j][1] <= vl[i][1] && (vr[j][0] != vl[i][0] || vr[j][1] != vl[i][1]))
            j++;
        if (vl[i][2] == vl[i][3])
            ans += j;
    }

    // l has the min, but r has the max, no ties allowed
    jl = 0, jr = 0;
    c.assign(K, 0);
    for (int i = 0; i < vr.size(); i++) {
        while (jr < vl.size() && vl[jr][1] < vr[i][1])
            c[vl[jr++][2]]++;
        while (jl < jr && vl[jl][0] >= vr[i][0])
            c[vl[jl++][2]]--;
        ans += c[vr[i][3]];
    }

    // r has the min, but l has the max, no ties allowed
    jl = 0, jr = 0;
    c.assign(K, 0);
    for (int i = 0; i < vl.size(); i++) {
        while (jr < vr.size() && vr[jr][1] < vl[i][1])
            c[vr[jr++][2]]++;
        while (jl < jr && vr[jl][0] >= vl[i][0])
            c[vr[jl++][2]]--;
        ans += c[vl[i][3]];
    }

    dfs(l, m), dfs(m, r);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pc[i] = __builtin_popcountll(a[i]);
    }
    ll m = *max_element(pc, pc+n)+1;
    // compress(a, a+n, a);
    // debug(vector(a, a+n));
    // debug(vector(pc, pc+n));
    dfs(0, n);
    cout << ans << "\n";
}