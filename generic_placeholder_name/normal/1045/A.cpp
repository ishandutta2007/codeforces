//yes toi copy bai normie
//bai vua trivial vua kho chiu vai a
 
/*
        Normie's Template v2.0
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
 
#include <algorithm>
 
#include <vector>
 
namespace atcoder {
 
namespace internal {
 
template <class T> struct simple_queue {
    std::vector<T> payload;
    int pos = 0;
    void reserve(int n) { payload.reserve(n); }
    int size() const { return int(payload.size()) - pos; }
    bool empty() const { return pos == int(payload.size()); }
    void push(const T& t) { payload.push_back(t); }
    T& front() { return payload[pos]; }
    void clear() {
        payload.clear();
        pos = 0;
    }
    void pop() { pos++; }
};
 
}  // namespace internal
 
}  // namespace atcoder
 
#include <cassert>
#include <limits>
#include <queue>
#include <vector>
 
namespace atcoder {
 
template <class Cap> struct mf_graph {
  public:
    mf_graph() : _n(0) {}
    mf_graph(int n) : _n(n), g(n) {}
 
    int add_edge(int from, int to, Cap cap) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        int from_id = int(g[from].size());
        int to_id = int(g[to].size());
        if (from == to) to_id++;
        g[from].push_back(_edge{to, to_id, cap});
        g[to].push_back(_edge{from, from_id, 0});
        return m;
    }
 
    struct edge {
        int from, to;
        Cap cap, flow;
    };
 
    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
    }
    std::vector<edge> edges() {
        int m = int(pos.size());
        std::vector<edge> result;
        for (int i = 0; i < m; i++) {
            result.push_back(get_edge(i));
        }
        return result;
    }
    void change_edge(int i, Cap new_cap, Cap new_flow) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        assert(0 <= new_flow && new_flow <= new_cap);
        auto& _e = g[pos[i].first][pos[i].second];
        auto& _re = g[_e.to][_e.rev];
        _e.cap = new_cap - new_flow;
        _re.cap = new_flow;
    }
 
    Cap flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }
    Cap flow(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);
 
        std::vector<int> level(_n), iter(_n);
        internal::simple_queue<int> que;
 
        auto bfs = [&]() {
            std::fill(level.begin(), level.end(), -1);
            level[s] = 0;
            que.clear();
            que.push(s);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (auto e : g[v]) {
                    if (e.cap == 0 || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    if (e.to == t) return;
                    que.push(e.to);
                }
            }
        };
        auto dfs = [&](auto self, int v, Cap up) {
            if (v == s) return up;
            Cap res = 0;
            int level_v = level[v];
            for (int& i = iter[v]; i < int(g[v].size()); i++) {
                _edge& e = g[v][i];
                if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
                Cap d =
                    self(self, e.to, std::min(up - res, g[e.to][e.rev].cap));
                if (d <= 0) continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if (res == up) break;
            }
            return res;
        };
 
        Cap flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) break;
            std::fill(iter.begin(), iter.end(), 0);
            while (flow < flow_limit) {
                Cap f = dfs(dfs, t, flow_limit - flow);
                if (!f) break;
                flow += f;
            }
        }
        return flow;
    }
 
    std::vector<bool> min_cut(int s) {
        std::vector<bool> visited(_n);
        internal::simple_queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int p = que.front();
            que.pop();
            visited[p] = true;
            for (auto e : g[p]) {
                if (e.cap && !visited[e.to]) {
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }
 
  private:
    int _n;
    struct _edge {
        int to, rev;
        Cap cap;
    };
    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<_edge>> g;
};
 
}  // namespace atcoder
 
using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
 
//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;
//---------END-------//
int typ[5001],arr[5001];
vector<int> info[5001];
mf_graph<int> gr(30001);
int n,m,i,j,k,t,t1,u,v,a,b,res;
vector<int> gt[30001],path;
void build(int c, int l, int r)
{
        if (l<r)
        {
                gr.add_edge(m+n+1+c,m+n+1+(c<<1),1e8);
                gr.add_edge(m+n+1+c,m+n+1+(c<<1)+1,1e8);
                build((c<<1),l,(l+r)/2);
                build((c<<1)+1,(l+r)/2+1,r);
        }
        else gr.add_edge(m+n+1+c,n+l,1e8);
}
void add(int c, int l, int r, int tl, int tr, int x)
{
        if ((l>tr)or(r<tl)) return;
        else if ((l>=tl)and(r<=tr)) gr.add_edge(x,m+n+1+c,1);
        else
        {
                int mid=(l+r)/2;
                add((c<<1),l,mid,tl,tr,x);
                add((c<<1)+1,mid+1,r,tl,tr,x);
        }
}
int dfs(int x)
{
        path.push_back(x);
        if (x==m+n+1)
        {
                arr[path[path.size()-2]-n]=path[1];
        //      for (auto g : path) cout<<g<<' ';
                //cout<<endl;
                path.pop_back();
                return 1;
        }
        else if (gt[x].size())
        {
                int u=gt[x][gt[x].size()-1];
                gt[x].pop_back();
                int a=dfs(u);
                path.pop_back();
                return a;
        }
        else
        {
                path.pop_back();
                return 0;
        }
}
int main()
{
        fio;
        cin>>n>>m;
        build(1,1,m);
        for (i=1;i<=m;i++) gr.add_edge(n+i,n+m+1,1);
        for (i=1;i<=n;i++)
        {
                cin>>typ[i];
                if (typ[i]==0)
                {
                        gr.add_edge(0,i,1);
                        cin>>u;
                        for (j=0;j<u;j++)
                        {
                                cin>>v;
                                gr.add_edge(i,n+v,1);
                                info[i].push_back(v);
                        }
                }
                else if (typ[i]==2)
                {
 
                        gr.add_edge(0,i,2);
                        u=3;
                        for (j=0;j<u;j++)
                        {
                                cin>>v;
                                gr.add_edge(i,n+v,1);
                                info[i].push_back(v);
                        }
                }
                else
                {
 
                        gr.add_edge(0,i,1);
                        cin>>a>>b;
                        info[i].push_back(a);
                        info[i].push_back(b);
                        add(1,1,m,a,b,i);
                }
        }
        res=gr.flow(0,m+n+1);
        auto vv=gr.edges();
        for (auto g : vv)
        {
                for (i=0;i<g.flow;i++) gt[g.from].push_back(g.to);
        }
        while(dfs(0));
        for (i=1;i<=n;i++) if (typ[i]==2)
        {
                u=0;
                for (j=0;j<3;j++) if (arr[info[i][j]]==i) u++;
             //   assert(("what",u<3));
                if (u==1)
                for (j=0;j<3;j++)
                {
                        if (arr[info[i][j]]-i)
                        {
                                arr[info[i][j]]=i;
                                break;
                        }
                }
        }
        cout<<res<<endl;
        for (i=1;i<=m;i++) if (arr[i]) cout<<arr[i]<<' '<<i<<endl;
}