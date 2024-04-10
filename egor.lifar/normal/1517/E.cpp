/*
KAMUI!
 
 

 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

*/
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
 
using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
using ll = long long;
using ld = long double; 
const string FILENAME = "input";
const int Mod = 998244353;


int sum(int a, int b) {
    return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
    return ((ll)a * b) % Mod;
}


int powm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}


int inv(int a) {
    return powm(a, Mod - 2);
}


const int MAXN = 400228;


int n;
int a[MAXN];
ll pref[MAXN];
ll suff[MAXN];
ll ans;




struct rmq {
    vector<int> d;
    int ss = 1;
    void init(int n) {
        while (ss < n) {
            ss <<= 1;
        }
        d.resize(2 * ss, 0);
    }
    void change(int i, int val) {
        i += ss;
        d[i] += val;
        while (i >> 1 > 0) {
            i >>= 1;
            d[i] = d[i * 2] + d[i * 2 + 1];
        }
    }
    int get(int l, int r) {
        l += ss;
        r += ss;
        int ans = 0;
        while (l <= r) {
            if (l & 1) {
                ans += d[l];
                l++;
            }
            if (!(r & 1)) {
                ans += d[r];
                r--;
            }
            l >>= 1;
            r >>= 1;
        }
        return ans;
    }
};



ll megasuff[MAXN];


void solve(int l, int r, ll add = 0) {
    ll cur = add;
    for (int i = l; i <= r; i++) {
        cur -= a[i];
    }
    if (cur > 0) {
        ans++;
    }
    rmq kek[2];
    kek[0].init(2 * n);
    kek[1].init(2 * n);
    vector<ll> st;
    megasuff[r + 1] = 0;
    megasuff[r + 2] = 0;
    for (int i = r; i >= l + 1; i--) {
        ll f = pref[r] - pref[i - 1] + add;
        ll sub = pref[i - 1] - (l ? pref[l - 1]: 0);
        if (f - sub > 0) {
            ans++;
        }
        megasuff[i] = a[i] - a[i + 1] + megasuff[i + 2];
        st.pb(f - megasuff[i]);
        if (i < r) {
            ll f2 = f - 2 * a[r];
            st.pb(f2 - megasuff[i]);
            if (f2 - sub > 0) {
                ans++;
            }
        }
    }
    sort(all(st));
    st.resize(distance(st.begin(), unique(all(st))));
    for (int i = r; i >= l + 1; i--) {
        ll sub = pref[i - 1] - (l ? pref[l - 1]: 0);
        int pos = upper_bound(all(st), -megasuff[i] + sub) - st.begin();
        ans += kek[i & 1].get(pos, sz(st) - 1);
        {
            ll f = pref[r] - pref[i - 1] + add;
            pos = lower_bound(all(st), f - megasuff[i]) - st.begin();
            kek[i & 1].change(pos, 1);
            if (i < r) {
                ll f2 = f - 2 * a[r];
                pos = lower_bound(all(st), f2 - megasuff[i]) - st.begin();
                kek[i & 1].change(pos, 1);
            }
        }
    }
}


void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        pref[i] = a[i];
        suff[i] = a[i];
    }
    for (int i = 1; i < n; i++) {
        pref[i] += pref[i - 1];
    }
    for (int i = n - 2; i >= 0; i--) {
        suff[i] += suff[i + 1];
    }
    ans = 0;
    for (int i = 1; i < n; i++) {
        ll d = pref[i] - (pref[n - 1] - pref[i]);
        if (d > 0) {
            ans++;
        }
    }
    solve(1, n - 1, a[0]);
    solve(0, n - 1);
    cout << ans % Mod << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}