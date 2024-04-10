#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;
int n, m, s;
struct Bug {
    int x, i;
};
struct Student {
    int x, c, i;
};  
Bug a[N];
Student b[N];
int tree[N << 2];
bool comp1(Bug a, Bug b) {
    return a.x < b.x;
}   
bool comp2(Student a, Student b) {
    return a.x < b.x;
}   
int mmin(int i, int j) {
    if (i == -1) return j;
    if (j == -1) return i;
    if (b[i].c < b[j].c) return i;
    else return j;
}   
void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = tl;
        return;
    }   
    int tm = (tl + tr) >> 1;
    build(v * 2 + 1, tl, tm); build(v * 2 + 2, tm + 1, tr);
    tree[v] = mmin(tree[v * 2 + 1], tree[v * 2 + 2]);
}   
int get(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return -1;
    if (l <= tl && tr <= r) return tree[v];
    int tm = (tl + tr) >> 1;
    return mmin(get(v * 2 + 1, tl, tm, l, r), get(v * 2 + 2, tm + 1, tr, l, r));
}   
void del(int v, int tl, int tr, int p) {
    if (tl == tr) {
        tree[v] = -1;
        return;
    }   
    int tm = (tl + tr) >> 1;
    if (p <= tm) del(v * 2 + 1, tl, tm, p);
    else del(v * 2 + 2, tm + 1, tr, p);
    tree[v] = mmin(tree[v * 2 + 1], tree[v * 2 + 2]);
}   
bool check(int t) {
    build(0, 0, n - 1);
    int ptr = m - 1;
    int w = 0;
    while (ptr >= 0) {
        int l = -1, r = n;
        while (l < r - 1) {
            int m = (l + r) >> 1;
            if (b[m].x < a[ptr].x) l = m;
            else r = m;
        }   
        int p = get(0, 0, n - 1, r, n - 1);
        if (p == -1) return 0;
        del(0, 0, n - 1, p);
        w += b[p].c;
        ptr -= t;
    }   
    return w <= s;
}
int ans[N];   
void print(int t) {
    build(0, 0, n - 1);
    int ptr = m - 1;
    while (ptr >= 0) {
        int l = -1, r = n;
        while (l < r - 1) {
            int m = (l + r) >> 1;
            if (b[m].x < a[ptr].x) l = m;
            else r = m;
        }   
        int p = get(0, 0, n - 1, r, n - 1);
        del(0, 0, n - 1, p);        
        for (int i = ptr; i >= max(0ll, ptr - t + 1); --i) {
            ans[a[i].i] = b[p].i;
        }   
        ptr -= t;
    }   
    cout << "YES\n";
    for (int i = 0; i < m; ++i) {
        cout << ans[i] + 1 << ' ';
    }   
    cout << '\n';
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m >> s;
    for (int i = 0; i < m; ++i) {
        cin >> a[i].x;
        a[i].i = i;
    }   
    for (int i = 0; i < n; ++i) {
        cin >> b[i].x;
    }   
    for (int i = 0; i < n; ++i) {
        cin >> b[i].c;
        b[i].i = i;
    }   
    sort(a, a + m, comp1);
    sort(b, b + n, comp2);
    int l = 0;
    int r = N;
    while (l < r - 1) {
        int m = (l + r) >> 1;
        if (check(m)) r = m;
        else l = m;
    }   

    if (r == N) {
        cout << "NO\n";
        exit(0);
    }   

    print(r);
}