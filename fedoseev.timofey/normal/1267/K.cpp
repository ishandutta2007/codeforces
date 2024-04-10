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
const int C = 30;
int cnt[C];
int get(vector <int> a) {
    int sz = a.size();
    int ans = 1;
    for (int i = 1; i <= sz; ++i) {
        int l = ub(all(a), i) - a.begin();
        ans *= l - (i - 1);
    }   

    for (int i = 0; i < C; ++i)
        cnt[i] = 0;
    for (int e : a)
        ++cnt[e];
    for (int i = 0; i < C; ++i)
        for (int j = 1; j <= cnt[i]; ++j) 
            ans /= j;

    return ans;
}   
void solve() {
    int n; cin >> n;
    vector <int> a;
    for (int i = 2; n; ++i) {
        a.app(n % i);
        n /= i;
    }   
    sort(all(a));
    int ans = get(a);
    if (a[0] == 0) {
        vector <int> t;
        for (int i = 1; i < a.size(); ++i) t.app(a[i]);
        ans -= get(t);
    }   
    cout << ans - 1 << '\n';
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t; cin >> t;
    while (t--) solve();
}