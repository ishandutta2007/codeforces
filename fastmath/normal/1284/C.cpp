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
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC

const int N = 1e6 + 7;
int f[N];
int MOD;

int mod(int n) {
    n %= MOD;
    if (n < 0)
        return n + MOD;
    else
        return n;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n >> MOD;

    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = mod(f[i - 1] * i);

    int ans = 0;
    for (int len = 1; len <= n; ++len) {
        int cnt = n - len + 1;
        ans = mod(ans + mod(cnt * cnt) * mod(f[len] * f[n - len]));            
    }   
    cout << ans << '\n';
}