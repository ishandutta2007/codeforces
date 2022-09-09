#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define maxn 120000
vector<int> G[maxn];
bool vis[maxn];
priority_queue<int, vector<int>, greater<int> > q;
int main(){
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i += 1){
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	q.push(1);
	vis[1] = true;
	while(q.empty() == false){
		int u = q.top();
		q.pop();
		cout << u << " ";
		for(int v : G[u]) if(vis[v] == false){
			q.push(v);
			vis[v] = true;
		}
	}
}