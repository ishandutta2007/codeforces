#include<iostream>
#include<cstdio>

using namespace std;

int n,a[200001],f[200001],ans=1;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	f[1]=1;for(int i=2;i<=n;++i){if(a[i-1]<<1>=a[i])f[i]=f[i-1]+1;else f[i]=1;ans=max(ans,f[i]);}
	printf("%d\n",ans);
}