#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;

#define int long long

// flow from UW team reference document

using VI = vector<int>;
using PII = pair<int,int>;
#define ALL(x) x.begin(),x.end()
#define REP(v,n) for(int v = 0; v < n; ++v)
#define st first
#define nd second
#define PB push_back

const int INF = 2e9 + 5;

class MinCostFlow {
  struct MCEdge { int to, cost, flow; MCEdge* next; };
  const int Infty = 1e13L + 100;
  vector<vector<MCEdge*>> adjList;
  int N, Source, Sink;
  VI dist;
  vector<MCEdge*> prev, Edges;
  void spfa() {
    queue<int> Q; vector<bool> onQueue(N); fill(ALL(dist), Infty);
    Q.push(Source); onQueue[Source] = true; dist[Source] = 0;
    while (!Q.empty()) {
      int v = Q.front(); Q.pop(); onQueue[v] = false;
      for (MCEdge *E : adjList[v]) {
        int s = E->to;
        if (E->flow == 0) { continue; }
        int newDist = dist[v] + E->cost;
        if (newDist < dist[s]) {
          dist[s] = newDist;
          prev[s] = E->next;
          if (!onQueue[s]) {
            Q.push(s); onQueue[s] = true;
          }
        }
      }
    }
  }
  int reduce_cost() {
    REP (v, N) for (MCEdge* E: adjList[v]) E->cost += dist[v] - dist[E->to];
    return dist[Sink];
  }
  void dijkstra_shortest_path(){
    fill(ALL(dist), Infty); dist[Source] = 0;
    priority_queue<PII> Q; Q.push(make_pair(0, Source));
    while (!Q.empty()){
      int dst = -Q.top().st, v = Q.top().nd; Q.pop();
      if (dst != dist[v]) { continue; }
      for (MCEdge* E: adjList[v]){
        int s = E->to;
        if (!E->flow) { continue; }
        int newDist = dist[v] + E->cost;
        if(newDist < dist[s]){
          dist[s] = newDist;
          prev[s] = E->next;
          Q.push({-newDist, s});
        }
      }
    }
  }
public:
  MinCostFlow(){}
  MinCostFlow(int _N) : N(_N), dist(_N), prev(_N), adjList(_N) {}
  ~MinCostFlow(){ for (MCEdge* E: Edges) { delete E; } }
  void fit(int size) {
    if (size > N) {
      N = size;
      dist.resize(size); prev.resize(size); adjList.resize(size);
    }
  }
  void add_edge(int u, int v, int flow, int cost){
	  debug() << "add" imie(u) imie(v) imie(flow) imie(cost);
    fit(max(u, v) + 1);
    MCEdge *E1 = new MCEdge{v, cost, flow}, *E2 = new MCEdge{u, -cost, 0};
    Edges.PB(E1); Edges.PB(E2);
    E1->next = E2; E2->next = E1;
    adjList[u].PB(E1); adjList[v].PB(E2);
  }
  PII get_min_cost_flow(int s, int t){
    fit(max(s, t) + 1);
    Source = s; Sink = t;
    int cost = 0, flow = 0;
    spfa();
    if(dist[Sink] > Infty / 2) { return {0,0}; }
    int sinkCost = reduce_cost();
    while (true) {
      dijkstra_shortest_path();
      if(dist[Sink] > Infty / 2) { break; }
      sinkCost += reduce_cost();
      int maxSend = Infty;
      for(int v = Sink; v != Source; v = prev[v]->to){
        maxSend = min(maxSend, prev[v]->next->flow);
      }
      for(int v = Sink; v != Source; v = prev[v]->to){
        MCEdge *E1 = prev[v], *E2 = E1->next;
        E1->flow += maxSend; E2->flow -= maxSend;
      }
      flow += maxSend;
      cost += maxSend * sinkCost;
    }
    return {flow, cost};
  }
};





#undef int
int main() {
	int side, m;
	scanf("%d%d", &side, &m);
	vector<vector<int>> in;
	set<int> X, Y;
	for(int i = 0; i < m; ++i) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		X.insert(x1);
		X.insert(x2 + 1);
		Y.insert(y1);
		Y.insert(y2 + 1);
		in.push_back({x1, y1, x2, y2});
	}
	
	auto get = [&](int x1, int x2, vector<int> vx) {
		vector<int> iksy;
		for(int j = 0; j < (int) vx.size() - 1; ++j) {
			if(x1 <= vx[j] && vx[j+1] - 1 <= x2) {
				iksy.push_back(j);
			}
		}
		// debug() << imie(x1) imie(x2) imie(vx) imie(iksy);
		return iksy;
	};
	
	vector<int> vx, vy;
	for(int a : X) {
		vx.push_back(a);
	}
	for(int a : Y) {
		vy.push_back(a);
	}
	
	MinCostFlow flow(vx.size() + vy.size() + 5);
	for(int i = 0; i < (int) vx.size() - 1; ++i) {
		flow.add_edge(0, i + 1, vx[i+1] - vx[i], 0);
	}
	for(int i = 0; i < (int) vy.size() - 1; ++i) {
		flow.add_edge(i + 1 + (int) vx.size(), int(vx.size() + vy.size()) + 1, vy[i+1] - vy[i], 0);
	}
	for(int i = 0; i < m; ++i) {
		int x1 = in[i][0];
		int y1 = in[i][1];
		int x2 = in[i][2];
		int y2 = in[i][3];
		vector<int> xs = get(x1, x2, vx);
		vector<int> ys = get(y1, y2, vy);
		for(int a : xs) {
			for(int b : ys) {
				flow.add_edge(a + 1, b + 1 + (int) vx.size(), INF, 0);
			}
		}
	}
	// debug() << flow.get_min_cost_flow(0, int(vx.size() + vy.size() + 1));
	printf("%lld\n", flow.get_min_cost_flow(0, int(vx.size() + vy.size() + 1)).first);
}