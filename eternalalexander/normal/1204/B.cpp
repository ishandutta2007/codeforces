#include <bits/stdc++.h>
int l,r,n,ans=0;
int main(){
	scanf("%d%d%d",&n,&l,&r);
	ans=n-l+1;
	for (int i=1;i<=l-1;++i) ans+=(1<<i);
	printf("%d ",ans);
	ans=(1<<(r-1))*(n-r+1);
	for (int i=1;i<=r-1;++i)ans+=(1<<(i-1));
	printf("%d",ans);
	return 0;
}