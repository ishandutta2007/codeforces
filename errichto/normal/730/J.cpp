#include <bits/stdc++.h>
using namespace std;
const int nax = 105;
const int inf = 1e9 + 5;
pair<int,int> t[nax];
int dp[nax][nax*nax];
void maxi(int & a, int b) { a = max(a, b); }
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", &t[i].first);
	for(int i = 0; i < n; ++i) scanf("%d", &t[i].second);
	int s = 0;
	for(int i = 0; i < n; ++i) s += t[i].first;
	sort(t, t + n, [](pair<int,int> a, pair<int,int> b) {
		return a.second > b.second;
	});
	int k = 0;
	int tmp = 0;
	while(tmp < s) {
		tmp += t[k].second;
		++k;
	}
	for(int i = 0; i < nax; ++i) for(int j = 0; j < nax * nax; ++j) dp[i][j] = -inf;
	dp[0][0] = 0;
	for(int i = 0; i < nax; ++i) {
		for(int used = n - 1; used >= 0; --used)
			for(int s_vol = 0; s_vol + t[i].second < nax * nax; ++s_vol)
				maxi(dp[used+1][s_vol + t[i].second], dp[used][s_vol] + t[i].first);
	}
	int ss = 0;
	for(int i = 0; i < n; ++i) ss += t[i].first;
	int best = 0;
	for(int i = s; i < nax * nax; ++i) maxi(best, dp[k][i]);
	printf("%d %d\n", k, ss - best);
	
}