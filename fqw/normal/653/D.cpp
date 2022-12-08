#include <cassert>
#include <list>
#include <queue>
#include <memory>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <limits>
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


class Dinic {
public:
    typedef LL T;

    explicit Dinic(int n) : n_(n), es_(n) {}

    void add_edge(int x, int y, T w) {
        Edge *e1, *e2;
        es_[x].emplace_back(e1=new Edge{y, w, nullptr});
        es_[y].emplace_back(e2=new Edge{x, 0, nullptr});
        e1->oppo=e2, e2->oppo=e1;
    }

    T compute_max(int s, int t) {
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

private:
    struct Edge { int y;  T w; Edge* oppo; };
    const int n_;
    vector<vector<unique_ptr<Edge>>> es_;
};

const int N=55;
const int M=555;

int a[M], b[M], c[M], n, m, x;

bool check(double each) {
    Dinic net(n);
    rep(i, 1, m) {
        int w=0;
        if(c[i]>x*each) w=x+1;
        else w=int(c[i]/each);
        net.add_edge(a[i]-1, b[i]-1, w);
    }
    return net.compute_max(0, n-1)>=x;
}

int main() {
    scanf("%d%d%d", &n,&m,&x);
    rep(i, 1, m) scanf("%d%d%d", &a[i],&b[i],&c[i]);
    double le=0, ri=1000000;
    repn(tt, 199) {
        double mid=(le+ri)/2;
        if(check(mid)) le=mid;
        else ri=mid;
    }
    printf("%.9lf\n", le*x);
    return 0;
}