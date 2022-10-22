#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <long long, long long> pii;

char buf[500010];
int a[100010];

string read(){
	scanf("%s", buf);
	return buf;
}

string change(string s){
	for (int i = 0; i < s.length(); i++){
		if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 'a' - 'A';
	}
	return s;
}

map <string, int> MP;
int tot = 1, cnt = 1, all;
vector <int> from[300010];
vector <int> g[300010];
int id[300010], low[300010], ins[300010], scc[300010], in[300010];
vector <int> s;
pii dp[300010];
string name[300010];

int get_id(string s){
	if (MP.count(s)) return MP[s];
	MP[s] = tot++;
	name[tot - 1] = s;
	return tot - 1;
}

int countR(int id){
	int ans = 0;
	for (int i = 0; i < name[id].size(); i++){
		if (name[id][i] == 'r') ans++;
	}
	return ans;
}

void dfs(int x){
//	cout << "dfs:" << x << endl;
	low[x] = id[x] = cnt++;
	s.push_back(x), ins[x] = 1;
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i];
		if (!id[v]){
			dfs(v);
			low[x] = min(low[x], low[v]);
		} else if (ins[v]) low[x] = min(low[x], id[v]);
	}
	if (low[x] != id[x]) return ;
	dp[all] = mp(countR(x), name[x].size());
	while (1){
		int v = s.back(); s.pop_back(), ins[v] = 0;
		scc[v] = all;
		dp[all] = min(dp[all], mp((long long)countR(v), (long long)name[v].size()));
		if (x == v) break;
	}
	all++;
}

int main(){
	int m, n;
	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		string s = read();
		s = change(s), a[i] = get_id(s);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		string a = read(), b = read();
		a = change(a), b = change(b);
		int x = get_id(a), y = get_id(b);
		from[x].push_back(y);
	}
	for (int i = 1; i < tot; i++){
		if (!id[i]) dfs(i);
	}
	for (int u = 1; u < tot; u++){
		for (int j = 0; j < from[u].size(); j++){
			int v = from[u][j];
			if (scc[u] == scc[v]) continue;
			in[scc[v]]++;
			g[scc[u]].push_back(scc[v]);
		}
	}
	queue <int> q;
	vector <int> order;
	for (int i = 0; i < all; i++){
		if (!in[i]) q.push(i);
	}
	while (!q.empty()){
		int u = q.front(); q.pop();
		order.push_back(u);
		for (int i = 0; i < g[u].size(); i++){
			int v = g[u][i];
			in[v]--;
			if (in[v] == 0) q.push(v);
		}
	}
	reverse(order.begin(), order.end());
	for (int i = 0; i < order.size(); i++){
		int x = order[i];
		for (int j = 0; j < g[x].size(); j++){
			int v = g[x][j];
			dp[x] = min(dp[x], dp[v]);
		}
	}
	pii ans(0, 0);
	for (int i = 0; i < m; i++){
		ans.fi += dp[scc[a[i]]].fi, ans.se += dp[scc[a[i]]].se;
	}
	printf("%I64d %I64d\n", ans.fi, ans.se);
	return 0;
}