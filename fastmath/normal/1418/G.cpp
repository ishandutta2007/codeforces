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

const int N = 1e6+7;
int cur[N];
int n;

ii mx[N << 2];
int prop[N << 2];
void relax(int v) {
    if (mx[v * 2 + 1].f == mx[v * 2 + 2].f) {
        mx[v] = mx[v * 2 + 1];
        mx[v].s += mx[v * 2 + 2].s;
    }   
    else {
        mx[v] = max(mx[v * 2 + 1], mx[v * 2 + 2]);
    }
}
void gap(int v, int x) {
    mx[v].f += x;
    prop[v] += x;
}
void push(int v) {
    gap(v * 2 + 1, prop[v]);
    gap(v * 2 + 2, prop[v]);
    prop[v] = 0;
}   
void add(int v, int tl, int tr, int l, int r, int x) {
    if (tr < l || r < tl)
        return;
    if (l <= tl && tr <= r) {
        gap(v, x);
        return;
    }   
    int tm = (tl + tr) >> 1;
    push(v);
    add(v * 2 + 1, tl, tm, l, r, x);
    add(v * 2 + 2, tm + 1, tr, l, r, x);
    relax(v);
}
void build(int v, int tl, int tr) {
    mx[v].s = tr - tl + 1;
    if (tl == tr) 
        return;
    int tm = (tl + tr) >> 1;
    build(v * 2 + 1, tl, tm);
    build(v * 2 + 2, tm + 1, tr);
}   

/*
void add(int l, int r, int x) {
    for (int i = l; i <= r; ++i)
        cur[i] += x;
}

ii get_max() {
    ii ans = mp(0, 0);
    for (int i = 0; i < n; ++i) {
        if (cur[i] > ans.f)
            ans = mp(cur[i], 1);
        else if (cur[i] == ans.f)
            ans.s++;
    }   
    return ans;
}
*/  

void add(int l, int r, int x) {
    add(0, 0, n - 1, l, r, x);
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    cin >> n;
    vector <int> a(n);
    vector <vector <int> > pos(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]].app(i);
    }   
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 5; ++j) {
            pos[i].app(n);
        }
    }   

    build(0, 0, n - 1);

    for (int i = 1; i <= n; ++i) {
        add(0, pos[i][0] - 1, 1);
        add(pos[i][2], pos[i][3] - 1, 1);
    }   

    vector <int> ptr(n + 1);

    int ans = 0;
    for (int l = 0; l < n; ++l) {
        if (l) {
            int x = a[l - 1];            

            //
            add(l, pos[x][ptr[x]] - 1, -1);
            add(pos[x][ptr[x]+2], pos[x][ptr[x]+3]-1, -1);

            ptr[x]++;

            add(l, pos[x][ptr[x]] - 1, 1);
            add(pos[x][ptr[x]+2], pos[x][ptr[x]+3]-1, 1);

        }   

        ii t = mx[0];
        if (t.f == n)
            ans += t.s;
    }   
    cout << ans << endl;
}