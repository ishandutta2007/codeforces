/*2007*/
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:1000000000")
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <random>
#include <time.h>
#include <queue>

using namespace std;

void pass(){
	return;
}

#define int long long
#define rand() (rand()<<15+rand())
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-6;

mt19937 rnd(time(NULL));
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 107;
const int MAXM = 10007;

struct Edge{
	int v, c, f, ref;
};

vector <Edge> g[MAXN];
vector <Edge> tree[MAXN];
int counter[MAXN];

Edge init(int v, int c, int f, int ref){
	Edge res;
	res.v = v;
	res.c = c;
	res.f = f;
	res.ref = ref;
	return res;
}

vector <int> dist;

bool bfs(int s, int t, int minc){
	for (int i = 0; i < MAXN; ++i) counter[i] = 0;

	dist.assign(MAXN, MOD);
	queue <int> q;
	q.push(s);
	dist[s] = 0;
	while (q.size()){
		int u = q.front();
		q.pop();
		for (Edge e : g[u]){
			if (e.c - e.f < minc) continue;
			if (dist[u] + 1 < dist[e.v]){
				dist[e.v] = dist[u] + 1;
				q.push(e.v);
			}
		}
	}
	return dist[t] != MOD;
}

int dfs(int u, int t, int minc, int flow){
	if (u == t) return flow;

	for (int i = counter[u]; i < g[u].size(); ++i){
		Edge *e = &g[u][i];

		if (e->f == e->c || dist[u] + 1 != dist[e->v] || e->c - e->f < minc){
			counter[u]++;
			continue;
		}
		else{
			int new_flow = dfs(e->v, t, minc, min(flow, e->c - e->f));
			if (!new_flow){
				counter[u]++;
				continue;
			}
			else{
				e->f += new_flow;
				g[e->v][e->ref].f -= new_flow;
				return new_flow;
			}
		}

	}

	return 0;
}

int dinic(int n, int s, int t){
	int minc = 1LL << 61;
	int ans = 0;
	while (minc){

		for (int i = 0; i < n + 7; ++i){
			bfs(s, t, minc);

			while (true){
				int flow = dfs(s, t, minc, MOD);
				ans += flow;
				if (!flow) break;
			}

		}

		minc /= 2;
	}

	return ans;
}

struct Card{
	int p, c, l;
};

Card a[MAXN];

bool prime(int n){
	for (int d = 2; d * d <= n; ++d){
		if (n % d == 0) return false;
	}
	return true;
}

bool comp(Card a, Card b){
	return a.p > b.p;
}

pair <int, int> build(int n, int k){
	for (int i = 0; i < MAXN; ++i) g[i] = {};
	vector <Card> a1;
	for (int i = 0; i < n; ++i){
		if (a[i].l <= k){
			a1.push_back(a[i]);
		}
	}
	sort(a1.begin(), a1.end(), comp);

	bool flag = false;
	vector <Card> a2;
	for (int i = 0; i < a1.size(); ++i){
		if (!(a1[i].c == 1 && flag)) a2.push_back(a1[i]);
		flag |= (a1[i].c == 1);
	}

	vector <Card> even, odd;
	int res = 0;
	for (int i = 0; i < a2.size(); ++i){
		res += a2[i].p;
		if (a2[i].c % 2){
			odd.push_back(a2[i]);
		}
		else{
			even.push_back(a2[i]);
		}
	}

	int s1 = odd.size();
	int s2 = even.size();

	for (int i = 0; i < odd.size(); ++i){
		g[0].push_back(init(1 + i, odd[i].p, 0, g[1 + i].size()));
		g[1 + i].push_back(init(0, 0, 0, g[0].size() - 1));
	}

	for (int i = 0; i < even.size(); ++i){
		g[1 + s1 + i].push_back(init(1 + s1 + s2, even[i].p, 0, g[1 + s1 + s2].size()));
		g[1 + s1 + s2].push_back(init(1 + s1 + i, 0, 0, g[1 + s1 + i].size() - 1));
	}

	for (int i = 0; i < odd.size(); ++i){
		for (int j = 0; j < even.size(); ++j){
			if (prime(odd[i].c + even[j].c)){
				g[1 + i].push_back(init(1 + s1 + j, MOD, 0, g[1 + s1 + j].size()));
				g[1 + s1 + j].push_back(init(1 + i, 0, 0, g[1 + i].size() - 1));
			}
		}
	}

	return{ res, a2.size() + 2 };
}

bool check(int n, int m, int k){
	auto tmp = build(n, m);
	return tmp.first - dinic(n + 2, 0, tmp.second - 1) >= k;
}

signed main(){
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i){
		cin >> a[i].p >> a[i].c >> a[i].l;
	}

	int l = 0;
	int r = MAXN;
	while (l < r - 1){
		int m = (l + r) / 2;
		if (check(n, m, k)){
			r = m;
		}
		else{
			l = m;
		}
	}

	if (r == MAXN) cout << "-1\n";
	else cout << r << '\n';
	return 0;
}