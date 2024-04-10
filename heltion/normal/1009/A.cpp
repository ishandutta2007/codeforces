#include<bits/stdc++.h>
using namespace std;
#define maxn 1000
int c[maxn], w[maxn];
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i += 1) scanf("%d", c + i);
	for(int i = 0; i < m; i += 1) scanf("%d", w + i);
	int p = 0, q = 0, ans = 0;
	while(p < m && q < n){
		if(w[p] >= c[q]) ans += 1, q += 1, p += 1;
		else q += 1;
	}
	printf("%d\n", ans);
}