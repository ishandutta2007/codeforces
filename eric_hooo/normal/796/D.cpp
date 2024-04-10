#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

struct Node{
	int x, dis;
	Node(){}
	Node(int _x, int _dis){x = _x, dis = _dis;}
};

int p[300010];
vector <int> from[300010];
map <pair <int, int>, int> m;
queue <Node> q;
int vis[300010], ans[300010];

int main(){
	int n, k, d;
	scanf("%d%d%d", &n, &k, &d);
	for (int i = 0; i < k; i++){
		scanf("%d", &p[i]);
	}
	for (int i = 1; i < n; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		m[mp(u, v)] = m[mp(v, u)] = i;
		from[u].push_back(v);
		from[v].push_back(u);
	}
	for (int i = 0; i < k; i++){
		q.push(Node(p[i], d));
		vis[p[i]] = 1;
	}
	while (!q.empty()){
		Node t = q.front(); q.pop();
		int u = t.x; t.dis--;
		for (int i = 0; i < from[u].size(); i++){
			int v = from[u][i];
			if (vis[v]) continue;
			vis[v] = 1, ans[m[mp(u, v)]] = 1;
			q.push(Node(v, t.dis));
		}
	}
	int tot = 0;
	for (int i = 1; i < n; i++){
		if (!ans[i]) tot++;
	}
	printf("%d\n", tot);
	for (int i = 1; i < n; i++){
		if (!ans[i]) printf("%d ", i);
	}
	printf("\n");
	return 0;
}