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
const int N = 51;
int cnt[N];
void solve() {
    for (int i = 0; i < N; ++i)
        cnt[i] = 0;

    int d, MOD;
    cin >> d >> MOD;
 
    int r = -1;
    for (int i = 0; i < N; ++i)
        if ((d >> i) & 1)
            r = i;
 
    
    for (int i = 0; i < N; ++i) {
        if (i < r) {
            cnt[i] = 1ll << i;
        }   
        else if (i == r) {
            cnt[i] = d - (1ll << i) + 1;
        }   
        cnt[i] %= MOD;
    }   
    int ans = 1;
    for (int i = 0; i < N; ++i)
        ans = (ans * (cnt[i] + 1)) % MOD;
    cout << (ans + MOD - 1) % MOD << endl;
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