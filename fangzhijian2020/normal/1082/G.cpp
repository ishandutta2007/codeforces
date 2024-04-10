#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long ans1,ans,sum,s,t,n,m,x,y,vis[100005],v,dis[100005],gap[100005],minn,i,j;
struct Edge{long long to,next,v;}a[400005];
long long h[100005]={0},cnt=1;
void add(long long x,long long y,long long v)
{  
    cnt++;a[cnt].to=y;a[cnt].next=h[x];a[cnt].v=v;h[x]=cnt;
    cnt++;a[cnt].to=x;a[cnt].next=h[y];a[cnt].v=0;h[y]=cnt;
}
long long sap(long long x,long long maxf){
	long long i,y,del,ret=0;
	if(x==t){
		return maxf;
	}
	for(i=h[x];i;i=a[i].next){
		y=a[i].to;
		if(dis[x]==dis[y]+1&&a[i].v>0){
			del=sap(y,min(maxf,a[i].v));
			a[i].v-=del;
			a[i^1].v+=del;
			ret+=del;
			maxf-=del;
			if(maxf==0||dis[s]==n+m+1){
				return ret;
			}
		}
	}
	if(!(--gap[dis[x]]))dis[s]=n+m+1;
	gap[++dis[x]]++;
	return ret;
}
void dfs(long long x){
	long long i,y;
	vis[x]=1;
	for(i=h[x];i;i=a[i].next){
		y=a[i].to;
		if(vis[y]==0&&a[i].v>0){
			dfs(y);
		}	
	}
	return;
}
int main(){
	scanf("%lld%lld",&n,&m);s=0;t=n+m+1;
	for(i=1;i<=n;i++){
		scanf("%lld",&v);
		add(i+m,t,v);
	}
	for(i=1;i<=m;i++){
		scanf("%lld%lld%lld",&x,&y,&v);
		add(i,x+m,(1ll<<60));
		add(i,y+m,(1ll<<60));
		add(0,i,v);sum+=v;
	}
	for(i=0;i<=t;i++)dis[i]=0;
	for(i=0;i<=t;i++)gap[i]=0;
	gap[0]=n+m+2;
	for(;dis[s]<n+m+1;)ans+=sap(s,(1ll<<60));
	printf("%lld\n",sum-ans);
	return 0;
}