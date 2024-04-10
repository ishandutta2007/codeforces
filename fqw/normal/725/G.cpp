// 9:52 - 10:34 - wa sample
//      - 11:13 - pass sample - wa
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define fillchar(a, x) memset(a, x, sizeof(a))
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define replr(i, a, b) rep(i, a, (b)-1)
#define reprl(i, a, b) irep(i, (b)-1, a)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef vector<int> VI;
template<class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os<<"("<<v.first<<", "<<v.second<<")"; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v) { os<<"["; repn(i, sz(v)) { if(i) os<<", "; os<<v[i]; } return os<<"]"; }
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const int N=200002;

VI children[N];
int dep[N], pos[N], ind[N], head[N], fa[N];
int order[N];
int n, qn;

void init() {
    scanf("%d%d", &n, &qn);
    ++n;
    replr(i, 1, n) {
        int j; scanf("%d", &j);
        children[j].pb(i);
    }

    VI size(n), maxy(n);
    const function<void(int)> compute_size=[&](int x) {
        size[x]=1;
        maxy[x]=-1;
        for(int y: children[x]) {
            compute_size(y);
            size[x]+=size[y];
            if(maxy[x]<0 || size[y]>size[maxy[x]]) {
                maxy[x]=y;
            }
        }
    };
    compute_size(0);

    int cur=0;
    const function<void(int,int,int,int)> dfs=[&](int d, int x, int f, int h) {
        pos[x]=cur, ind[cur]=x, ++cur;
        dep[x]=d, head[x]=h, fa[x]=f;
        if(maxy[x]>=0) {
            dfs(d+1, maxy[x], x, h);
        }
        for(int y: children[x]) if(y!=maxy[x]) {
            dfs(d+1, y, x, y);
        }
    };
    dfs(0, 0, -1, 0);
}

struct Node {
    int buf=0;
    int val=0;
} tr[N*4];

void push(int x, int l, int r, int buf) {
    tr[x].buf=buf;
    tr[x].val=buf+(r-l-1);
}

void release(int x, int l, int r) {
    if(tr[x].buf>0) {
        const int m=(l+r)/2;
        push(x*2+1, l, m, tr[x].buf);
        push(x*2+2, m, r, tr[x].buf+(m-l));
        tr[x].buf=0;
    }
}

void update(int x, int l, int r) {
    const int m=(l+r)/2;
    tr[x].val=max(tr[x*2+1].val-(r-m), tr[x*2+2].val);
}

void set(int x, int l, int r, int st, int en, int val) {
    if(st<=l && r<=en) {
        push(x, l, r, val+(l-st));
        return;
    }
    release(x, l, r);
    const int m=(l+r)/2;
    if(st<m) set(x*2+1, l, m, st, en, val);
    if(m<en) set(x*2+2, m, r, st, en, val);
    update(x, l, r);
}

int find(int x, int l, int r, int st, int en, int val) {
    if(l+1==r) {
        if(tr[x].val>val+(en-r)) {
            return l;
        } else {
            return l-1;
        }
    }
    release(x, l, r);
    const int m=(l+r)/2;
#define L find(x*2+1, l, m, st, en, val)
#define R find(x*2+2, m, r, st, en, val)

    if(m<=st) {
        return R;
    } else if(en<=m) {
        return L;
    } else {
        if(r<=en) {
            if(tr[x*2+2].val>val+(en-r)) {
                return R;
            } else {
                return L;
            }
        } else {
            int i=R;
            if(i<m) i=L;
            return i;
        }
    }
}


void solve() {
    struct Query {
        int i, x, t, gt;
        bool operator <(const Query& q) const {
            return gt<q.gt || (gt==q.gt && x<q.x);
        }
    };
    vector<Query> qs(qn);
    repn(i, qn) {
        scanf("%d%d", &qs[i].x, &qs[i].t);
        qs[i].i=i;
        qs[i].gt=qs[i].t+dep[qs[i].x];
    }
    sort(all(qs));

    VI ans(qn);
    for(const auto& q: qs) {
        int t=q.t, x=q.x, y=x;
        while(y>0) {
            int z=head[y];
            int i=find(0, 0, n, pos[z], pos[y]+1, t+(dep[x]-dep[y]));
            if(i<pos[z]) {
                y=z>0?fa[z]:z;
            } else {
                y=ind[i];
                break;
            }
        }
        t+=(dep[x]-dep[y])*2;
        ans[q.i]=t;
        while(x!=y) {
            int z=head[x];
            if(dep[z]<=dep[y]) z=ind[pos[y]+1];
            set(0, 0, n, pos[z], pos[x]+1, t-(dep[x]-dep[z]));
            t-=dep[x]-dep[fa[z]], x=fa[z];
        }
    }
    repn(i, qn) printf("%d ", ans[i]);
    printf("\n");
}

int main() {
    init();
    solve();
    return 0;
}