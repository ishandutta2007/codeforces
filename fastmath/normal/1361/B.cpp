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

const int MOD = 1000 * 1000 * 1000 + 7;
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

const int INF = 1e9 + 7;
int mult(int a, int b) {
    if (a == 0 || b == 0)
        return 0;
    if (a > INF/b)
        return INF;
    else
        return min(INF, a * b);
}   
int inf_fp(int a, int p) {
    if (a == 1)
        return 1;
    else if (p > 20)
        return INF;
    else {
        int ans = 1;
        for (int i = 0; i < p; ++i)
            ans = mult(ans, a);
        return ans;
    }   
}   

void solve() {
    int n, p;
    cin >> n >> p;

    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a)); reverse(all(a));
    
    int finf = 0, rf = 0, pw = 0;
    for (auto k : a) {

        //cout << finf << ' ' << rf << ' ' << pw << endl;

        if (pw > k) {
            int d = pw - k;
            finf = mult(finf, inf_fp(p, d));
            rf = rf * fp(p, d) % MOD;
            pw = k;
        }
        
        if (finf == 0) {
            finf = rf = 1;
            pw = k;
        }   
        else {
            rf = mod(rf - 1);
            --finf;
        }   
    }   

    cout << mod(rf * fp(p, pw)) << endl;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--)
        solve();
}