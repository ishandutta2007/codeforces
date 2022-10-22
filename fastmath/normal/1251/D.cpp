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
void solve() {
    int n, S;
    cin >> n >> S;
    vector <ii> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i].f >> a[i].s;
    sort(all(a));
    reverse(all(a));
    int l = 0, r = 1e10;
    int w = n / 2 + 1;
    while (l < r - 1) {
        int m = (l + r) >> 1;

        int k = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            auto e = a[i];
            if (k < w && e.s >= m) {
                ++k;
                sum += max(m, e.f);
            }   
            else {
                sum += e.f;
            }   
        }

        if (k >= w && sum <= S)
            l = m;
        else
            r = m;
    }           
    cout << l << endl;
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