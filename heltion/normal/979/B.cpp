#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200000
char ans[4][maxn] = {"Kuro", "Shiro", "Katie", "Draw"}, s[maxn];
int cnt[3][52];
int max[3];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < 3; i += 1){
		scanf("%s", s);
		int m = strlen(s);
		for(int j = 0; j < m; j += 1)
			if(s[j] <= 'Z') cnt[i][s[j] - 'A'] += 1;
			else cnt[i][s[j] - 'a' + 26] += 1;
		for(int j = 0; j < 52; j += 1)
			max[i] = std::max(max[i], cnt[i][j]);
		if(n == 1 and max[i] == m and m != 1) max[i] -= 1;
		else max[i] = std::min(max[i] + n, m);
		// printf("%d\n", max[i]);
	}
	if(max[0] > max[1] and max[0] > max[2]) printf("%s", ans[0]);
	else if(max[1] > max[0] and max[1] > max[2]) printf("%s", ans[1]);
	else if(max[2] > max[0] and max[2] > max[1]) printf("%s", ans[2]);
	else printf("%s", ans[3]);
}