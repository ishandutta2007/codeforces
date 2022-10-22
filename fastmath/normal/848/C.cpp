#include<bits/stdc++.h>
using namespace std;
#define int long long
#define app push_back
const int N = 100001;
int a[N], ans[N];
set <int> pos[N];
int nx[N];

int timer = 0;

struct Mem1 {
    int i, x, v;
};  

vector <int> c[N];
vector <Mem1> mem1[N];
void upd_(int i) {
    int v = nx[i] - i;
    for (int k = i; k < N; k |= k + 1) {
        c[k].app(nx[i]);
        mem1[timer].app({k, nx[i], v});
    }   
}
void upd(int i, int to) {
    int v = nx[i] - i;
    for (int k = i; k < N; k |= k + 1) {
        mem1[timer].app({k, nx[i], -v});
    }       
    nx[i] = to;
    v = nx[i] - i;
    for (int k = i; k < N; k |= k + 1) {
        c[k].app(nx[i]);
        mem1[timer].app({k, nx[i], v});
    }   
}   
struct Mem {
    int i, q, f, x;
};  
vector <Mem> mem[N];
void get(int q, int f, int i, int x) {
    for (; i >= 0; i &= i + 1, --i) {
        mem[timer].app({i, q, f, x});
    }
}
bool quer[N];

vector <int> f[N];
void add(int i, int x, int v) {
    int p = lower_bound(c[i].begin(), c[i].end(), x) - c[i].begin();
    for (; p < c[i].size(); p |= p + 1) {
        f[i][p] += v;
    }       
}   
int get(int i, int x) {
    int p = upper_bound(c[i].begin(), c[i].end(), x) - c[i].begin() - 1;
    int ans = 0;
    for (; p >= 0; p &= p + 1, --p) {
        ans += f[i][p];
    }   
    return ans;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) nx[i] = N;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }   
    for (int i = 1; i <= n; ++i) {
        if (pos[a[i]].size()) {
            nx[*pos[a[i]].rbegin()] = i;
        }   
        pos[a[i]].insert(i);
    }
    for (int i = 1; i <= n; ++i) {
        upd_(i);
    }
    for (timer = 0; timer < m; ++timer) {
        int t;
        cin >> t;
        if (t == 1) {
            int p, x;
            cin >> p >> x;
            if (a[p] != x) {
                auto t = pos[a[p]].find(p);
                if (t != pos[a[p]].begin()) {
                    auto l = t; --l;
                    auto r = t; ++r;
                    if (r == pos[a[p]].end()) upd(*l, N);
                    else upd(*l, *r);
                }
                pos[a[p]].erase(t);
                a[p] = x;
                pos[x].insert(p);
                t = pos[x].find(p);
                auto r = t; ++r;
                if (r == pos[x].end()) upd(p, N);
                else upd(p, *r);
                if (t != pos[x].begin()) {
                    auto l = t; --l;
                    upd(*l, *t);
                }   
            }
        }   
        else {
            quer[timer] = 1;
            int l, r;
            cin >> l >> r;
            get(timer, 1, r, r); get(timer, -1, l - 1, r);
        }   
    }
    for (int i = 0; i < N; ++i) {
        sort(c[i].begin(), c[i].end()); 
        c[i].resize(unique(c[i].begin(), c[i].end()) - c[i].begin());
        f[i].resize(c[i].size());
    }   
    for (int i = 0; i < N; ++i) {
        for (auto e : mem1[i]) {
            add(e.i, e.x, e.v);
            //cout << i << ' ' << "add " << e.i << ' ' << e.x << ' ' << e.v << '\n';
        }
        for (auto e : mem[i]) {
            ans[e.q] += get(e.i, e.x) * e.f;
            //cout << i << ' ' << "get " << e.q << ' ' << e.f << ' ' << e.i << ' ' << e.x << '\n';
        }   
    }
    for (int i = 0; i < m; ++i) {
        if (quer[i]) cout << ans[i] << '\n';
    }   
}