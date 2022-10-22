#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC

const int MOD = 998244353;
int mod(int n) {
    n %= MOD;
    if (n < 0) return n + MOD;
    else return n;
}   
int fp(int a, int p) {
    int ans = 1, c = a;
    for (int i = 0; (1ll << i) <= p; ++i) {
        if ((p >> i) & 1) ans = mod(ans * c);
        c = mod(c * c);
    }   
    return ans;
}   
int dv(int a, int b) { return mod(a * fp(b, MOD - 2)); }

const int N = 2e5 + 7;
int pref[N], sum[N], sumi[N];
bool cur[N];
set <int> ms;
int right(int i) {
    return *ms.upper_bound(i);
}   
int left(int i) {
    auto t = ms.lower_bound(i); --t;
    return *t;
}   
int get(int i) {
    int r = right(i);
    int p = dv(pref[r - 1], pref[i - 1]);
    int s1 = mod((r - i) * p);
    int s2 = mod(dv(mod(sumi[r - 1] - sumi[i - 1]), pref[i - 1]) - dv(mod(sum[r - 1] - sum[i - 1]), pref[i - 1]) * (i - 1));
    return dv(mod(s1 + s2), p);
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, q;
    cin >> n >> q;
    pref[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int p; cin >> p;
        pref[i] = mod(pref[i - 1] * dv(p, 100));
        sum[i] = mod(sum[i - 1] + pref[i - 1] * dv(100 - p, 100));
        sumi[i] = mod(sumi[i - 1] + mod(pref[i - 1] * dv(100 - p, 100)) * i);
    }   
    #ifdef HOME
    for (int i = 1; i <= n; ++i)
        cout << pref[i] << ' ';
    cout << '\n';
    for (int i = 1; i <= n; ++i)
        cout << sum[i] << ' ';
    cout << '\n';
    #endif
    cur[1] = 1;
    ms.insert(1);
    ms.insert(n + 1);
    int ans = get(1);
    while (q--) {
        int i; cin >> i;
        if (cur[i]) {
            int l = left(i);
            ans -= get(i);
            ans -= get(l);
            ms.erase(i);
            ans += get(l);
        }
        else {
            int l = left(i);
            ans -= get(l);
            ms.insert(i);
            ans += get(l);
            ans += get(i);
        }   
        cur[i] ^= 1;
        ans = mod(ans);
        cout << ans << '\n';
    }   
}