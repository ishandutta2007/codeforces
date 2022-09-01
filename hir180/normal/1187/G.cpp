#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <assert.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define fi first
#define sc second
using int64 = long long;

typedef pair<long long,long long> P;
#define repn(i,n) for(int i=1;i<=n;i++)
typedef pair<P,P> P2;
//#define INF 1000000000
#define mod 1000000007
typedef long long ll;

template< typename flow_t, typename cost_t >
struct PrimalDual {
  const cost_t INF;
 
  struct edge {
    int to;
    flow_t cap;
    cost_t cost;
    int rev;
    bool isrev;
  };
  vector< vector< edge > > graph;
  vector< cost_t > potential, min_cost;
  vector< int > prevv, preve;
 
  PrimalDual(int V) : graph(V), INF(numeric_limits< cost_t >::max()) {}
 
  void add_edge(int from, int to, flow_t cap, cost_t cost) {
    graph[from].emplace_back((edge) {to, cap, cost, (int) graph[to].size(), false});
    graph[to].emplace_back((edge) {from, 0, -cost, (int) graph[from].size() - 1, true});
  }
 
  cost_t min_cost_flow(int s, int t, flow_t f) {
    int V = (int) graph.size();
    cost_t ret = 0;
    using Pi = pair< cost_t, int >;
    priority_queue< Pi, vector< Pi >, greater< Pi > > que;
    potential.assign(V, 0);
    preve.assign(V, -1);
    prevv.assign(V, -1);
 
    while(f > 0) {
      min_cost.assign(V, INF);
      que.emplace(0, s);
      min_cost[s] = 0;
      while(!que.empty()) {
        Pi p = que.top();
        que.pop();
        if(min_cost[p.second] < p.first) continue;
        for(int i = 0; i < graph[p.second].size(); i++) {
          edge &e = graph[p.second][i];
          cost_t nextCost = min_cost[p.second] + e.cost + potential[p.second] - potential[e.to];
          if(e.cap > 0 && min_cost[e.to] > nextCost) {
            min_cost[e.to] = nextCost;
            prevv[e.to] = p.second, preve[e.to] = i;
            que.emplace(min_cost[e.to], e.to);
          }
        }
      }
      if(min_cost[t] == INF) return -1;
      for(int v = 0; v < V; v++) potential[v] += min_cost[v];
      flow_t addflow = f;
      for(int v = t; v != s; v = prevv[v]) {
        addflow = min(addflow, graph[prevv[v]][preve[v]].cap);
      }
      f -= addflow;
      ret += addflow * potential[t];
      for(int v = t; v != s; v = prevv[v]) {
        edge &e = graph[prevv[v]][preve[v]];
        e.cap -= addflow;
        graph[v][e.rev].cap += addflow;
      }
    }
    return ret;
  }
 
  void output() {
    for(int i = 0; i < graph.size(); i++) {
      for(auto &e : graph[i]) {
        if(e.isrev) continue;
        auto &rev_e = graph[e.to][e.rev];
        cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << rev_e.cap + e.cap << ")" << endl;
      }
    }
  }
};

int n,m,k,c,d;

int main(){
	cin>>n>>m>>k>>c>>d;
	PrimalDual< int64, int64 > flow(6005);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=102;j++){
			flow.add_edge(i*105+j,i*105+j+1,55,0);
			if(i == 1){
				flow.add_edge(i*105+j,6003,55,c*j);
			}
		}
	}
	for(int i=1;i<=k;i++){
		int a; scanf("%d",&a);
		flow.add_edge(6002,a*105,1,0);
	}
	for(int i=1;i<=m;i++){
		int a,b; scanf("%d%d",&a,&b);
		for(int j=0;j<=102;j++){
			for(int ii=1;ii<=n/2+3;ii++){
				flow.add_edge(a*105+j,b*105+j+1,1,d*(2*ii-1));
				flow.add_edge(b*105+j,a*105+j+1,1,d*(2*ii-1));
			}
		}
	}
	cout << flow.min_cost_flow(6002,6003,k) << endl;
}