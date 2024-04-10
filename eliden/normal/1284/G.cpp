#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
class Spanning {
    int n, m;
    vector<pair<int,int>> edges;
    vector<bool> included;
    vector<vector<pair<int,int>>> adj;
    vector<bool> bfs(const vector<bool> &forbidden, int start=0, int end=-1) const {
        vector<bool> visited(n);
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            if(!visited[u]) {
                visited[u] = true;
                if(u==end) break;
                for(auto e:adj[u]) if(!forbidden[e.second]) q.push(e.first);
            }
        }
        return visited;
    }
public:
    Spanning(int n, vector<pair<int,int>> edges, vector<bool> included):
        n(n), m(edges.size()), edges(edges), included(included), adj(n) {
        rep(i,0,m) if(included[i]) {
            int x,y;
            tie(x,y) = edges[i];
            adj[x].emplace_back(y,i);
            adj[y].emplace_back(x,i);
        }
    }
    vector<int> circuit(int x, const vector<bool> &I) const {
        assert(!I[x]);
        vector<bool> forbidden = I;
        forbidden[x] = true;
        vector<bool> visited = bfs(forbidden,edges[x].first,edges[x].second);
        vector<int> result;
        if(!visited[edges[x].second]) {
            result.push_back(x);
            rep(i,0,m) if(included[i] && I[i]
                          && visited[edges[i].first]+visited[edges[i].second]==1) {
                result.push_back(i);
            }
        }
        return result;
    }
    bool connected() const {
        vector<bool> forbidden(m);
        auto visited = bfs(forbidden);
        rep(i,0,n) if(!visited[i]) return false;
        return true;
    }
};
class UniformThing {
    int n;
    vector<int> a;
    vector<vector<int>> adj;
public:
    UniformThing(int n, const vector<int> &a): n(n), a(a), adj(n) {
        int m = a.size();
        rep(x,0,m) if(a[x]!=-1) adj[a[x]].push_back(x);
    }
    vector<int> circuit(int x, const vector<bool> &I) const {
        assert(!I[x]);
        vector<int> result;
        if(a[x]==-1) return result;
        for(int y:adj[a[x]]) if(I[y]) result.push_back(y);
        if(result.size() >= adj[a[x]].size()-2) result.push_back(x);
        else result.clear();
        return result;
    }
};
template<typename M1, typename M2>
struct Intersection {
    M1 matroid1;
    M2 matroid2;
    int n;
    vector<ll> s1, s2;
    vector<bool> I;
    int k;
    ll val;
    Intersection(const vector<ll> &w, const M1 &matroid1, const M2 &matroid2):
        matroid1(matroid1), matroid2(matroid2),
        n(w.size()), s1(n,0), s2(w), I(n),k(0),val(0) {}
    bool step() {
        const ll INFTY=numeric_limits<ll>::max();
        const ll NEGINF=numeric_limits<ll>::min();
        vector<bool> source(n), sink(n);
        vector<vector<pair<int,ll>>> aux(n);
        ll m1=NEGINF,m2=NEGINF;
        rep(x,0,n) if(!I[x]) {
            auto ys = matroid1.circuit(x,I);
            if(sink[x] = !ys.size()) m1=max(m1,s1[x]);
            for(int y:ys) aux[x].emplace_back(y,s1[y]-s1[x]);
            ys = matroid2.circuit(x,I);
            if(source[x] = !ys.size()) m2=max(m2,s2[x]);
            for(int y:ys) aux[y].emplace_back(x,s2[y]-s2[x]);
        }
        if(m1==NEGINF || m2==NEGINF) return false;
        vector<ll> dist(n+1,INFTY);
        vector<int> pred(n+1,-1);
        using PQT = tuple<ll,int,int,int>;
        priority_queue<PQT,vector<PQT>,greater<PQT>> pq;;
        rep(x,0,n) {
            if(source[x]) pq.emplace(m2-s2[x],0,x,-1);
            if(sink[x]) aux[x].emplace_back(n,m1-s1[x]);
        }
        while(!pq.empty()) {
            int x, dd, last; ll c;
            tie(c,dd,x,last) = pq.top();
            pq.pop();
            if(c<dist[x]) {
                dist[x] = c;
                pred[x] = last;
                if(x==n) break;
                for(auto e:aux[x]) pq.emplace(c+e.second,dd+1,e.first,x);
            }
        }
        ll d = dist[n];
        if(d==INFTY) return false;
        val += m1+m2-d;
        rep(x,0,n) if(dist[x]<INFTY) {
            ll delta = d-dist[x];
            s1[x] += delta;
            s2[x] -= delta;
        }
        for(int x=pred[n];x!=-1;x=pred[x]) I[x] = !I[x];
        ++k;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    rep(test,0,tests) {
        int nn, mm;
        cin>>nn>>mm;
        vector<string> input(nn);
        rep(i,0,nn) cin>>input[i];
        int n = 0;
        vector<vector<int>> nodeid(nn, vector<int>(mm,-1));
        rep(i,0,nn) rep(j,0,mm) if(input[i][j]=='O') {
            nodeid[i][j] = n++;
        }
        int m = 0; 
        vector<vector<int>> edgeid(2*nn, vector<int>(2*mm,-1));
        vector<int> assign;
        vector<vector<char>> ans(2*nn-1, vector<char>(2*mm-1,' '));
        vector<pair<int,int>> edges;
        rep(i,0,nn) rep(j,0,mm) {
            ans[2*i][2*j] = input[i][j];
            if(i+1<nn && nodeid[i][j]>=0 && nodeid[i+1][j]>=0) {
                int ii = i;
                if((i+j)%2!=0) ++ii;
                int label = nodeid[ii][j];
                if(ii==0 && j == 0) label = -1;
                assign.push_back(label);
                edges.emplace_back(nodeid[i][j], nodeid[i+1][j]);
                edgeid[2*i+1][2*j] = m++;
                ans[2*i+1][2*j] = 'O';
            }
            if(j+1<mm && nodeid[i][j]>=0 && nodeid[i][j+1]>=0) {
                int jj = j;
                if((i+j)%2!=0) ++jj;
                int label = nodeid[i][jj];
                if(i==0 && jj == 0) label = -1;
                assign.push_back(label);
                edges.emplace_back(nodeid[i][j], nodeid[i][j+1]);
                edgeid[2*i][2*j+1] = m++;
                ans[2*i][2*j+1] = 'O';
            }            
        }
        Spanning matroid1(n,edges,vector<bool>(m,true));
        UniformThing matroid2(n, assign);
        vector<ll> weights(m,0);
        Intersection<Spanning,UniformThing> intersect(weights,matroid1,matroid2);
        int k = 0;
        while(intersect.step()) ++k;
        bool bad = false;
        if(k<m-(n-1)) bad = true;
        else {
            vector<int> count(n);
            rep(i,0,m) if(!intersect.I[i] && assign[i]!=-1) ++count[assign[i]];
            rep(i,0,nn) rep(j,0,mm) {
                if(i==0 && j==0 ) continue;
                if((i+j)%2!=0) continue;
                if(nodeid[i][j]>=0 && count[nodeid[i][j]]<2) {
                    bad = true;
                }
            }
        }
        if(bad) cout<<"NO\n";
        else {
            cout<<"YES\n";
            rep(i,0,2*nn-1) {
                rep(j,0,2*mm-1) {
                    if(edgeid[i][j]>=0 && intersect.I[edgeid[i][j]]) {
                        ans[i][j] = ' ';
                    }
                    cout<<ans[i][j];
                }
                cout<<"\n";
            }
        }
    }
    

}