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
#define y0 lmao
const int INF = 5e16;

int x0, y0, ax, ay, bx, by, x, y, t;
int dist(ii a, ii b) {
    return abs(a.f - b.f) + abs(a.s - b.s);
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> x0 >> y0 >> ax >> ay >> bx >> by >> x >> y >> t;

    vector <ii> a;
    a.app(mp(x0, y0));
    while (1) {
        auto p = mp(a.back().f * ax + bx, a.back().s * ay + by);
        if (p.f > INF || p.s > INF)
            break;
        a.app(p);
    }       
    /*        
    for (auto e : a)
        cout << e.f << ' ' << e.s << '\n';
    */
    int n = a.size();
    int ans = 0;

    ii S = mp(x, y);

    for (int l = 0; l < n; ++l) {
        for (int r = l; r < n; ++r) {

            int d = 0;
            for (int i = l; i + 1 <= r; ++i) {
                d += dist(a[i], a[i + 1]);
            }   
            d += min(dist(S, a[l]), dist(S, a[r]));

            if (d <= t)
                ans = max(ans, r - l + 1);
        }   
    }   
    cout << ans << '\n';
}