#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 10000001
int T,l,r,a[MAXN],tot,siz[MAXN],s[MAXN][2];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void ins(int x){int u=1;FOR(i,17,0){int c=x>>i&1;siz[u]++;if(!s[u][c])s[u][c]=++tot;u=s[u][c];}siz[u]++;}
int ask(int x,int y){int u=1,ans=0;FOR(i,17,0){int c=x>>i&1;if(y>=1<<i)ans+=siz[s[u][c]],u=s[u][c^1],y-=1<<i;else u=s[u][c];}return ans;}
int main()
{
	T=get();
	while(T--)
	{
		For(i,1,tot)siz[i]=s[i][0]=s[i][1]=0;tot=1;l=get(),r=get();For(i,0,r-l)a[i]=get(),ins(a[i]);
		For(i,0,r-l)if(ask(a[i]^l,r+1)-ask(a[i]^l,l)==r-l+1){cout<<(a[i]^l)<<'\n';break;}
	}
}