#include <bits/stdc++.h>

void solve(){
	int x,n,y,c[2]={0};
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;++i){
		scanf("%d",&y);
		c[y%2]++;
	}
	for(int i=0;i<=x;++i){
		int j = x-i;
		if ( i > c[1] || j > c[0]) continue;
		if ( 1 * i % 2 == 1) { puts("YES"); return ; }
	}
	puts("NO");
}

int main(){
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}