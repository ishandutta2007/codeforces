#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int inf=2147483647;
int n;
#define Maxn 300010
int l[Maxn],r[Maxn];
int lmax1[Maxn],lmax2[Maxn],rmin1[Maxn],rmin2[Maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&l[i],&r[i]);
	lmax1[0]=0;rmin1[0]=inf;
	for(int i=1;i<=n;++i){
		lmax1[i]=max(lmax1[i-1],l[i]);
		rmin1[i]=min(rmin1[i-1],r[i]);
	}
	lmax2[n+1]=0;rmin2[n+1]=inf;
	for(int i=n;i>=1;--i){
		lmax2[i]=max(lmax2[i+1],l[i]);
		rmin2[i]=min(rmin2[i+1],r[i]);
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		int L=max(lmax1[i-1],lmax2[i+1]);
		int R=min(rmin1[i-1],rmin2[i+1]);
		if(R>=L)ans=max(ans,R-L);
	}
	printf("%d\n",ans);
	return 0;
}