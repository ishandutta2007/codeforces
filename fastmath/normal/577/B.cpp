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
bitset <2007> dp, mem;
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        mem[i] = 1;
    dp[0] = 1;
    while (n--) {
        int x;
        cin >> x;
        dp |= dp << (x % m);

        if (dp[m] || (x % m == 0)) {
            cout << "YES\n";
            exit(0);
        }   

        dp |= dp >> m;
        dp &= mem;
    }   
    cout << "NO\n";
}