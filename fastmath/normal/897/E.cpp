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
int n, m, seed, vmax;
int rnd() {
    int ret = seed;
    seed = (seed * 7 + 13) % 1000000007;
    return ret;
}   
int a[N];
int fp(int a, int p, int mod) {    
    int ans = 1, c = a % mod;
    for (int i = 0; (1ll << i) <= p; ++i) {
        if ((p >> i) & 1) ans = (ans * c) % mod;
        c = (c * c) % mod;
    }   
    return ans;
}   
void cut(vector <ii> &a, int l) {
    for (auto e : a) if (e.f == l) return;
    int pos = a.size();
    int x = -1;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i].f > l) {
            pos = i;
            break;
        }   
        else x = a[i].s;
    }
    a.insert(a.begin() + pos, mp(l, x));            
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m >> seed >> vmax;
    for (int i = 1; i <= n; ++i) 
        a[i] = rnd() % vmax + 1;
    vector <ii> d;
    for (int i = 1; i <= n; ++i) 
        d.app(mp(i, a[i]));
    int sum = 0;
    while (m--) {
        int op = rnd() % 4 + 1;
        int l = rnd() % n + 1;
        int r = rnd() % n + 1;
        if (r < l) swap(l, r);

        cut(d, l);
        if (r != n) cut(d, r + 1);

        int x, y;
        if (op == 3) 
            x = rnd() % (r - l + 1) + 1;
        else 
            x = rnd() % vmax + 1;
        if (op == 4) 
            y = rnd() % vmax + 1;

        if (op == 1) {
            for (auto &seg : d) 
                if (l <= seg.f && seg.f <= r)
                    seg.s += x;
        }
        else if (op == 2) {
            vector <ii> d1;
            for (auto seg : d) {
                if (l < seg.f && seg.f <= r) continue;
                if (seg.f == l) d1.app(mp(seg.f, x));
                else d1.app(seg);
            }   
            d = d1;
        }
        else if (op == 3) {
            vector <ii> t;
            for (int i = 0; i < d.size(); ++i) 
                if (l <= d[i].f && d[i].f <= r) 
                    if (i + 1 == d.size())
                        t.app(mp(d[i].s, n - d[i].f + 1));
                    else
                        t.app(mp(d[i].s, d[i + 1].f - d[i].f));
            sort(all(t));
            for (auto e : t)
                if (x <= e.s) {
                    cout << e.f << '\n';
                    break;
                }
                else 
                    x -= e.s;
        }   
        else {
            int ans = 0;
            for (int i = 0; i < d.size(); ++i)
                if (l <= d[i].f && d[i].f <= r) {
                    if (i + 1 == d.size()) 
                        ans += fp(d[i].s, x, y) * (n - d[i].f + 1);
                    else 
                        ans += fp(d[i].s, x, y) * (d[i + 1].f - d[i].f);
                }
            cout << ans % y << '\n';
        }   
    }   
}