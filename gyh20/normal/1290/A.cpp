#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int t,n,a[3505],m,k,ans;
inline int work(int l,int r,int x){
	int kk=1e9;
	for(int i=0;i<=x;++i){
		kk=min(kk,max(a[l+i],a[r-x+i]));
	}
	return kk;
}
signed main(){
scanf("%d",&t);
while(t--){
	scanf("%d%d%d",&n,&m,&k);
	if(k>=m)k=m-1;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	m-=k;
	m-=1;
	ans=0;
	for(int i=0;i<=k;++i){
		ans=max(ans,work(i+1,n-k+i,m));
	}
	printf("%d\n",ans);
}
}