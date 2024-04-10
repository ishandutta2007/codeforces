#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <set>
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
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os<<"("<<v.first<<", "<<v.second<<")"; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v) { os<<"["; repn(i, sz(v)) { if(i) os<<", "; os<<v[i]; } return os<<"]"; }
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const int kInf=1<<30;

int kInfX ;

struct Tree {
    const int n;
    VI tr;

    Tree(int _n) : n(_n), tr(n*4, kInf) {}

    int minval(int cur, int l, int r, int s, int t) const {
        if(s<=l && r<=t) return tr[cur];
        const int m=(l+r)/2;
        int ans=kInf;
        if(s<m) setmin(ans, minval(cur*2+1, l, m, s, t));
        if(m<t) setmin(ans, minval(cur*2+2, m, r, s, t));
        return ans;
    }

    int minval(int s, int t) const {
        if(s>=t) return kInf;
        return minval(0, 0, n, s, t);
    }

    void change(int cur, int l, int r, int i, int v) {
        if(l+1==r) { tr[cur]=v; return; }
        const int m=(l+r)/2;
        if(i<m) change(cur*2+1, l, m, i, v);
           else change(cur*2+2, m, r, i, v);
        tr[cur]=min(tr[cur*2+1], tr[cur*2+2]);
    }

    void change(int i, int v) {
        change(0, 0, n, i, v);
    }
};

struct BigTree {
    struct Node {
        VI ys;
        vector<set<int>> ps;
        Tree* tree;
        Node *l=nullptr, *r=nullptr;
        int yi(int y) const { return int(lower_bound(all(ys), y)-ys.begin()); }
    } *root;

    static VI grab_ys(const vector<pair<PII, int>>& ps) {
        VI ys;
        for(const auto& p: ps) ys.pb(p.fi.se);
        sort(all(ys)), ys.erase(unique(all(ys)), ys.end());
        return ys;
    }

    Node* build(int l, int r, const vector<pair<PII, int>>& ps) {
        if(ps.empty()) return nullptr;
        Node* cur=new Node();
        cur->ys=grab_ys(ps);
        cur->ps.resize(cur->ys.size());
        for(const auto& p: ps) cur->ps[cur->yi(p.fi.se)].insert(p.se);
        cur->tree=new Tree(sz(cur->ys));
        repn(i, sz(cur->ys)) cur->tree->change(i, *cur->ps[i].begin());
        if(l+1<r) {
            const int m=(l+r)/2;
            vector<pair<PII, int>> lps, rps;
            for(const auto& p: ps) (p.fi.fi<m?lps:rps).pb(p);
            cur->l=build(l, m, lps);
            cur->r=build(m, r, rps);
        }
        return cur;
    }

    BigTree(const VPI& ps) {
        vector<pair<PII, int>> tmp;
        repn(i, sz(ps)) tmp.pb(mp(ps[i], i));
        root=build(0, kInfX, tmp);
    }

    int minval(Node* cur, int l, int r, int x1, int x2, int y1, int y2) const {
        if(cur==nullptr) return kInf;
        if(x1<=l && r<=x2) return cur->tree->minval(cur->yi(y1), cur->yi(y2));
        const int m=(l+r)/2;
        int ans=kInf;
        if(x1<m) setmin(ans, minval(cur->l, l, m, x1, x2, y1, y2));
        if(m<x2) setmin(ans, minval(cur->r, m, r, x1, x2, y1, y2));
        return ans;
    }

    int minval(int x1, int x2, int y1, int y2) const {
        return minval(root, 0, kInfX, x1, x2, y1, y2);
    }

    Node* erase(Node* cur, int l, int r, int x, int y, int v) {
        {
            int i=cur->yi(y);
            cur->ps[i].erase(v);
            if(cur->ps[i].empty()) {
                cur->tree->change(i, kInf);
            } else {
                cur->tree->change(i, *cur->ps[i].begin());
            }
        }
        if(l+1==r) return cur;
        const int m=(l+r)/2;
        if(x<m) cur->l=erase(cur->l, l, m, x, y, v);
           else cur->r=erase(cur->r, m, r, x, y, v);
        return cur;
    }

    void erase(int x, int y, int v) {
        root=erase(root, 0, kInfX, x, y, v);
    }
};

int main() {
    struct Target { int x1, x2, y1, y2, z, i; };
    int n; scanf("%d",&n);
    vector<Target> ts(n);
    repn(i, n) {
        scanf("%d%d%d%d%d", &ts[i].x1,&ts[i].x2,&ts[i].y1,&ts[i].y2,&ts[i].z);
        ts[i].i=i;
    }

    int m; scanf("%d", &m);
    vector<PII> bs(m);
    repn(i, m) scanf("%d%d", &bs[i].fi,&bs[i].se);

    {
        VI xs;
        for(const auto& t: ts) xs.pb(t.x1), xs.pb(t.x2);
        for(const auto& b: bs) xs.pb(b.fi);
        sort(all(xs)), xs.erase(unique(all(xs)), xs.end());
        kInfX=sz(xs);
        for(auto& t: ts) {
            t.x1=int(lower_bound(all(xs), t.x1)-xs.begin());
            t.x2=int(lower_bound(all(xs), t.x2)-xs.begin());
        }
        for(auto& b: bs) b.fi=int(lower_bound(all(xs), b.fi)-xs.begin());
    }

    BigTree tr(bs);

    VI ans(m, kInf);
    sort(all(ts), [](const Target& a, const Target& b) { return a.z<b.z; });
    for(const auto& t: ts) {
        int i=tr.minval(t.x1, t.x2+1, t.y1, t.y2+1);
        if(i==kInf) continue;
        ans[i]=t.i;
        tr.erase(bs[i].fi, bs[i].se, i);
    }
    for(int i: ans) printf("%d\n", i==kInf ? 0 : i+1);

    return 0;
}