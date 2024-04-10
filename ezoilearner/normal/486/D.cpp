#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int Mod=1000000007;
int d,n;
int zjr=0;
#define maxn 2010
int a[maxn];
int head[maxn],v[maxn*2],nxt[maxn*2],tot=0;
int f[maxn][4];
int bel[maxn];
void add_edge(int s,int e){
	tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
	tot++;v[tot]=s;nxt[tot]=head[e];head[e]=tot;
}
void divide(int u,int minv,int f){
	if(a[u]<minv)bel[u]=1;
	else if(a[u]==minv)bel[u]=2;
    else if(minv<a[u]&&a[u]<=minv+d)bel[u]=3;
    else bel[u]=1;
    for(int i=head[u];i;i=nxt[i])
    if(v[i]!=f)divide(v[i],minv,u);
}
void solve(int u,int ff){
	for(int i=head[u];i;i=nxt[i])
	if(v[i]!=ff)solve(v[i],u);
	int ans;	
	if(bel[u]==1)f[u][1]=1;
	else{
		ans=1;
		for(int i=head[u];i;i=nxt[i])
		if(v[i]!=ff)ans=1ll*ans*f[v[i]][1]%Mod;
		ans=(ans+1)%Mod;
		f[u][1]=ans;
	}
	if(bel[u]!=3)f[u][2]=1;
	else{
		ans=1;
		for(int i=head[u];i;i=nxt[i])
		if(v[i]!=ff)ans=1ll*ans*f[v[i]][2]%Mod;
		ans=(ans+1)%Mod;
		f[u][2]=ans;
	}
	if(bel[u]==2){
	    ans=1;
	    for(int i=head[u];i;i=nxt[i])
		if(v[i]!=ff)ans=1ll*ans*f[v[i]][1]%Mod;
	    zjr=(zjr+ans)%Mod;
	}
	if(bel[u]==3){
		int ans1=1,ans2=1;
		for(int i=head[u];i;i=nxt[i])
		if(v[i]!=ff){
			ans1=1ll*ans1*f[v[i]][1]%Mod;
			ans2=1ll*ans2*f[v[i]][2]%Mod;
		}
		zjr=(zjr+(ans1-ans2+Mod)%Mod)%Mod;
	}
}
int main(){
	scanf("%d%d",&d,&n);
	int minv=2147483647,maxv=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		minv=min(a[i],minv);
		maxv=max(a[i],maxv);
	}
	int s,e;
	for(int i=1;i<n;++i){
		scanf("%d%d",&s,&e);
		add_edge(s,e);
	}
	for(int i=minv;i<=maxv;++i){
		divide(1,i,0);
		solve(1,0);
	}
	printf("%d\n",zjr);
	return 0;
}