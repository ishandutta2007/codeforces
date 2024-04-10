#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

using namespace std;

int n,m;
int seen[210000];
int tot[210000];
vector< pair<pii, int> > g[210000];
int ans[210000];

int main() {
	memset(ans,-1,sizeof(ans));

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a,b,c;
		scanf("%d %d %d", &a, &b, &c); a--; b--;
		g[a].push_back({ {b,c}, i});
		g[b].push_back({ {a,c},-i});
		tot[a] += c;
		tot[b] += c;
	}

	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (pair<pii, int> p : g[cur]) {
			int dest = p.first.first, cost = p.first.second;
			if (ans[abs(p.second)] == -1) {
				if (p.second < 0) ans[-p.second]=1;
				else ans[p.second]=0;

				tot[dest] -= 2*cost;
				if (tot[dest] == 0 && dest != n-1) q.push(dest);
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		printf("%d\n", ans[i]);
	}
}