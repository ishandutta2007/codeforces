#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define f first
#define s second
#define bp __builtin_popcount
#define all(a) a.begin(),a.end()
#define ll long long
#define mp make_pair
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    map <int, int> d;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        d[x - i] += x;
    }   
    int ans = 0;
    for (auto e : d)
        ans = max(ans, e.s);
    cout << ans << endl;
}