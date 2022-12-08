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
#include <string>
#include <vector>
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
template<class T> ostream& operator<<(ostream& os, const vector<T>& vec) {
    os<<"["; bool f=false;
    for(const auto& x: vec) { if(f) os<<", "; f=true; os<<x; }
    return os<<"]";
}
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

class Dinic {
public:
    typedef LL T;
    explicit Dinic(int n) : n_(n), es_(n) {}
    void add_edge(int x, int y, T w) { add_edge_(x, y, w); }
    T compute_max(int s, int t) { return compute_max_(s, t); }

private: // {{{
    struct Edge { int y;  T w; Edge* oppo; };

    void add_edge_(int x, int y, T w) {
        Edge *e1, *e2;
        es_[x].emplace_back(e1=new Edge{y, w, nullptr});
        es_[y].emplace_back(e2=new Edge{x, 0, nullptr});
        e1->oppo=e2, e2->oppo=e1;
    }

    T compute_max_(int s, int t) {
        T ans=0;
        while(1) {
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
            if(dis[t]==0) return ans;

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
            ans+=dfs(s, numeric_limits<T>::max());
        }
    }

    const int n_;
    vector<vector<unique_ptr<Edge>>> es_;
// }}}
};

bool solve() {
    int n, b, q; scanf("%d%d%d", &n,&b,&q);
    VPI lims(q);
    for(auto& lim: lims) scanf("%d%d", &lim.fi,&lim.se);
    lims.pb(mp(b, n));
    sort(all(lims));
    VI size, belong(b);
    int cur=0, curv=0;
    for(const auto& lim: lims) {
        if(lim.se<curv) return false;
        int i=sz(size);
        size.pb(lim.se-curv); curv=lim.se;
        while(cur<lim.fi) belong[cur++]=i;
    }
    q=sz(size);

    //cout<<"size: "<<size<<endl;
    //cout<<"belong: "<<belong<<endl;

    Dinic net(b+q+5+2);
    const int s=b+q+5;
    const int t=b+q+6;
    repn(i, 5) {
        net.add_edge(s, b+q+i, n/5);
    }
    repn(i, b) {
        net.add_edge(b+q+i%5, i, 1);
        net.add_edge(i, b+belong[i], 1);
    }
    repn(i, q) {
        net.add_edge(b+i, t, size[i]);
    }
    return net.compute_max(s, t)==n;
}

int main() {
    printf("%s\n", solve()?"fair":"unfair");
    return 0;
}