#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int INF = 0x3f3f3f3f;

typedef pair <int, int> pii;
typedef pair <pii, int> piii; 

vector <piii> task;
int head[5010], vis[5010], dist[5010], path[5010], edge[5010];
int nxt[100010], to[100010], w[100010], f[100010];
int tot, n, k;
queue <int> q;

void add(int u, int v, int W, int F){
	to[tot] = v, w[tot] = W, f[tot] = F, nxt[tot] = head[u], head[u] = tot++;
}

bool spfa(int s, int t){
	memset(dist, INF, sizeof(dist));
	memset(path, -1, sizeof(path));
	q.push(s), vis[s] = 1, dist[s] = 0;
	while (!q.empty()){
		int u = q.front(); q.pop();
		vis[u] = 0;
		for (int i = head[u]; ~i; i = nxt[i]){
			int v = to[i];
			if (!w[i]) continue;
			if (dist[v] > dist[u] + f[i]){
				dist[v] = dist[u] + f[i];
				path[v] = u, edge[v] = i;
				if (!vis[v]) q.push(v), vis[v] = 1;
			}
		}
	}
	return ~path[t];
}

int min_cost(int s, int t){
	int res = 0;
	while (spfa(s, t)){
		int now = t, flow = INF;
		while (now != s){
			int e = edge[now];
			flow = min(flow, w[e]);
			now = path[now];
		}
		res += flow * dist[t];
		now = t;
		while (now != s){
			int e = edge[now];
			w[e] -= flow, w[e ^ 1] += flow;
			now = path[now];
		}
	}
	return res;
}

int in(int x){return 2 * x;}
int out(int x){return 2 * x + 1;}
int Time(int x){return 2 * n + x;}

int main(){
	memset(head, -1, sizeof(head));
	scanf("%d%d", &n, &k);
	vector <int> all;
	for (int i = 0; i < n; i++){
		int s, t, c;
		scanf("%d%d%d", &s, &t, &c);
		all.push_back(s), all.push_back(s + t - 1);
		task.push_back(mp(mp(s, t), c));
	}
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
	int S = 2 * n + all.size() + 1, SS = S + 1, T = SS + 1;
	for (int i = 0; i < n; i++){
		int s = task[i].fi.fi, t = s + task[i].fi.se - 1, c = task[i].se;
		int p1 = lower_bound(all.begin(), all.end(), s) - all.begin();
		int p2 = lower_bound(all.begin(), all.end(), t) - all.begin() + 1;
		add(Time(p1), in(i), INF, 0), add(in(i), Time(p1), 0, 0);
		add(out(i), Time(p2), INF, 0), add(Time(p2), out(i), 0, 0);
		add(in(i), out(i), 1, -c), add(out(i), in(i), 0, c);
	}
	for (int i = 0; i < all.size(); i++){
		add(Time(i), Time(i + 1), INF, 0);
		add(Time(i + 1), Time(i), 0, 0);
	}
	add(S, SS, k, 0), add(SS, S, 0, 0);
	add(SS, Time(0), INF, 0), add(Time(0), SS, 0, 0);
	add(Time(all.size()), T, INF, 0), add(T, Time(all.size()), 0, 0);
	min_cost(S, T);
	for (int i = 0; i < n; i++){
		int j = head[in(i)];
		while (to[j] != out(i)) j = nxt[j];
		if (w[j] == 0) printf("1 ");
		else printf("0 ");
	}
	printf("\n");
	return 0;
}