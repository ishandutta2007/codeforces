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

const int N = 1e5 + 7;
int seg[N], pref[N];
int get(int n, int i) {
    int l = 0, r = n;
    while (l < r - 1) {
        int m = (l + r) >> 1;
        if (i <= pref[m])
            r = m;
        else
            l = m;
    }   
    if (r == n) {
        return 1;
    }
    else {
        int p = i - pref[r - 1];
        if (p % 2 == 1)
            return r;
        else
            return r + (p / 2);
    }   
}   

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    for (int i = 1; i < n; ++i) {
        seg[i] = 2 * (n - i);
    }   
    seg[n] = 1;

    for (int i = 1; i <= n; ++i)
        pref[i] = pref[i - 1] + seg[i];

    for (int i = l; i <= r; ++i)
        cout << get(n, i) << ' ';
    cout << endl;            
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
    while (t--) {
        solve();
    }   
}