#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 400001
int T,N,M,f[MAXN],siz[MAXN];bool vis[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
void mrg(int x,int y){x=getf(x),y=getf(y);if(x!=y)f[x]=y,siz[y]+=siz[x];}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get();For(i,1,N*2)f[i]=i,siz[i]=i<=N,vis[i]=0;
		For(i,1,M)
		{
			int u=get(),v=get();string s;cin>>s;
			if(s[0]=='i')mrg(u,v+N),mrg(u+N,v);else mrg(u,v),mrg(u+N,v+N);
		}
		bool flag=1;For(i,1,N)if(getf(i)==getf(i+N)){cout<<"-1\n";flag=0;break;}if(!flag)continue;
		int ans=0;For(i,1,N){int x=getf(i),y=getf(i+N);if(!vis[x]&&!vis[y])ans+=max(siz[x],siz[y]),vis[x]=vis[y]=1;}cout<<ans<<'\n';
	}
	return 0;
}