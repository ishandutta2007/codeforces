#include<bits/stdc++.h>
using namespace std;const int N=1e5+7;
int n,m,l[N],p[N],i,j,L,R,pos,mid,ans,used;long long sum;
int main(){
	for(scanf("%d%d",&n,&m),i=1;i<=m;++i){
		scanf("%d",l+i);
		if(n-l[i]<i-1)return 0*puts("-1");sum+=l[i];
		p[i]=i;
	}
	if(sum<n)return 0*puts("-1");p[m+1]=n+1;
	for(i=m;i>=1;--i)if(p[i]+l[i]<p[i+1])p[i]=p[i+1]-l[i];
	for(i=1;i<=m;++i)printf("%d ",p[i]);puts("");
}