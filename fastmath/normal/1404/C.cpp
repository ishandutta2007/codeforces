#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';

const int N = 3e5+7;
const int INF = 1e9+7; // check INF!

struct ST {

int mn[N << 2], sum[N << 2], prop[N << 2];
void gap(int v, int l, int r, int x) {
    mn[v] += x;
    prop[v] += x;
}   
void push(int v, int l, int r) {
    if (prop[v]) {
        int m = (l + r) >> 1;
        gap(v * 2 + 1, l, m, prop[v]);
        gap(v * 2 + 2, m + 1, r, prop[v]);
        prop[v] = 0;
    }   
}
void relax(int v) {
    mn[v] = min(mn[v * 2 + 1], mn[v * 2 + 2]);
    sum[v] = sum[v * 2 + 1] + sum[v * 2 + 2];
}   
int getsum(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl)
        return 0;
    if (l <= tl && tr <= r)
        return sum[v];
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    return getsum(v * 2 + 1, tl, tm, l, r) + getsum(v * 2 + 2, tm + 1, tr, l, r);
}   

void setpoint(int v, int tl, int tr, int i, int mn_x, int sum_x) {
    if (tl == tr) {
        mn[v] = mn_x;
        sum[v] = sum_x;
        return;
    }   
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    if (i <= tm)
        setpoint(v * 2 + 1, tl, tm, i, mn_x, sum_x);
    else
        setpoint(v * 2 + 2, tm + 1, tr, i, mn_x, sum_x);
    relax(v);
}
void add(int v, int tl, int tr, int l, int r, int x) {
    if (tr < l || r < tl)
        return;
    if (l <= tl && tr <= r) {
        gap(v, tl, tr, x);
        return;
    }   
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    add(v * 2 + 1, tl, tm, l, r, x);
    add(v * 2 + 2, tm + 1, tr, l, r, x);
    relax(v);                
}   
  
void build(int v, int tl, int tr) {
    if (tl == tr) {
        mn[v] = INF;
        sum[v] = 0;
        return;
    }   
    int tm = (tl + tr) >> 1;
    build(v * 2 + 1, tl, tm);
    build(v * 2 + 2, tm + 1, tr);
    relax(v);
}   
int getsum(int l, int r) {
    return getsum(0, 0, N - 1, l, r);
}   
void setpoint(int i, int mn_x, int sum_x) {
    setpoint(0, 0, N - 1, i, mn_x, sum_x);
}
void build() {
    build(0, 0, N - 1);
}   
int find_right(int v, int tl, int tr) {
    assert(mn[v] == 0);
    if (tl == tr)
        return tr;
    int tm= (tl + tr) >> 1;
    push(v, tl, tr);
    if (mn[v * 2 + 2] == 0)
        return find_right(v * 2 + 2, tm + 1, tr);
    else
        return find_right(v * 2 + 1, tl, tm);
}   
int find_right() {
    return find_right(0, 0, N - 1);
}
//build with range 0..N!

void add(int l, int r, int x) {
    add(0, 0, N - 1, l, r, x);
}   

} t;  


signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif
    int n, q;
    cin >> n >> q;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }   

    vector <vector <ii> > d(n + 1);
    vector <int> ans(q);
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        int l = x + 1;
        int r = n - y;
        d[l].app(mp(r, i));
    }
    
    t.build();
    for (int l = n; l; --l) {
        if (a[l] <= l) {
            t.setpoint(l, l - a[l], 0);
        }   
        while (t.mn[0] == 0) {
            int pos = t.find_right();
            t.setpoint(pos, INF, 1);
            t.add(pos + 1, n, -1);
        }   
        for (auto e : d[l]) {
            int r = e.f, i = e.s;
            ans[i] = t.getsum(l, r);
        }   
    }   

    for (auto e : ans)
        cout << e << endl;
}