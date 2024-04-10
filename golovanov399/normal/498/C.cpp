#include <bits/stdc++.h>

// #include "Flow.h"

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

struct Network{

	struct Edge {
		int from, to, cap, flow;

		Edge(int fr, int to, int cap, int fl = 0):
			from(fr),to(to),cap(cap),flow(fl){}
	};

	int n;
	int s, t;
	vector<Edge> edges;
	vector<vector<int>> a;
	vector<int> ptr;

	Network(int n, int s, int t):n(n),s(s),t(t){
		a.resize(n);
		ptr.resize(n);
	}

	void add_edge(int from, int to, int cap){
		int num = edges.size();
		edges.push_back(Edge(from, to, cap));
		edges.push_back(Edge(to, from, 0));
		a[from].push_back(num);
		a[to].push_back(num + 1);
	}

	int push(int v, int limit){
		if (v == t)
			return limit;
		if (limit == 0)
			return 0;
		int res = 0;
		while (ptr[v] < a[v].size() && limit){
			int pos = a[v][ptr[v]];
			int to = edges[pos].to;
			int lm = min(limit, edges[pos].cap - edges[pos].flow);
			ptr[v]++;
			int flow = push(to, lm);
			limit -= flow;
			res += flow;
			edges[pos].flow += flow;
			edges[pos ^ 1].flow -= flow;
		}
		return res;
	}

	int get_flow(){
		int res = 0;
		while (true){
			for (int i = 0; i < n; i++)
				ptr[i] = 0;
			int flow = push(0, INT_MAX / 10);
			if (flow == 0)
				break;
			res += flow;
		}
		return res;
	}

	void show_flow() const {
		vector<vector<int>> out(n);
		for (int i = 0; i < edges.size(); i += 2){
			if (edges[i].flow == 0)
				continue;
			int j = i;
			if (edges[i].flow < 0)
				j++;
			out[edges[j].from].push_back(j);
		}
		for (int i = 0; i < n; i++){
			for (int j : out[i]){
				cerr << i << " -> " << edges[j].to << " (" << edges[j].flow << "/" << edges[j].cap << ")\n";
			}
		}
	}
};

int main(){

	// check_perfect_matching();

	int n = nxt(), m = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		a[i] = nxt();
	}
	vector<int> divs;
	for (int i = 0; i < n; i++){
		int x = a[i];
		for (int j = 2; j * j <= x; j++){
			if (x % j == 0){
				divs.push_back(j);
				while (x % j == 0)
					x /= j;
			}
		}
		if (x > 1)
			divs.push_back(x);
	}
	sort(all(divs));
	divs.resize(unique(all(divs)) - divs.begin());

	vector<pair<int, int>> ar(m);
	for (int i = 0; i < m; i++){
		ar[i].first = nxt() - 1, ar[i].second = nxt() - 1;
		if (ar[i].first % 2)
			swap(ar[i].first, ar[i].second);
	}

	int ans = 0;
	for (int g : divs){
		Network network(n + 2, 0, n + 1);
		for (int i = 0; i < n; i++){
			int x = 0;
			while (a[i] % g == 0){
				a[i] /= g;
				x++;
			}
			if (i % 2 == 0)
				network.add_edge(0, i + 1, x);
			else
				network.add_edge(i + 1, n + 1, x);
		}
		for (int i = 0; i < m; i++)
			network.add_edge(ar[i].first + 1, ar[i].second + 1, 100);
		ans += network.get_flow();
		// network.show_flow();
		// cerr << "------------\n";
	}

	cout << ans << "\n";

	return 0;
}