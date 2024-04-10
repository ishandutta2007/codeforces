#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

namespace myrand
{
    mt19937 mt(chrono::system_clock::now().time_since_epoch() / chrono::microseconds(1));
    ll Int(ll l,ll r) {return uniform_int_distribution<ll> (l,r)(mt);}
}

using namespace myrand;

ull modmul(ull a, ull b, ull M) {
    ll ret = a * b - M * ull(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}

ull modpow(ull b, ull e, ull mod) {
    ull ans = 1;
    for (; e; b = modmul(b, b, mod), e /= 2)
        if (e & 1) ans = modmul(ans, b, mod);
    return ans;
}

ull inverse(ull x, ull mod) { return modpow(x, mod - 2, mod);}

const int N = 2e5 + 10;
const ll mod = 1e9 + 7, Hmod = (ll)44 * mod + 1;
ll base, ps[N];
int a[N], n, q;
unordered_map<int, vi> pos;

int Find(int x, int l)
{
    if (!pos.count(x)) return 1e9;
    vi &vt = pos[x];
    auto it = lower_bound(all(vt), l);
    if (it == vt.end()) return 1e9;
    return *it;
}

ll cal(ll x, ll h) // x^0 + .. + x^h - 1
{
    if (x == 1) return h;
    return modmul((modpow(x, h, Hmod) + Hmod - 1) % Hmod, inverse((x + Hmod - 1) % Hmod, Hmod), Hmod);
}
int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    base = 31410061773;
    while (modpow(base, mod, Hmod) != 1) base = Int(N, Hmod - 1);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i], ps[i] = (ps[i - 1] + modpow(base, a[i], Hmod)) % Hmod, pos[a[i]].eb(i);
    for (int i = 1, l, r, d; i <= q; ++i)
    {
        cin >> l >> r >> d;
        int x = a[l], mn = a[l];
        int low = 0, high = r - l;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int p = Find((x - (ll)mid * d + mod * mod) % mod, l);
            if (p <= r) low = mid + 1, mn = a[p];
            else high = mid - 1;
        }
        //cout << mn << "\n";
        ll val = (ps[r] - ps[l - 1] + Hmod) % Hmod;
        val = modmul(val, inverse(modpow(base, mn, Hmod), Hmod), Hmod);
        if (val == cal(modpow(base, d, Hmod), r - l + 1)) cout << "Yes\n";
        else cout << "No\n";
        //cout << val << " " << cal(modpow(base, d, Hmod), r - l + 1) << "\n";
    }
    return 0;
}