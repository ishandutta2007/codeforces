#include<bits/stdc++.h>
#define maxn 12
#define maxk 100
using namespace std;
int w[maxn], cnt[1 << maxn];
char s[maxn + 1];
pair<int, int> p[1 << maxn];
int ans[1 << maxn][maxk + 1];
int bit(int n){
	int result = 0;
	for(int i = 0; i < n; i += 1) result = result * 2 + s[i] - '0';
	return result;
}
int main(){
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 0; i < n; i += 1) scanf("%d", w + i);
	for(int i = 0; i < m; i += 1){
		scanf("%s", s);
		cnt[bit(n)] += 1;
	}
	for(int i = 0; i < (1 << n); i += 1){
		p[i].second = i;
		for(int j = 0; j < n; j += 1) if(i & (1 << (n - j - 1))) p[i].first += w[j];
	}
	sort(p, p + (1 << n));
	int inv = (1 << n) - 1;
	for(int i = 0; i < (1 << n); i += 1){
		for(int j = 0; j < (1 << n); j += 1)
			if(p[j].first <= 100)
				ans[i][p[j].first] += cnt[i ^ p[j].second ^ inv];
		for(int k = 1; k <= 100; k += 1)
			ans[i][k] += ans[i][k - 1];
	}
	for(int i = 0; i < q; i += 1){
		int k;
		scanf("%s %d", s, &k);
		printf("%d\n", ans[bit(n)][k]);
	}
}