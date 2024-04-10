#include <bits/stdc++.h>

int c1[8]={0},c2[8]={0},n,m,t;
long long ans=0;

int main(){
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)c1[i%5]++;
	for(int i=1;i<=m;++i)c2[i%5]++;
	for(int i=1;i<5;++i){
	//	printf("%d %d\n",c1[i],c2[5-i-1]);
		ans+=(long long)c1[i]*c2[5-i];
	}ans+=(long long)c1[0]*c2[0];
	std::cout<<ans;
	return 0;
}