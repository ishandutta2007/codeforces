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
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n; cin >> n;
    int ans = 0;
    set <int> ms;
    n <<= 1;
    while (n--) {
        int x; cin >> x;
        if (ms.find(x) == ms.end()) 
            ms.insert(x);
        else 
            ms.erase(x);
        ans = max(ans, (int)ms.size());
    }   
    cout << ans << '\n';
}