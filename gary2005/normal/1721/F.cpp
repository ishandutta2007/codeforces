/**
 *    author:  gary
 *    created: 27.08.2022 22:31:52
**/
#include<bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <vector>


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


namespace atcoder {

template <class Cap> struct mf_graph {
  public:
    mf_graph() : _n(0) {}
    explicit mf_graph(int n) : _n(n), g(n) {}

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
                if (res == up) return res;
            }
            level[v] = _n;
            return res;
        };

        Cap flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) break;
            std::fill(iter.begin(), iter.end(), 0);
            Cap f = dfs(dfs, t, flow_limit - flow);
            if (!f) break;
            flow += f;
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

#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
using namespace atcoder;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=4e5+20;
void f(){fflush(stdout);}
int n1,n2,m,q,bl[MAXN],x[MAXN],y[MAXN];
bool die[MAXN],live[MAXN];
set<int> S;
vector<int> g[MAXN];
int main(){
    cin>>n1>>n2>>m>>q;
    mf_graph<int> graph(n1+n2+2);
    rb(i,1,n1) graph.add_edge(0,i,1);
    rb(i,1,n2) graph.add_edge(i+n1,n1+n2+1,1);
    rb(i,1,m){
        cin>>x[i]>>y[i];
        g[x[i]].push_back(y[i]+n1);
        g[y[i]+n1].push_back(x[i]);
        graph.add_edge(x[i],y[i]+n1,1);
    }
    graph.flow(0,n1+n2+1);
    auto X=graph.edges();
    assert(X.size()==m+n1+n2);
    LL sum=0;
    int cnt=0;
    rb(i,1,m){
        if(X[i-1+n1+n2].flow==1){
            int u,v;
            u=X[i-1+n1+n2].from,v=X[i-1+n1+n2].to;
            bl[u]=bl[v]=i;
            live[i]=1;
            sum+=i;
            cnt++;
            S.insert(i);
        }
    }
    queue<mp> qu;
    rb(i,1,n1+n2) if(!bl[i]){
        for(auto it:g[i]){
            qu.push(II(it,i));
        }
    }
    f();
    while (q--){
        int t;
        cin>>t;
        if(t==1){
            while (!qu.empty()&&(die[qu.front().first]||die[qu.front().second])) qu.pop();
            int era;
            if(!qu.empty()) era=qu.front().first;
            else era=x[*S.begin()];
            die[era]=1;
            cout<<"1\n";
            cout<<(era<=n1? era:n1-era)<<'\n';
            sum-=bl[era];
            cnt--;
            live[bl[era]]=0;
            era=bl[era];
            S.erase(era);
            bl[x[era]]=bl[y[era]+n1]=0;
            cout<<sum<<'\n';
            for(auto it:g[x[era]]) qu.push(II(it,x[era]));
            for(auto it:g[y[era]+n1]) qu.push(II(it,y[era]+n1));
        }
        else{
            cout<<cnt<<'\n';
            rb(i,1,m){
                if(live[i]){
                    cout<<i<<' ';
                }
            }
            cout<<'\n';
        }
        f();
    }
    return 0;
}