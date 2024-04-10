#include<cstdio>
#define re register
#define ll long long
#define int unsigned int
using namespace std;
int n,a[5002],b[5002],c[5002],d[5002],X[5002],nxt[5002],S,E;
ll ans;
inline ll calc(re int x,re int y){return x>y?X[x]-X[y]+c[x]+b[y]:X[y]-X[x]+d[x]+a[y];}
signed main(){
	scanf("%u%u%u",&n,&S,&E);
	for(re int i=1;i<=n;++i)scanf("%u",&X[i]);
	for(re int i=1;i<=n;++i)scanf("%u",&a[i]);
	for(re int i=1;i<=n;++i)scanf("%u",&b[i]);
	for(re int i=1;i<=n;++i)scanf("%u",&c[i]);
	for(re int i=1;i<=n;++i)scanf("%u",&d[i]);
	nxt[S]=E,ans=calc(S,E);
	for(re int i=1;i<=n;++i)
		if(i^S&&i^E){
			re ll mn=1e18;
			re int pos=0;
			for(re int j=S;j^E;j=nxt[j]){
				re ll s=calc(j,i)+calc(i,nxt[j])-calc(j,nxt[j]);
				if(s<mn)mn=s,pos=j;
			}
			nxt[i]=nxt[pos],nxt[pos]=i,ans+=mn;
		}
	printf("%lld",ans);
}