#include<bits/stdc++.h>
using namespace std;
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

const int N = 1e6+7;
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
        mn[v] = mx[v] = sum[v] = x;
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
void build(int v, int tl, int tr, vector <ii> &a) {
    if (tl == tr) {
        if (tl < a.size()) {
            mn[v] = mx[v] = sum[v] = a[tl].s;
        }
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
void build(vector <ii> &a) {
    build(0, 0, N, a);
}   
//build with range 0..N!

int get_left(int v, int tl, int tr, int l, int w) {
    if (tr < l || mx[v] < w)
        return -1;
    if (tl == tr)
        return tl;
    int tm = (tl + tr) >> 1;
    int t = get_left(v * 2 + 1, tl, tm, l, w);
    if (t != -1)
        return t;
    else
        return get_left(v * 2 + 2, tm + 1, tr, l, w);                                    
}   
int get_left(int l, int w) {
    return get_left(0, 0, N, l, w);
}

} ta, tb;  


signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    string a = s, b = s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') {
            a[i] = '0';
            b[i] = '1';
        }   
    }   
    auto get = [&] (string s, char c) {
        int cur = 0;
        vector <ii> a;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != c) {
                if (cur)
                    a.app(mp(i - 1, cur));
                cur = 0;
            }   
            else {
                cur++;
            }   
        }   
        if (cur)
            a.app(mp((int)s.size() - 1, cur));
        return a;
    };  
    vector <ii> as = get(a, '0'), bs = get(b, '1');
    ta.build(as);
    tb.build(bs);
    for (int x = 1; x <= n; ++x) {
        int ans = 0, ptr = 0;
        auto get_link = [&] (vector <ii> &a, ST &tree) {
            auto t = lower_bound(all(a), mp(ptr, 0));
            if (t == a.end())
                return n + 1;
            if (max(ptr, t->f - t->s + 1) + x - 1 <= t->f) {
                return max(ptr, t->f - t->s + 1) + x;
            }
            int l = tree.get_left(t - a.begin() + 1, x);
            if (l == -1)
                return n + 1;
            int lf = a[l].f - a[l].s + 1;
            return lf + x;
        };
        while (1) {
            /*
            cout << ptr << ' ' << ans << endl;
            cout << get_link(bs, tb) << endl;
            exit(0);
            */
            int to = min(get_link(as, ta), get_link(bs, tb));
            if (to == n + 1)
                break;
            ptr = to;
            ans++;
        }   
        cout << ans << ' ';
    }   
    cout << endl;
}