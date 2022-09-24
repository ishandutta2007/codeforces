#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
int n,m,S,T,N,gap[1005],dis[1005],h[1005],cnt=1,cur[1005];
int u[100005],v[100005],fin[100005],k,t,d[1005],dn[1005];
struct Edge{
	int to,next,flow,id;
}e[300005];
void Add(int x,int y,int z,int id) {
	e[++cnt]={y,h[x],z,id},h[x]=cnt;
	e[++cnt]={x,h[y],0,0},h[y]=cnt;
}
void A(int x,int y,int down,int z) {
	e[++cnt]={y,h[x],z-down,0},h[x]=cnt,dn[x]-=down,dn[y]+=down;
	e[++cnt]={x,h[y],0,0},h[y]=cnt;
}
int DFS(int x,int f,int s,int t){
	if(!f)return 0;
	if(x==t)return f;
	int ret=0;
	for(int &i=cur[x];i;i=e[i].next){
		int y=e[i].to;
		if(!e[i].flow||dis[y]+1!=dis[x])continue;
		int dlt=DFS(y,min(f,e[i].flow),s,t);
		e[i].flow-=dlt,e[i^1].flow+=dlt;
		ret+=dlt,f-=dlt;
		if(dis[s]==N||!f)return ret;
	}
	if(!--gap[dis[x]])dis[s]=N;
	else gap[++dis[x]]++;
	return ret;
}
ll SAP(int s,int t) {
	ll ret=0;
	memset(gap,0,sizeof(gap));
	memset(dis,0,sizeof(dis));
	gap[0]=N;
	while(dis[s]<N)memcpy(cur,h,sizeof(h)),ret+=DFS(s,inf,s,t);
	return ret;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&t);
	for(int i=1;i<=k;i++)scanf("%d%d",&u[i],&v[i]),v[i]+=n,d[u[i]]++,d[v[i]]++;
	int ans=0;
	for(int i=1;i<=n+m;i++)if(d[i]%t)ans++;
	printf("%d\n",ans);
	while(t){
		cnt=1,S=n+m+1,T=n+m+2,memset(d,0,sizeof(d)),memset(h,0,sizeof(h)),memset(dn,0,sizeof(dn));
		for(int j=1;j<=k;j++)if(!fin[j])Add(u[j],v[j],1,j),d[u[j]]++,d[v[j]]++;
		for(int j=1;j<=n;j++)A(S,j,d[j]/t,(d[j]+t-1)/t);
		for(int j=n+1;j<=n+m;j++)A(j,T,d[j]/t,(d[j]+t-1)/t);
		int ss=n+m+3,tt=n+m+4;
		N=tt,Add(T,S,inf,0);
		for(int j=1;j<=T;j++)if(dn[j]>0)Add(ss,j,dn[j],0);else Add(j,tt,-dn[j],0);
		SAP(ss,tt);
		for(int j=1;j<=n;j++){
			for(int o=h[j];o;o=e[o].next)if(!e[o].flow&&e[o].to>n&&e[o].to<=n+m)fin[e[o].id]=t;
		}
		t--;
	}
	for(int i=1;i<=k;i++)printf("%d ",fin[i]);
    return 0;
}