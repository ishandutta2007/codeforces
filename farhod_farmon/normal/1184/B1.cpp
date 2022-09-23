#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
const double pi = 3.1415926535898;
#define dout if(debug) cout
#define fi first
#define se second
#define sp setprecision
#define sz(a) (int(a.size()))
#define all(a) a.begin(),a.end()
bool debug = 0;
const int MAXN = 1e6 + 100;
const int LOG = 25;
const int mod = 1e9 + 7;
const int MX = 1e6 + 100;
typedef long long li;
const li MOD = 1000000000949747713ll;


int val[MAXN];
void solve() {
    int s,b;
    cin >> s >> b;
    for(int i=1;i<=s;++i){
        cin >> val[i];
    }
    vector<pll> a;
    for(int i = 1;i<=b;++i){
        int d,g;
        cin >> d >> g;
        a.pb({d,g});
    }
    sort(all(a));

    for(int i = 0;i<sz(a);++i){
        if(i > 0){
            a[i].se += a[i-1].se;
        }
    }

    for(int i = 1;i<=s;++i){
        int l = 0, r = sz(a) - 1;
        int ans = -1;
        while(l<=r){
            int mid = (l+r)>>1;
            if(a[mid].fi <= val[i]){
                ans = mid;
                l = mid+1;
            } else{
                r = mid-1;
            }
        }
        if(ans == -1){
            cout << 0;
        } else{
            cout << a[ans].se;
        }
        cout <<" ";
    }
}

signed main() {
#ifdef zxc
    debug = 1;
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#else
    //freopen("roboherd.in", "r", stdin);
    //freopen("roboherd.out", "w", stdout);

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