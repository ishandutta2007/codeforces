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
const int N = 1e5 + 7;
int a[N];
int cnt[N], cc[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n; cin >> n;
    set <int> ms;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ms.insert(a[i]);
    }
    int all = ms.size();
    int mx = 0;
    int ans = 1;
    cc[0] = all;
    for (int i = 0; i < n; ++i) {
        --cc[cnt[a[i]]];
        ++cnt[a[i]];
        ++cc[cnt[a[i]]];
        mx = max(mx, cnt[a[i]]);
        if (mx > 1 && cc[0] + cc[mx - 1] == all - 1) {
            ans = max(ans, i + 1);
        }   
        if (mx == 1) {
            ans = max(ans, i + 1);
        }
        if (cc[1] == 1 && cc[0] + cc[mx] == all - 1) {
            ans = max(ans, i + 1);
        }   
    }
    cout << ans << '\n';
}