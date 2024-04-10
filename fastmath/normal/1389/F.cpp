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

const int N = 4e5+7;

struct ST {

const int INF = 1e9+7; // check INF!

int mn[N << 2], mx[N << 2], prop[N << 2], sum[N << 2];
void gap(int v, int l, int r, int x) {
    mn[v] += x;
    mx[v] += x;
    sum[v] += (r - l + 1) * x;
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
    mx[v] = max(mx[v * 2 + 1], mx[v * 2 + 2]);
    sum[v] = sum[v * 2 + 1] + sum[v * 2 + 2];
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
int getmin(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl)
        return INF;
    if (l <= tl && tr <= r)
        return mn[v];
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    return min(getmin(v * 2 + 1, tl, tm, l, r), getmin(v * 2 + 2, tm + 1, tr, l, r));
}   
int getmax(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl)
        return -INF;
    if (l <= tl && tr <= r)
        return mx[v];
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    return min(getmax(v * 2 + 1, tl, tm, l, r), getmax(v * 2 + 2, tm + 1, tr, l, r));
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
void setpoint(int v, int tl, int tr, int i, int x) {
    if (tl == tr) {
        if (x > mx[v]) {
            mn[v] = mx[v] = sum[v] = x;
        }
        return;
    }   
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    if (i <= tm)
        setpoint(v * 2 + 1, tl, tm, i, x);
    else
        setpoint(v * 2 + 2, tm + 1, tr, i, x);
    relax(v);
}   
void build(int v, int tl, int tr, int *a) {
    if (tl == tr) {
        mn[v] = mx[v] = sum[v] = a[tl];
        return;
    }   
    int tm = (tl + tr) >> 1;
    build(v * 2 + 1, tl, tm, a);
    build(v * 2 + 2, tm + 1, tr, a);
    relax(v);
}   
void clear() {
    memset(mx, 0, sizeof mx);
    memset(mn, 0, sizeof mn);
    memset(sum, 0, sizeof sum);
    memset(prop, 0, sizeof prop);
}   
void add(int l, int r, int x) {
    add(0, 0, N, l, r, x);
}   
int getmin(int l, int r) {
    return getmin(0, 0, N, l, r);
}   
int getmax(int l, int r) {
    return getmax(0, 0, N, l, r);
}   
int getsum(int l, int r) {
    return getsum(0, 0, N, l, r);
}   
void setpoint(int i, int x) {
    setpoint(0, 0, N, i, x);
}   

} d[2];  

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    struct Seg {
        int l, r, c;
    };  
    
    int n;
    cin >> n;

    const int INF = 1e9+7;

    vector <Seg> a(n);
    vector <int> c = {-INF};
    for (int i = 0; i < n; ++i) {
        cin >> a[i].l >> a[i].r >> a[i].c;
        c.app(a[i].l);
        c.app(a[i].r);
        --a[i].c;
    }   
    sort(all(c));
    c.resize(unique(all(c)) - c.begin());

    for (int i = 0; i < n; ++i) {
        a[i].l = lower_bound(all(c), a[i].l) - c.begin();
        a[i].r = lower_bound(all(c), a[i].r) - c.begin();
    }   

    auto comp = [] (Seg a, Seg b) {
        return a.r < b.r;
    };

    sort(all(a), comp);
    int ans = 0;
    for (auto e : a) {
        d[e.c ^ 1].add(0, e.l - 1, 1);
        int best = d[e.c ^ 1].getmax(0, N);

        //cout << e.l << ' ' << e.r << ' ' << e.c << " : " << best << endl;

        d[e.c].setpoint(e.r, best);                
        ans = max(ans, best);
    }   
    cout << ans << endl;    
}