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
const int mod = 1e9 + 7;
const int MX = (1e7 + 100) * 1.5;
typedef long long li;
const li MOD = 1000000000949747713ll;

template<class T1, class T2>
std::ostream &operator<<(std::ostream &out, const std::pair<T1, T2> &rhs) {
    out << "( " << rhs.first << " , " << rhs.second << " )";
    return out;
}


int C[MAXN];

void solve() {
    int n, f;
    cin >> n >> f;
    for (int i = 1; i <= n; ++i) {
        cin >> C[i];
    }
    int A;
    cin >> A;
    set<pii> ss;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        ss.insert({x, i});

        while (f < C[i]) {
            if(ss.size() == 0){
                cout << -1;
                return;
            }
            assert(ss.size() > 0);
            ans += ss.begin()->fi;
            ss.erase(ss.begin());
            f += A;
        }
    }
    cout << ans;
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