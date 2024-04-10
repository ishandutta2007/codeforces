#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 444444;
vector<int> a[N];
vector<int> sz[N];
vector<int> mx[N];
int p[N];
int n;

int dfs(int v, int pr = -1){
	int res = 1;
	sz[v].resize(a[v].size());
	for (int i = 0; i < a[v].size(); i++){
		if (a[v][i] == pr){
			p[v] = i;
			continue;
		}
		res += (sz[v][i] = dfs(a[v][i], v));
	}
	return res;
}

int dfs1(int v){
	int res = 0;
	mx[v].resize(a[v].size());
	for (int i = 0; i < a[v].size(); i++){
		if (i == p[v])
			continue;
		mx[v][i] = dfs1(a[v][i]);
		if (sz[v][i] <= n / 2)
			mx[v][i] = max(mx[v][i], sz[v][i]);
		res = max(res, mx[v][i]);
	}
	return res;
}

void dfs2(int v){
	pair<int, int> _mx(0, 0);
	for (int i = 0; i < a[v].size(); i++){
		int x = mx[v][i];
		if (x > _mx.first){
			_mx.second = _mx.first;
			_mx.first = x;
		} else if (x > _mx.second){
			_mx.second = x;
		}
	}
	for (int i = 0; i < a[v].size(); i++){
		if (i == p[v])
			continue;
		int x = (mx[v][i] == _mx.first) ? _mx.second : _mx.first;
		if (sz[a[v][i]][p[a[v][i]]] <= n / 2)
			x = max(x, sz[a[v][i]][p[a[v][i]]]);
		mx[a[v][i]][p[a[v][i]]] = x;
		dfs2(a[v][i]);
	}
}

int main(){

	n = nxt();
	for (int i = 0; i < n - 1; i++){
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	p[0] = -1;
	dfs(0);

	for (int i = 0; i < n; i++){
		for (int j = 0; j < a[i].size(); j++){
			if (j == p[i])
				continue;
			sz[a[i][j]][p[a[i][j]]] = n - sz[i][j];
		}
	}

	dfs1(0);
	dfs2(0);

	// for (int i = 0; i < n; i++){
	// 	for (int j = 0; j < a[i].size(); j++){
	// 		cerr << i + 1 << " -- " << a[i][j] + 1 << ": " << mx[i][j] << "\n";
	// 	}
	// }

	for (int i = 0; i < n; i++){
		int bad_cnt = 0;
		int lst = -1;
		for (int j = 0; j < a[i].size(); j++){
			if (sz[i][j] > n / 2){
				bad_cnt++;
				lst = j;
			}
		}
		if (bad_cnt > 1){
			printf("%d ", 0);
		} else
		if (bad_cnt == 0){
			printf("%d ", 1);
		} else {
			printf("%d ", (sz[i][lst] - mx[i][lst] > n / 2) ? 0 : 1);
		}
	}
	printf("\n");

	return 0;
}