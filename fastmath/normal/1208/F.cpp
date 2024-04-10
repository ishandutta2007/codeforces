#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
const int LG = 21, N = 1e6 + 7;
ii r[1 << LG];
int n, a[N];
void add(ii &p, int i) {
    if (i == p.first || i == p.second) return;
    if (i > p.first) p = {i, p.first};
    else if (i > p.second) p = {p.first, i};
}
void add(ii &l, ii r) { add(l, r.first); add(l, r.second); }
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) add(r[a[i]], i);
    for (int m = (1 << LG) - 1; m >= 0; --m) {
        for (int i = 0; i < LG; ++i) {
            if (!((m >> i) & 1)) add(r[m], r[m + (1 << i)]);
        }
    }
    int ans = 0;
    for (int i = 0; i + 2 < n; ++i) {
        int p = 0;
        for (int b = LG - 1; b >= 0; --b) {
            if ((a[i] >> b) & 1) continue;
            if (r[p + (1 << b)].second > i) p += 1 << b;
        }        
        ans = max(ans, a[i] | p);
    }
    cout << ans << '\n';
}