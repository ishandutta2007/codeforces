#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,t,L[150002],p1,p2,a[4],b[4];
vector<int>G[150002];
char v[150002],f[150002][2];
long long ans;
int main(){
	t=read();
	while(t--){
		n=read(),m=read(),p2=ans=0;
		for(re int i=0;i<=n+1;++i)v[i]=f[i][0]=f[i][1]=0,G[i].clear();
		for(re int i=1,x,y;i<=m;++i){
			x=read(),y=read();
			if(y==x+1)v[y]=1;
			else G[y].push_back(x);
		}
		for(re int i=1;i<=n;++i)L[i]=v[i]?L[i-1]:i;
		for(re int i=2;i<=n;++i)G[i].push_back(0),G[n+1].push_back(i-1);
		for(re int i=2;i<=n;++i)if(!v[i])p2=i;
		for(re int i=n;i>=2;--i)if(!v[i])p1=i-1;
		if(!p2){
			printf("%lld\n",1ll*n*(n-1)>>1);
			continue;
		}
		f[p1][0]=1,f[p1][1]=2;
		for(re int i=p1+1;i<=n;++i)for(auto z:G[i+1])if(L[i]<=z+1)f[i][0]|=f[z][1],f[i][1]|=f[z][0];
		for(re int i=p1;i;--i)for(auto z:G[i+1])if(L[i]<=z+1)f[z][0]|=f[i][1],f[z][1]|=f[i][0];
		a[0]=a[1]=a[2]=a[3]=b[0]=b[1]=b[2]=b[3]=0;
		for(re int i=0;i<=p1;++i)++a[f[i][0]];
		for(re int i=p2-1;i<=n;++i)++b[f[i][0]];
		for(re int i=0;i<4;++i)for(re int j=0;j<4;++j)if(i&j)ans+=1ll*a[i]*b[j];
		printf("%lld\n",ans-(p2==p1+1));
	}
}