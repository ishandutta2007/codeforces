#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
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


void add(int &a, int b) { a = mod(a + b); }

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n, m;
    cin >> n >> m;

    const int INF = 2e9;

    vector <int> a(n), b(m);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector <ii> lf(n + 1, mp(INF, INF)), rf(n + 1, mp(INF, INF));
    for (int i = n - 1; i >= 0; --i) {
        lf[i] = lf[i + 1];
        if (a[i] <= lf[i].f)
            lf[i] = mp(a[i], i);
        
        rf[i] = rf[i + 1];
        if (a[i] < rf[i].f)
            rf[i] = mp(a[i], i);
    }   

    for (int i = 0; i < m; ++i)
        cin >> b[i];        

    int ans = 1, l = 0;
    bool first = 1;
    for (int x : b) {

        while (lf[l].f < x)
            ++l;

        if (lf[l].f > x) {
            cout << 0 << endl;
            exit(0);
        }   

        int r = rf[l].s;

        if (first && l) {
            cout << 0 << endl;
            exit(0);
        }   

        if (!first) {
            ans = mod(ans * (r - l + 1));
        }
        l = r + 1;
        first = 0;
    }   
    cout << ans << endl;
}