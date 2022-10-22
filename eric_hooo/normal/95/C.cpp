#include <bits/stdc++.h>
using namespace std;

const long long INF = 1ll * 0x3f3f3f3f * 0x3f3f3f3f;

struct Node{
	int to;
	long long dis;
	Node(){}
	Node(int a, long long b){
		to = a;
		dis = b;
	}
	bool operator < (const Node &A) const{
		return dis > A.dis;
	}
};

vector <Node> from[1010];
vector <Node> from2[1010];
long long dis[1010];
int n, m;
int vis[1010]; 
queue <int> q;

void spfa(int pos){
	for (int i = 1; i <= n; i++){
		dis[i] = INF, vis[i] = 0;
	}
	dis[pos] = 0;
	while (!q.empty()) q.pop();
	
	q.push(pos), vis[pos] = 1;
	
	while (!q.empty()){
		int u = q.front(); q.pop(), vis[u] = 0;
		for (int i = 0; i < from[u].size(); i++){
			Node tmp = from[u][i];
			int v = tmp.to;
			if (dis[v] > tmp.dis + dis[u]){
				dis[v] = tmp.dis + dis[u];
				if (!vis[v]) q.push(v), vis[v] = 1;
			}
		}
	}
}

void spfa2(int pos){
	for (int i = 1; i <= n; i++){
		dis[i] = INF, vis[i] = 0;
	}
	dis[pos] = 0;
	while (!q.empty()) q.pop();
	
	q.push(pos), vis[pos] = 1;
	
	while (!q.empty()){
		int u = q.front(); q.pop(), vis[u] = 0;
		for (int i = 0; i < from2[u].size(); i++){
			Node tmp = from2[u][i];
			int v = tmp.to;
			if (dis[v] > dis[u] + tmp.dis){
				dis[v] = dis[u] + tmp.dis;
				if (!vis[v]) q.push(v), vis[v] = 1;
			}
		}
	}
}

int main(){
	cin >> n >> m;
	int s, t;
	cin >> s >> t;
	for (int i = 0; i < m; i++){
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		from[u].push_back(Node(v, c));
		from[v].push_back(Node(u, c));
	}
	for (int i = 1; i <= n; i++){
		int t, c;
		scanf("%d%d", &t, &c);
		spfa(i);
		from2[i].push_back(Node(i, 0));
		for (int j = 1; j <= n; j++){
			if (dis[j] <= t) from2[i].push_back(Node(j, c));
		}
	}
	spfa2(s);
	cout << (dis[t] == INF ? -1 : dis[t]) << endl;
	return 0;
}