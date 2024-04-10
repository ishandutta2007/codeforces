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
signed main() {
    #ifdef LMAO
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        for (int i = 0; i <= a; ++i) {
            for (int j = 0; j <= b; ++j) {
                if (i * 2 + j <= b && j * 2 <= c) {
                    ans = max(ans, i + (i * 2 + j) + j * 2);
                }   
            }   
        }   
        cout << ans << '\n';
    }   
}