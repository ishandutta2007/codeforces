#include <bits/stdc++.h>
int n,m,l,r,d[1000000];
int main(){
	scanf("%d%d",&n,&m);
	while (m--){
		scanf("%d%d",&l,&r);
		d[l]++;d[r+1]--;
	}for(int i=1;i<=n;++i)d[i]+=d[i-1];
	for(int i=1;i<=n;++i){
		if (d[i]!=1){printf("%d %d\n",i,d[i]);return 0;
	}}printf("OK");return 0;
}