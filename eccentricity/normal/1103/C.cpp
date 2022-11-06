#include<bits/stdc++.h>
using namespace std;
#define maxn 300000
vector<int> G[maxn];
vector<int> F[maxn];
bool vis[maxn];
int d[maxn];
int f[maxn];
int n, m, k;
vector<int> L;
void DFS(int u, int fa = 0){
	vis[u] = true;
	f[u] = fa;
	if(d[u] >= (n + k - 1) / k - 1){
		cout << "PATH" << endl;
		cout << (n + k - 1) / k << endl;
		while(u){
			cout << u << " ";
			u = f[u];
		}
		exit(0);
	}
	int c = 0;
	for(int v : G[u])
		if(vis[v] == 0){
			c += 1;
			d[v] = d[u] + 1;
			DFS(v, u);
		}
	if(c == 0){
		L.push_back(u);
		for(int v : G[u]) if(v != fa){
			F[u].push_back(v);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	while(m --){
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	DFS(1);
	if(L.size() < k){
		cout << -1;
		return 0;
	}
	cout << "CYCLES" << endl;
	for(int i = 0; i < k; i += 1){
		int dd = L[i];
		sort(F[dd].begin(), F[dd].end(), [&](const int&a, const int&b){
			return d[a] > d[b];
		});
		//cout << "dd : " << dd << endl;
		if((d[dd] - d[F[dd][0]]) % 3 != 2){
			cout << d[dd] - d[F[dd][0]] + 1 << endl;
			int p = dd;
			while(p != F[dd][0]){
				cout << p << " ";
				p = f[p];
			}
			cout << F[dd][0] << endl;
		}
		
		else if((d[dd] - d[F[dd][1]]) % 3 != 2){
			cout << d[dd] - d[F[dd][1]] + 1 << endl;
			int p = dd;
			while(p != F[dd][1]){
				cout << p << " ";
				p = f[p];
			}
			cout << F[dd][1] << endl;
		}
		else{
			cout << d[F[dd][0]] - d[F[dd][1]] + 2 << endl;
			cout << dd << " ";
			int p = F[dd][0];
			while(p != F[dd][1]){
				cout << p << " ";
				p = f[p];
			}
			cout << F[dd][1] << endl;
		}
	}
}