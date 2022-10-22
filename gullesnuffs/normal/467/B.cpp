#include <bits/stdc++.h>

using namespace std;

int x[10005];

int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0; i <= m; ++i){
		scanf("%d", x+i);
	}
	int ans=0;
	for(int i=0; i < m; ++i){
		if(__builtin_popcount(x[i]^x[m]) <= k)
			++ans;
	}
	printf("%d\n", ans);
}