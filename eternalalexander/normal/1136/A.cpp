#include <bits/stdc++.h>
int n,x,l[10000],r[10000];
int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&l[i],&r[i]);
	scanf("%d",&x);
	for(int i=1;i<=n;++i)if(r[i]>=x){printf("%d ",n-i+1);return 0;}
}