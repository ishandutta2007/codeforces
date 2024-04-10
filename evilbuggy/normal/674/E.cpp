#include <bits/stdc++.h>
using namespace std;

const int K = 65;
const int N = 500005;

int parent[N];
double p[N][K], ans[N];

void update(int v){
	ans[v] = 0.0;
	p[v][0] = 1.0;
	for(int i = 1; i < K; i++){
		p[v][i] = 0.0;
	}
	double prev = 0.0;
	for(int i = 1; i < K; i++){
		int u = parent[v];
		if(u == 0)break;

		double tmp = p[u][i];
		ans[u] -= p[u][i];
		p[u][i] = 1 - (1 - p[u][i])/(1 - 0.5*prev)*(1 - 0.5*p[v][i - 1]);
		ans[u] += p[u][i];
		prev = tmp; v = u;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;
	parent[1] = 0;
	for(int i = 0; i < K; i++){
		p[1][i] = 0.0;
	}
	ans[1] = 0.0;
	p[1][0] = 1.0;

	int n = 2;
	while(q--){
		int type, v;
		cin >> type >> v;
		if(type == 1){
			parent[n] = v;
			update(n); ++n;
		}else{
			cout << fixed << setprecision(12) << ans[v] << '\n';
		}
		// for(int i = 1; i < n; i++){
		// 	for(int j = 0; j < n; j++){
		// 		cout << p[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;
	}

	return 0;
}