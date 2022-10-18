#include <bits/stdc++.h>
#define maxn 1000005
int n,max,t,a[maxn]={0},f[maxn];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);
	f[0]=1;
	for(int i=1;i<=n;++i){
		if (a[i]!=a[i-1]){
			f[i]=f[i-1]+1;a[i]=a[i-1]+1;
		}else f[i]=f[i-1];
	}printf("%d",f[n]);	
	return 0;
}