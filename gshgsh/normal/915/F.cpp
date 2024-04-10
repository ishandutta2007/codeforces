#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1000001
int N,a[MAXN],K,b[MAXN],f[MAXN],siz[MAXN];ll ans;vector<int>pos[MAXN],E[MAXN];bool vis[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
void mrg(int x,int y,int v){x=getf(x),y=getf(y);if(x==y)return;if(siz[x]>siz[y])swap(x,y);ans+=1ll*siz[x]*siz[y]*v;f[x]=y;siz[y]+=siz[x];}
int main()
{
	N=get();For(i,1,N)a[i]=b[i]=get();For(i,1,N-1){int u=get(),v=get();E[u].push_back(v),E[v].push_back(u);}
	sort(b+1,b+N+1);K=unique(b+1,b+N+1)-b-1;For(i,1,N)a[i]=lower_bound(b+1,b+K+1,a[i])-b,pos[a[i]].push_back(i);
	For(i,1,N)f[i]=i,siz[i]=1,vis[i]=0;For(i,1,K)for(auto j:pos[i]){ans+=b[a[j]];for(auto k:E[j])if(vis[k])mrg(j,k,b[a[j]]);vis[j]=1;}
	For(i,1,N)f[i]=i,siz[i]=1,vis[i]=0;FOR(i,K,1)for(auto j:pos[i]){ans-=b[a[j]];for(auto k:E[j])if(vis[k])mrg(j,k,-b[a[j]]);vis[j]=1;}cout<<ans<<'\n';
}