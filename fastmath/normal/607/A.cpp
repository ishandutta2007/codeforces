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
ii a[N];
int to[N], cnt[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> a[i].f >> a[i].s;
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        to[i] = lower_bound(a, a + n, mp(a[i].f - a[i].s, 0ll)) - a - 1;
        if (to[i] == -1)
            cnt[i] = 1;
        else
            cnt[i] = cnt[to[i]] + 1;
        ans = max(ans, cnt[i]);
    }   
    cout << n - ans << endl;   
}