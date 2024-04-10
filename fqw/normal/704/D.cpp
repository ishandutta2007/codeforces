#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <memory>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define sz(a) static_cast<int>(a.size())
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
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
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const int N=100010;

class Network { // {{{
    typedef int T;
    struct Edge { int y; T w; Edge* oppo; };
    const int n_, super_s_, super_t_;
    T super_total_ = 0;
    vector<vector<unique_ptr<Edge>>> es_;

    T augment(int s, int t) {
        VI dis(n_); dis[s]=1; 
        queue<int> que; que.push(s);
        while(!que.empty()) {
            int x=que.front(); que.pop();
            for(const auto& e: es_[x]) {
                if(e->w>0 && dis[e->y]==0) {
                    dis[e->y]=dis[x]+1;
                    que.push(e->y);
                }
            }
        }
        if(dis[t]==0) return 0;

        vector<size_t> ce(n_);
        const function<T(int,T)> dfs=[&](int x, T rest) {
            if(x==t) return rest;
            T r=0;
            for(size_t& i=ce[x]; i<es_[x].size(); ++i) {
                const auto& e=es_[x][i];
                if(e->w>0 && dis[e->y]>dis[x]) {
                    T cur=dfs(e->y, min(e->w, rest));
                    e->w-=cur, e->oppo->w+=cur;
                    r+=cur, rest-=cur;
                    if(rest==0) break;
                }
            }
            return r;
        };
        return dfs(s, numeric_limits<T>::max());
    }
public:
    explicit Network(int n) : n_(n+2), super_s_(n), super_t_(n+1), es_(n_) {}

    void* add_edge(int x, int y, T w) {
        Edge *e1, *e2;
        es_[x].emplace_back(e1=new Edge{y, w, nullptr});
        es_[y].emplace_back(e2=new Edge{x, 0, nullptr});
        e1->oppo=e2, e2->oppo=e1;
        return e1;
    }

    void* add_edge_with_lower_limit(int x, int y, T w, T lb) {
        if(lb>0) {
            add_edge(super_s_, y, lb);
            add_edge(x, super_t_, lb);
            super_total_+=lb;
        }
        return add_edge(x, y, w-lb);
    }

    // Returns -1 if no solution.
    T compute_maxflow(int s, int t) {
        if(super_total_>0) {
            add_edge(t, s, numeric_limits<T>::max());
            LL r=0, tmp;
            while((tmp=augment(super_s_, super_t_))>0) r+=tmp;
            if(r!=super_total_) return -1;
        }
        T ans=0, tmp;
        while((tmp=augment(s, t))>0) ans+=tmp;
        return ans;
    }

    T flow(void* e) const { return static_cast<Edge*>(e)->oppo->w; }
};  // }}}

int main() {
    map<int, int> lim_x, lim_y;
    int n, m; scanf("%d%d", &n,&m);
    int r, b; scanf("%d%d", &r,&b);
    bool rb_rev=false; if(r>b) rb_rev=true, swap(r, b);
    static PII points[N]; bool anscolor[N];
    rep(i, 1, n) {
        int x, y; scanf("%d%d", &x,&y);
        points[i]=mp(x, y);
    }
    rep(i, 1, m) {
        int t, l, d; scanf("%d%d%d", &t,&l,&d);
        if(t==1) {
            if(lim_x.count(l)) setmin(lim_x[l], d);
            else lim_x[l]=d;
        } else {
            if(lim_y.count(l)) setmin(lim_y[l], d);
            else lim_y[l]=d;
        }
    }
    map<int, VI> cnt_x, cnt_y, free_x, free_y;
    int ans=0;
    rep(i, 1, n) {
        bool has_x=lim_x.count(points[i].fi)>0;
        bool has_y=lim_y.count(points[i].se)>0;
        if(!has_x && !has_y) { ans+=1; anscolor[i]=true; continue; }
        if(has_x && !has_y) { free_x[points[i].fi].pb(i); continue; }
        if(!has_x && has_y) { free_y[points[i].se].pb(i); continue; }
        cnt_x[points[i].fi].pb(i), cnt_y[points[i].se].pb(i);
    }

    int num=0;
    const int s=num++;
    const int t=num++;
    map<int, int> ix, iy;
    static void* es[N]; fillchar(es, 0);
    for(const auto& kv: lim_x) ix[kv.fi]=num++;
    for(const auto& kv: lim_y) iy[kv.fi]=num++;
    Network net(num);
    repn(tt, 2) {
        auto& lim=(tt==0?lim_x:lim_y);
        auto& cnt=(tt==0?cnt_x:cnt_y);
        auto& free=(tt==0?free_x:free_y);
        for(const auto& kv: lim) {
            const int c=sz(cnt[kv.fi]), f=sz(free[kv.fi]);
            const int tot=c+f, lbound=max(0,(tot-kv.se+1)/2), rbound=tot-lbound;
            //printf("tt=%d,v=%d c=%d f=%d [%d,%d]\n",tt,kv.fi,c,f,lbound,rbound);
            if(lbound>rbound) { printf("-1\n"); return 0; }
            if(tt==0) {
                const int x=ix[kv.fi];
                net.add_edge_with_lower_limit(s, x, rbound, lbound);
                for(int i: free[kv.fi]) {
                    es[i]=net.add_edge(x, t, 1);
                }
                for(int i: cnt[kv.fi]) {
                    const int y=iy[points[i].se];
                    es[i]=net.add_edge(x, y, 1);
                }
            } else {
                const int y=iy[kv.fi];
                net.add_edge_with_lower_limit(y, t, rbound, lbound);
                for(int i: free[kv.fi]) {
                    es[i]=net.add_edge(s, y, 1);
                }
            }
        }
    }
    int tmp=net.compute_maxflow(s,t);
    if(tmp<0) { printf("-1\n"); return 0; }
    ans+=tmp;
    //printf("ans=%d\n", ans);
    rep(i, 1, n) if(es[i]!=nullptr) anscolor[i]=(net.flow(es[i])>0);
    //printf("ans=%d\n",ans);
    printf("%lld\n", ans*LL(r)+(n-ans)*LL(b));
    rep(i, 1, n) printf("%c", (anscolor[i]^rb_rev)?'r':'b');

    return 0;
}