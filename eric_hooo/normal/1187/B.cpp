#include <bits/stdc++.h>
using namespace std;

char s[200010];
int n;
int sum[26][200010];
int cnt[26];

int main(){
	scanf("%d%s", &n, s + 1);
	for (int i = 1; i <= n; i++){
		sum[s[i] - 'a'][i] = 1;
		for (int j = 0; j < 26; j++){
			sum[j][i] += sum[j][i - 1];
		}
	}
	int m; scanf("%d", &m);
	while (m--){
		scanf("%s", s);
		int len = strlen(s);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < len; i++){
			cnt[s[i] - 'a']++;
		}
		int maxj = 0;
		for (int j = 0; j < 26; j++){
			maxj = max(maxj, int(lower_bound(sum[j] + 1, sum[j] + n + 1, cnt[j]) - sum[j]));
		}
		printf("%d\n", maxj);
	}
	return 0;
}