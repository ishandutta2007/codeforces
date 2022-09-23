//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf_int = 1e9 + 100;
const ll inf_ll = 1e18;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double dbl;
#define pb push_back
#define eb emplace_back
const double pi = 3.1415926535898;
#define dout if(debug) cout
#define fi first
#define se second
#define sp setprecision
#define sz(a) (int(a.size()))
#define mp make_pair
#define all(a) a.begin(),a.end()
bool debug = 0;
const int MAXN = 2e5 + 100;
const int LOG = 21;
const int mod = 998244353;
const int MX = (1e7 + 100) * 1.5;
typedef long long li;

template<class T1, class T2>
std::ostream &operator<<(std::ostream &out, const std::pair<T1, T2> &rhs) {
    out << "( " << rhs.first << " , " << rhs.second << " )";
    return out;
}

ll a[MAXN];
ll b[MAXN];
int n, k;


using ll = long long;
const ll MOD = 998244353;

ll mul(ll a, ll b) {
    a = a * b % MOD;
    return a;
}

ll add(ll a, ll b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    } else if (a < 0) {
        a += MOD;
    }
    return a;
}

ll pw(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

struct NTT {
    NTT(int n) : tail(n) {
        LG = close_lg(n);
        for (int i = 1; i < n; ++i) {
            tail[i] = ((i & 1) << (LG - 1)) | (tail[i >> 1] >> 1);
        }
    }

    int close_lg(int n) {
        int res = 0;
        while (1 << res < n) {
            ++res;
        }
        return res;
    }

    void ntt(vector<ll> &a, bool invert) {
        int n = a.size();
        int k = close_lg(n);
        for (int i = 0; i < n; ++i) {
            int cur_tail = tail[i] >> (LG - k);
            if (cur_tail < i) {
                swap(a[i], a[cur_tail]);
            }
        }
        for (int len = 2; len <= n; len <<= 1) {
            int half = len >> 1;
            int root = pw(3, (MOD - 1) / len);
            for (int bl = 0; bl < n; bl += len) {
                int cur = 1;
                for (int i = bl; i < bl + half; ++i) {
                    ll u = a[i];
                    ll v = mul(a[i + half], cur);
                    a[i] = add(u, v);
                    a[i + half] = add(u, MOD - v);
                    cur = mul(cur, root);
                }
            }
        }
        if (invert) {
            ll inv = pw(n, MOD - 2);
            for (int i = 0; i < n; ++i) {
                a[i] = mul(a[i], inv);
            }
            reverse(a.begin() + 1, a.end());
        }
    }

    vector<int> tail;
    int LG;
};

vector<ll> mul2(vector<ll> a, vector<ll> b) {
    int n = sz(a);
    int m = sz(b);
    vector<ll> res(n + m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            res[i + j] += (a[i] * b[j]) % mod;
            if (res[i + j] >= mod)
                res[i + j] -= mod;
        }
    }
    return res;
}

vector<ll> mul(vector<ll> a, vector<ll> b, NTT &ntt) {
    ll size = 1 << ntt.close_lg(a.size() + b.size());
    a.resize(size);
    b.resize(size);
    ntt.ntt(a, false);
    ntt.ntt(b, false);
    for (int i = 0; i < a.size(); ++i) {
        a[i] = mul(a[i], b[i]);
    }
    ntt.ntt(a, true);
    return a;
}

vector<ll> solve(int l, int r, NTT &ntt) {
    int len = r - l + 1;

    if (l == r) {
        vector<ll> res(2);
        res[0] = 1;
        res[1] = b[l];
        return res;
    } else {
        int tm = (l + r) >> 1;
        vector<ll> res1 = solve(l, tm, ntt);
        vector<ll> res2 = solve(tm + 1, r, ntt);

        vector<ll> res = mul(res1, res2, ntt);
        res[0] = 1;
        return res;
    }
}

void solve() {

    NTT ntt(1 << 20);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }


    int qq;
    cin >> qq;
    for (int j = 1; j <= qq; ++j) {
        int t;
        cin >> t;
        int q;
        cin >> q;
        for (int i = 1; i <= n; ++i) {
            b[i] = a[i];
        }
        if (t == 1) {
            int pos, d;
            cin >> pos >> d;
            b[pos] = d;
        } else {
            int l, r, d;
            cin >> l >> r >> d;
            for (int i = l; i <= r; ++i) {
                b[i] += d;
            }
        }
        for (int i = 1; i <= n; ++i) {
            b[i] = q - b[i];
             b[i] = (b[i] % mod + mod) % mod;
        }

        vector<ll> res = solve(1, n, ntt);
        if (sz(res) <= k) {
            cout << 0 << "\n";
        } else {
            cout << res[k] << "\n";
        }
    }
}

signed main() {
#ifdef zxc
    debug = 0;
    freopen("../input.txt", "r", stdin);
    //  freopen("../output.txt", "w", stdout);
#else

#endif //zxc
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(20);

    int t = 1;
    while (t--)
        solve();
    if (debug)
        cerr << endl << "time : " << (1.0 * clock() / CLOCKS_PER_SEC) << endl;
}