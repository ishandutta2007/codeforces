/*














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
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { x = (x > y ? y: x);}
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { x = (x < y ? y: x);}
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left224
#define right right224
#define rank rank224
#define y1 y1224
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
const string FILENAME = "input";
const int MAXN = 20228;



const ll MOD = 998244353;


int rev[300000 * 4];
const int G = 3;

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}


int sum(int a, int b) {
    return (1LL * a + b + MOD) % MOD;
}


int powm(int a, int b) {
    int cur = a;
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mul(res, cur);
        }   
        cur = mul(cur, cur);
        b >>= 1;
    }
    return res;
}


void FFT(vector<ll> &a,int n,ll op){
    for (int i=0;i<n;i++) if (i<rev[i]) swap(a[i],a[rev[i]]);
    for (int i=1;i<n;i<<=1){
        ll wn=powm(G,(MOD-1)/i>>1);
        if (op) wn=powm(wn,MOD-2);
        for (int j=0;j<n;j+=i<<1){
            ll w=1;
            for (int k=j;k<j+i;k++,w=1ll*w*wn%MOD){
                ll x=a[k],y=1ll*w*a[k+i]%MOD;
                a[k]=(x+y)%MOD;a[k+i]=(x-y + MOD)%MOD;
            }
        }
    }
    if (op){
        ll invn=powm(n,MOD-2);
        for (int i=0;i<n;i++) a[i]=1ll*a[i]*invn%MOD;
    }
}

vector<ll> multiply(vector<ll> a, vector<ll> b) {
    int n = max(sz(a), sz(b));
    int ns=1,len=0,m=n * 2;
    for (;ns<=m;len++) ns<<=1;
    for (int i=1;i<ns;i++) {
        rev[i]=rev[i>>1]>>1^((i&1)<<(len-1));
    }
    a.resize(ns);
    b.resize(ns);
    FFT(a,ns,0);
    FFT(b,ns,0);
    for (int i=0;i<ns;i++) a[i] = mul(a[i], b[i]);
    FFT(a,ns,1);
    return a;
}

int n, k;
ll a[MAXN];
ll b[MAXN];


vector<ll> get(int l, int r) {
    if (l == r) {
        vector<ll> res;
        res.resize(2);
        res[0] = 1;
        res[1] = b[l];
        return res;
    }
    vector<ll> f = get(l, (l + r) / 2);
    vector<ll> f1 = get((l + r) / 2 + 1, r);
    vector<ll> g = multiply(f, f1);
    while (!g.empty() && g.back() == 0) {
        g.pop_back();
    }
    return g;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int q;
    cin >> q;
    for (int it = 0; it < q; it++) {
        int t;
        cin >> t;
        if (t == 1) {
            int q, i, d;
            cin >> q >> i >> d;
            int c = a[i];
            a[i] = d;
            for (int i = 1; i <= n; i++) {
                b[i] = (q - a[i]);
                b[i] %= MOD;
                if (b[i] < 0) {
                    b[i] += MOD;
                }
            }
            vector<ll> kek = get(1, n);
            a[i] = c;
            cout << kek[k] << '\n';
        } else {
            int q, l, r, d;
            cin >> q >> l >> r >> d;
            for (int i = l; i <= r; i++) {
                a[i] += d;
            }
            for (int i = 1; i <= n; i++) {
                b[i] = (q - a[i]);
                b[i] %= MOD;
                if (b[i] < 0) {
                    b[i] += MOD;
                }
            }
            vector<ll> kek = get(1, n);
            for (int i = l; i <= r; i++) {
                a[i] -= d;
            }
            cout << kek[k] << '\n';
        }
    }
    return 0; 
}