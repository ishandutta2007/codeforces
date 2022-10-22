#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> P;

const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;

int f[maxn];

void add(int x, int v) {
    while(x < maxn) {
        f[x] += v;
        x += x & (-x);
    }
}

int qry(int x) {
    int r = 0;
    while(x > 0) {
        r += f[x];
        x -= x & (-x);
    }
    return r;
}

P a[maxn];
bool cmp(const P &x, const P &y) {
    return x.se < y.se;
}

int p[maxn];
set<P> q;

int ff(int x) {
    //cout<<x<<" "<<p[x]<<endl;
    if(p[x] != x) p[x] = ff(p[x]);
    return p[x];
}

void funion(int x, int y) {
    x = ff(x);
    y = ff(y);
    if(x != y) p[x] = y;
}

int main() {
    int n;
    LL d = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        a[i] = P(u, v);
    }
    sort(a, a + n, cmp);
    for(int i = 0; i < n; ++i) p[i] = i;
    for(int i = n - 1; i >= 0; --i) {
        while(!q.empty()) {//cout<<-1<<endl;
            if(-(*q.begin()).fi > a[i].se) q.erase(q.begin());
            else break;
        }
        for(auto e:q) {
            if(-e.fi > a[i].fi) funion(e.se, i), d++;
            else break;
            if(d > n - 1) return puts("NO"), 0;
        }
        q.insert(P(-a[i].fi, i));
    }
    for(int i = 1; i < n; ++i) if(ff(i) != ff(0)) return puts("NO"), 0;
    if(d == n - 1) puts("YES");
    else puts("NO");
    return 0;
}