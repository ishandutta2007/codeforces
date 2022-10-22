#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, int> piii;

const long long INF = 0x3f3f3f3f3f3f3f3f;

vector <int> B[100010], E[100010];
int s[100010], t[100010], d[100010], w[100010];
long long dp[100010][210];

int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; i++){
		scanf("%d%d%d%d", &s[i], &t[i], &d[i], &w[i]);
		B[s[i]].push_back(i), E[t[i]].push_back(i);
	}
	set <piii> now;
//	for (int i = 0; i <= m; i++){
//		dp[n + 1][i] = INF;
//	}
//	dp[n + 1][0] = 0;
	for (int i = n; i >= 1; i--){
		for (int j = 0; j < E[i].size(); j++){
			int x = E[i][j];
			now.insert(mp(mp(-w[x], -d[x]), x));
		}
		for (int j = 0; j <= m; j++){
			dp[i][j] = INF;
			// case1: pick it
			if (j){
				dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
			}
			// case2: not pick it
			int w = 0, d = i;
			if (now.size()){
				set <piii> :: iterator it = now.begin();
//				cout << w << " " << d << " " << it->se << endl;
				w = -it->fi.fi, d = -it->fi.se;
			}
//			cout << "    (" << d + 1 << ", " << j << ")->(" << i << ", " << j << ")" << endl;
			dp[i][j] = min(dp[i][j], dp[d + 1][j] + w);
		}
		for (int j = 0; j < B[i].size(); j++){
			int x = B[i][j];
			now.erase(mp(mp(-w[x], -d[x]), x));
		}
	}
	long long ans = INF;
	for (int i = 0; i <= m; i++){
		ans = min(ans, dp[1][i]);
	}
	printf("%I64d\n", ans);
	return 0;
}