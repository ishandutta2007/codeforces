#include <bits/stdc++.h>
using namespace std;
const int nbits = 30;

int gauss[nbits];

void add(int w){
	for (int i = nbits - 1; i >= 0; i--){
		if(gauss[i] == 0 && (w&(1<<i))){
			gauss[i] = w;
			break;
		} else {
			w = min(w, w ^ gauss[i]);
		}
	}
}

int query(int w){
	for(int i = nbits - 1; i >= 0; i--)
		w = min(w, w ^ gauss[i]);
	return w;
}	

const int maxn = 100100;

vector<pair<int, int> > e[maxn];
int dist[maxn], vis[maxn];

void dfs(int cur, int p){
	vis[cur] = 1;
	for(auto edge : e[cur]){
		if(vis[edge.first]){
			int cost = dist[cur] ^ dist[edge.first] ^ edge.second;
			add(cost);
		} else {
			dist[edge.first] = dist[cur] ^ edge.second;
			dfs(edge.first, cur);
		}
	}
}
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		e[u].push_back(make_pair(v,w));
		e[v].push_back(make_pair(u,w));
	}
	dfs(1, 0);
	cout << query(dist[n]) << endl;
	return 0;
}