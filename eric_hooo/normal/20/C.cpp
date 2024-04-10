#include <bits/stdc++.h>
using namespace std;

const long long INF = 1ll * 0x3f3f3f3f * 0x3f3f3f3f;

struct Node{
	int to;
	long long dis;
	Node(){}
	Node(int _to, long long _dis){to = _to, dis = _dis;}
	bool operator < (const Node &A) const{
		return dis > A.dis;
	}
};

vector <Node> from[100010];
priority_queue <Node> q;
long long dis[100010];
int P[100010];
int n;

void Dij(int pos){
	for (int i = 1; i <= n; i++){
		dis[i] = INF;
	}
	dis[pos] = 0, P[pos] = 0;
	q.push(Node(pos, 0));
	while (!q.empty()){
		Node t = q.top(); q.pop();
		int u = t.to;
		if (t.dis != dis[u]) continue;
		for (int i = 0; i < from[u].size(); i++){
			Node tmp = from[u][i];
			int v = tmp.to;
			if (dis[v] > dis[u] + tmp.dis){
				dis[v] = dis[u] + tmp.dis, P[v] = u;
				q.push(Node(v, dis[v]));
			}
		}
	}
}

void print(int x){
	if (x == 0) return ;
	print(P[x]);
	printf("%d ", x);
}

int main(){
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		from[u].push_back(Node(v, w));
		from[v].push_back(Node(u, w));
	}
	Dij(1);
	if (dis[n] == INF) cout << -1 << endl;
	else print(n);
	printf("\n");
	return 0;
}