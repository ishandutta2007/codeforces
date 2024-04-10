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
const int MOD = 1000 * 1000 * 1000 + 7;
int mod(int n) { return (n % MOD + MOD) % MOD; }
int fp(int a, int p) {
    int ans = 1;
    for (int i = 0; (1ll << i) <= p; ++i) {
        if ((p >> i) & 1) ans = mod(ans * a);
        a = mod(a * a);
    }   
    return ans;
}   
signed main() {
    #ifdef LMAO
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m; cin >> n >> m;
    cout << fp(mod(fp(2, m) - 1), n) << '\n';
}