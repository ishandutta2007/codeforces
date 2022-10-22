#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 300001
int N,fa[MAXN][20],a[MAXN],c[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	N=get(),a[0]=get(),c[0]=get();
	For(i,1,N)
	{
		int opt=get();if(opt==1){fa[i][0]=get(),a[i]=get(),c[i]=get();For(j,1,19)fa[i][j]=fa[fa[i][j-1]][j-1];}
		else{int v=get(),cnt=get();int tot=0;ll ans=0;while(cnt&&a[v]){int u=v;FOR(j,19,0)if(a[fa[u][j]])u=fa[u][j];int tmp=min(cnt,a[u]);ans+=1ll*tmp*c[u],tot+=tmp,cnt-=tmp,a[u]-=tmp;}cout<<tot<<' '<<ans<<endl;}
	}
	return 0;
}