#include<bits/stdc++.h>
#define maxn 240000
using namespace std;
char s[maxn];
int pdx[maxn], pdy[maxn];
int sdx[maxn], sdy[maxn];
int main(){
	int n;
	scanf("%d %s", &n, s + 1);
	int x, y;
	scanf("%d %d", &x, &y);
	if(n < abs(x) + abs(y) || (x + y + n) % 2){
		printf("-1");
		return 0;
	}
	for(int i = 1; i <= n; i += 1){
		pdy[i] = pdy[i - 1];
		pdx[i] = pdx[i - 1];
		if(s[i] == 'U') pdy[i] += 1;
		if(s[i] == 'D') pdy[i] -= 1;
		if(s[i] == 'L') pdx[i] -= 1;
		if(s[i] == 'R') pdx[i] += 1;
	}
	for(int i = n; i >= 1; i -= 1){
		sdy[i] = sdy[i + 1];
		sdx[i] = sdx[i + 1];
		if(s[i] == 'U') sdy[i] += 1;
		if(s[i] == 'D') sdy[i] -= 1;
		if(s[i] == 'L') sdx[i] -= 1;
		if(s[i] == 'R') sdx[i] += 1;
	}
	int ans = maxn;
	for(int i = 0; i <= n; i += 1){
		if(abs(pdx[i] - x) + abs(pdy[i] - y) > n - i) break;
		int L = i + 1, R = n + 1;
		while(L < R){
			int M = (L + R) / 2;
			if(abs(pdx[i] + sdx[M] - x) + abs(pdy[i] + sdy[M] - y) <= M - i - 1)
				R = M;
			else L = M + 1;
			//printf("%d %d\n", i, M);
		}
		ans = min(ans, L - i - 1);
	}
	printf("%d", ans);
}