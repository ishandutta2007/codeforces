#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));

    int l = 0, cnt = 1, ans = 0;
    while (l < n) {
        int r = l;
        while (r < n && a[r] > cnt) {
            ++r;
            ++cnt;
        }   
        if (r == n)
            break;
        ++ans;
        l = r + 1;
        cnt = 1;            
    }   
    cout << ans << endl;
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