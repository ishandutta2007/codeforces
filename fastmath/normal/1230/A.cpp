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
const int C = 1001;
bitset <C> dp;
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n = 4;
    int sum = 0;
    dp[0] = 1;
    for (int i = 0; i < 4; ++i) {
        int x; cin >> x;
        sum += x; dp |= dp << x;           
    }   
    if (sum & 1) cout << "NO\n";
    else if (dp[sum >> 1]) cout << "YES\n";
    else cout << "NO\n";
}