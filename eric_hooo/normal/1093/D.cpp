#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

vector <int> from[300010];
int vis[300010], a, b;

long long power(long long a, long long b){
	if (b == 0) return 1;
	long long t = power(a, b / 2);
	if (b & 1) return t * t % mod * a;
	return t * t % mod;
}

int dfs(int x, int p){
//	cout << "  " << x << " " << p << endl;
	vis[x] = p;
	if (p == 1) a++;
	else b++;
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i];
		if (v == x) continue;
//		cout << "    " << v << " " << vis[v] << " " << (p == 1 ? 2 : 1) << endl;
//		cout << "    " << ((p == 1 ? 2 : 1) != vis[v]) << endl;
//		cout << "    " << !vis[v] << endl;
		if (!vis[v]){
			if (dfs(v, p == 1 ? 2 : 1) == 0) return 0;
		}
		else if (vis[v] != (p == 1 ? 2 : 1)) return 0;
//		cout << "POS" << endl;
	}
	return 1;
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++){
			from[i].clear(), vis[i] = 0;
		}
		for (int i = 0; i < m; i++){
			int u, v;
			scanf("%d%d", &u, &v);
			from[u].push_back(v);
			from[v].push_back(u);
		}
		long long res = 1;
		for (int i = 1; i <= n; i++){
			if (vis[i]) continue;
			a = b = 0;
			if (!dfs(i, 1)){
				res = 0;
				break;
			}
			res = res * ((power(2, a) + power(2, b)) % mod) % mod;
		}
		printf("%I64d\n", res);
	}
	return 0;
}