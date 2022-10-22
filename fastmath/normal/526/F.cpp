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
const int N = 1e6+7;
struct Node {
    int l, r;
    int mn, mx;
    int type;
    //type 1 : 1, 2, 3..n
    bool check() {
        return r - l + 1 == mx - mn + 1;
    }
    void print() {
        cout << "Node " << endl;
        cout << "l, r : " << l << ' ' << r << endl;
        cout << "mn, mx " << mn << ' ' << mx << endl;
        cout << "type " << type << endl;
    }   
} d[N];  
void domn(int &a, int b) { a = min(a, b); }
void domx(int &a, int b) { a = max(a, b); }
Node merge(Node a, Node b) {
    domn(a.l, b.l);
    domx(a.r, b.r);
    domn(a.mn, b.mn);
    domx(a.mx, b.mx);
    a.type = 0;
    return a;
}   
vector <int> tree[N];
bool check(int u, int v) {
    return merge(d[u], d[v]).check();
}

int ans = 0;
void dfs(int u) {
    bool join = 1;
    for (int i = 0; i + 1 < tree[u].size(); ++i) {
        join &= check(tree[u][i], tree[u][i+1]);
    }
    if (join && tree[u].size()) {
        int k = tree[u].size();
        ans += k * (k - 1) / 2;        
    }   
    else {
        ans += 1;
    }   
    for (int v : tree[u]) {
        dfs(v);
    }
}   

struct Tree {

int add[N << 2], tree[N << 2];
void gap(int v, int x) {
    tree[v] += x;
    add[v] += x;
}   
void push(int v) {
    if (add[v]) {
        gap(v * 2 + 1, add[v]);
        gap(v * 2 + 2, add[v]);
        add[v] = 0;
    }   
}   
void relax(int v) {
    tree[v] = min(tree[v * 2 + 1], tree[v * 2 + 2]);
}
void build(int v, int tl, int tr) {
    tree[v] = (-N) - N + add[v];

    if (tl == tr)
        return;

    int tm = (tl + tr) >> 1;
    build(v * 2 + 1, tl, tm);
    build(v * 2 + 2, tm + 1, tr);
}
void shift(int v, int tl, int tr, int l, int r, int x) {
    if (tr < l || r < tl)
        return;
    if (l <= tl && tr <= r) {
        gap(v, x);
        return;
    }   
    int tm = (tl + tr) >> 1;
    push(v);
    shift(v * 2 + 1, tl, tm, l, r, x);
    shift(v * 2 + 2, tm + 1, tr, l, r, x);
    relax(v);
}   
int getmin(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl)
        return N;
    if (l <= tl && tr <= r)
        return tree[v];
    int tm = (tl + tr) >> 1;
    push(v);
    return min(getmin(v * 2 + 1, tl, tm, l, r), getmin(v * 2 + 2, tm + 1, tr, l, r));
}   
void shift(int l, int r, int x) {
    shift(0, 0, N, l, r, x);
}   
int get(int l, int r) {
    return getmin(0, 0, N, l, r);
}   

} mag;

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    vector <int> p(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        p[x - 1] = y - 1;
    }
    mag.build(0, 0, N);
    vector <int> s;   
    vector <int> mn = {-1}, mx = {-1};
    int ptr = 0;
    for (int i = 0; i < n; ++i) {
        {
        mag.shift(i, i, -(p[i]-N));
        while (mn.back()!= -1 && p[i] <= p[mn.back()]) {
            int r = mn.back();
            int was = p[mn.back()];
            mn.pop_back();
            mag.shift(mn.back()+1, r, -(p[i]-was));
        }
        mn.app(i);
        }

        {
        mag.shift(i, i, p[i]-(-N));
        while (mx.back()!= -1 && p[i] >= p[mx.back()]) {
            int r = mx.back();
            int was = p[mx.back()];
            mx.pop_back();
            mag.shift(mx.back()+1, r, p[i]-was);
        }
        mx.app(i);
        }
            
        mag.shift(0, i - 1, -1);

        int u = ptr++;
        d[u] = {i, i, p[i], p[i], 0};

        while (mag.get(0, d[u].l - 1) == 0) {
            if (s.size() && tree[s.back()].size() && check(s.back(), u)) {
                if ((d[s.back()].type == 1 && d[u].mn > d[s.back()].mn) || (d[s.back()].type == 2 && d[u].mn < d[s.back()].mn)) {
                    tree[s.back()].app(u);
                    int tp = d[s.back()].type;
                    d[s.back()] = merge(d[s.back()], d[u]);
                    d[s.back()].type = tp;
                    u = s.back();
                    s.pop_back();
                }   
                else {
                    int add = ptr++;
                    d[add] = merge(d[s.back()], d[u]);

                    if (d[s.back()].mn < d[u].mn)
                        d[add].type = 1;
                    else
                        d[add].type = 2;

                    tree[add].app(s.back());
                    tree[add].app(u);
                    s.pop_back();
                    u = add;
                }
                continue;
            }   

            int sz = s.size();
            int p = -1;
            Node cur = d[u];
            for (int j = sz - 1; j >= 0; --j) {
                cur = merge(cur, d[s[j]]);    
                if (cur.check()) {
                    p = j;
                    break;
                }   
            }
            if (p == -1)
                break;

            tree[ptr].app(u);
            while (s.size() > p) {
                tree[ptr].app(s.back());
                s.pop_back();
            }
            reverse(all(tree[ptr]));

            bool join1 = 1;
            for (int j = 0; j + 1 < tree[ptr].size(); ++j)
                join1 &= d[tree[ptr][j]].mx + 1 == d[tree[ptr][j + 1]].mn;
            if (join1)
                cur.type = 1;

            bool join2 = 1;
            for (int j = 0; j + 1 < tree[ptr].size(); ++j)
                join2 &= d[tree[ptr][j]].mn - 1 == d[tree[ptr][j + 1]].mx;
            if (join2)
                cur.type = 2;

            u = ptr++;
            d[u] = cur;
        }   
        s.app(u);
    }

    int root = s[0];
    dfs(root);
    cout << ans << endl;
}