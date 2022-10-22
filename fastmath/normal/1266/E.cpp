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
const int N = 2e5 + 7;
int n, q, a[N], cnt[N];
int sum = 0;
void dec(int i) {
    sum -= min(a[i], cnt[i]);
    --cnt[i];
    sum += min(a[i], cnt[i]);
}   
void inc(int i) {
    sum -= min(a[i], cnt[i]);
    ++cnt[i];
    sum += min(a[i], cnt[i]);
}
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    int all = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        all += a[i];
    }
    cin >> q;
    map <ii, int> d;
    while (q--) {
        int s, t, u;
        cin >> s >> t >> u;
        if (d.find(mp(s, t)) != d.end()) {
            dec(d[mp(s, t)]);
            d.erase(mp(s, t));
        }   
        if (u) {
            inc(u);
            d[mp(s, t)] = u;
        }
        cout << all - sum << '\n';
    }               
}