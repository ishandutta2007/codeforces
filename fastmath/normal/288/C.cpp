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
const int N = 1e6 + 7;
int ans[N];
void solve(int n) {
    if (n < 1)
        return;    
    int mx = 0;
    while ((1 << (mx + 1)) <= n)
        ++mx;
    int l = (1 << mx) - 1;
    for (int i = (1 << mx); i <= n; ++i) {
        ans[i] = l;
        ans[l] = i;
        --l;
    }   
    solve(l);
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    cout << n * (n + 1) << endl;
    solve(n);
    for (int i = 0; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << endl;                        
}