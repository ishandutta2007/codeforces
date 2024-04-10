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
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 2e5 + 7, MOD = 998244353;
int a[N], b[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    vector <int> f;
    for (int i = 0; i < n; ++i) {
        f.app((i + 1) * (n - i) * a[i]);
    }   
    sort(all(f));
    sort(b, b + n);
    reverse(b, b + n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = (ans + b[i] * (f[i] % MOD)) % MOD;
    }
    cout << ans << '\n';            
}