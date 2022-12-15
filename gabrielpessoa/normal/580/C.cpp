#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, double> id;
typedef vector<id> vid;
typedef pair<double, int> di;
typedef vector<di> vdi;
typedef pair<ll, ll> llp;
typedef pair<string, string> ss;

const int SIZE  = 1E5+5;
const int MOD = 1E9 + 7;
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;

vi g[SIZE];
int cat[SIZE];

int dfs(int pos, int vimDe, int gatos, int gatosMaximo) {
	if(cat[pos]) {
		if(gatos++ == gatosMaximo) return 0;
	} else {
		gatos = 0;
	}
	if(g[pos].size() == 1 && g[pos][0] == vimDe) {
		return 1;
	}
	int total = 0;
	for(int a : g[pos]) {
		if(a == vimDe) continue;
		total += dfs(a, pos, gatos, gatosMaximo);
	}
	return total;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &cat[i]);
	}
	for(int i = 1; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	printf("%d\n", dfs(1, 0, 0, m));
	return 0;
}