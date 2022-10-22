#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(NULL)
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define INF 1e18
#define inf 1e9
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

int n, m;
int g[111][111];
int p[1000010];
vector<int> ans;

int main() {

	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("\n");
		for(int j=1; j<=n; j++) {
			scanf("%c", &g[i][j]);
			g[i][j] -= '0';
			if(g[i][j] == 0 && i != j) g[i][j] = inf;
		}
	}

	scanf("%d", &m);
	for(int i=0; i < m; i++) {
		scanf("%d", p + i);
	}

	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}

	ans.push_back(p[0]);
	for(int i=0; i<m-1; i) {
		int j;
		//printf("!%d\n", i);
		for(j=i+1; j<m; j++) {
			if(g[p[i]][p[j]] != j - i) {
				//printf("%d %d %d\n", i, j, g[p[i]][p[j]]);
				break;
			}
			//printf("%d %d %d\n", i, j);
		}

		i = j-1;
		ans.push_back(p[i]);
	}

	printf("%d\n", ans.size());
	for(int i=0; i<ans.size(); i++) {
		printf("%d ", ans[i]);
	}
}