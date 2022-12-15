#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const int SIZE = 1E5 + 5;

vi g[SIZE];
ii gold[SIZE];
bool visitado[SIZE];

void dfs(int p) {
	visitado[p] = true;
	for(int a : g[p]) {
		if(!visitado[a]) {
			dfs(a);
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		ll x;
		scanf("%lld", &x);
		gold[i] = ii(x, i+1);
	}
	for(int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	sort(gold, gold+n);
	ll goldNecessario = 0;
	for(int i = 0; i < n; i++) {
		if(visitado[gold[i].second]) {
			continue;
		}
		goldNecessario += gold[i].first;
		dfs(gold[i].second);
	}
	printf("%lld\n", goldNecessario);
	return 0;
}