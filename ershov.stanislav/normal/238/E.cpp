#include <iostream>
#include <vector>

using namespace std;
#define INF 1000000000
int n, m, a, b, k, d[111][111], s[111], t[111], r[111], now, seen, used[111];
bool must[111][111];
int main()
{
	cin >> n >> m >> a >> b;
	a--, b--;
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) if (i!=j) d[i][j]=INF;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		d[u-1][v-1]=1;
	}
	cin >> k;
	for (int i=0; i<k; i++) cin >> s[i] >> t[i], s[i]--, t[i]--;
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) for (int l=0; l<n; l++) d[j][l]=min(d[j][l], d[j][i]+d[i][l]);
	for (int i=0; i<k; i++) for (int j=0; j<n; j++) {
		must[i][j]=d[s[i]][t[i]]==d[s[i]][j]+d[j][t[i]];
		for (int l=0; l<n; l++) must[i][j]&=l==j||d[s[i]][l]!=d[s[i]][j]||d[l][t[i]]!=d[j][t[i]];
	}
	for (int i=0; i<n; i++) r[i]=INF;
	r[b]=0;
	while (++now) {
		bool found=false;
		for (int i=0; i<k; i++) if (d[s[i]][t[i]]!=INF) for (int j=0; j<n; j++) if (must[i][j]&&r[j]==INF) {
			vector<int> q(1, j);
			used[j]=++seen;
			for (int l=0; l<(int)q.size(); l++) for (int z=0; z<n; z++)
				if (d[q[l]][z]==1&&r[z]>=now&&d[z][t[i]]==d[q[l]][t[i]]-1&&used[z]!=seen) {
					q.push_back(z);
					used[z]=seen;
			}
			if (used[t[i]]!=seen) r[j]=now, found=true;
		}
		if (!found) break;
	}
	if (r[a]!=INF) cout << r[a];
	else cout << -1;
	return 0;
}