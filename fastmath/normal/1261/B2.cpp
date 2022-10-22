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

int cnt[N << 2];
void add(int v, int tl, int tr, int p) {
    ++cnt[v];
    if (tl == tr) return;
    int tm = (tl + tr) >> 1;
    if (p <= tm) return add(v * 2 + 1, tl, tm, p);
    else add(v * 2 + 2, tm + 1, tr, p);
}   
int getk(int v, int tl, int tr, int k) {
    if (tl == tr) return tl;
    int tm = (tl + tr) >> 1;
    if (k <= cnt[v * 2 + 1]) return getk(v * 2 + 1, tl, tm, k);
    else return getk(v * 2 + 2, tm + 1, tr, k - cnt[v * 2 + 1]);
}

vector <ii> mem[N];

int n;
int a[N], ans[N];
vector <int> p[N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    vector <int> c;
    for (int i = 0; i < n; ++i) { cin >> a[i]; c.app(a[i]); }
    sort(all(c)); c.resize(unique(all(c)) - c.begin());
    for (int i = 0; i < n; ++i) a[i] = lb(all(c), a[i]) - c.begin();
    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int k, pos; cin >> k >> pos;
        mem[k].app(mp(pos, i));
    }   
    for (int i = 0; i < n; ++i) p[a[i]].app(i);
    int cur = 0;
    for (int i = N - 1; i >= 0; --i) 
        for (int j : p[i]) {
            add(0, 0, n - 1, j);
            ++cur;
            for (auto e : mem[cur]) {
                ans[e.s] = getk(0, 0, n - 1, e.f);
            }   
        }   
    for (int i = 0; i < q; ++i) cout << c[a[ans[i]]] << '\n';
}