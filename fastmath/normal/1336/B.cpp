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

const int INF = 5e18;

int kv(int x) {
    return x * x;
}   

int get(vector <int> &mid, vector <int> &l, vector <int> &r) {
    int ans = INF;
    for (int x : mid) {
        int xl = upper_bound(all(l), x) - l.begin() - 1;
        if (xl == -1)
            continue;
        int xr = lower_bound(all(r), x) - r.begin();
        if (xr == r.size())
            continue;

        xl = l[xl];
        xr = r[xr];
        ans = min(ans, kv(x - xl) + kv(x - xr) + kv(xl - xr));            
    }   
    return ans;
}   

void solve() {
    int n[3];
    vector <int> a[3];
    for (int i = 0; i < 3; ++i) {
        cin >> n[i];
        a[i].resize(n[i]);
    }
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < n[i]; ++j)
            cin >> a[i][j];

    for (int i = 0; i < 3; ++i)
        sort(all(a[i]));

    vector <int> per = {0, 1, 2};
    int ans = INF;
    do {
        ans = min(ans, get(a[per[0]], a[per[1]], a[per[2]]));
    } while (next_permutation(all(per)));                
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