#include<bits/stdc++.h>
#define maxn 1200
using namespace std;
const int INF = 100000000;
int f[2][8];
char s[4];
int main(){
	int n;
	scanf("%d", &n);
	fill(f[0] + 1, f[0] + 8, INF);
	for(int i = 1; i <= n; i += 1){
		int c, m = 0;
		scanf("%d %s", &c, s);
		copy(f[i & 1 ^ 1], f[i & 1 ^ 1] + 8, f[i & 1]);
		for(int j = 0; s[j]; j ++)
			m |= 1 << s[j] - 'A';
		for(int j = 0; j < 8; j += 1)
			f[i & 1][j | m] = min(f[i & 1][j | m], f[i & 1][j] + c);
	}
	printf("%d", f[n & 1][7] == INF ? -1 : f[n & 1][7]);
}