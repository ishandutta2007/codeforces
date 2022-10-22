#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 500001
int T,N,M,u[MAXN],v[MAXN],w[MAXN],f[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
void mrg(int x,int y){x=getf(x),y=getf(y);if(x!=y)f[x]=y;}
void mrg(int x,int y,int v){mrg(x,y+v*N);mrg(x+N,y+(v^1)*N);}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get();For(i,1,N-1)u[i]=get(),v[i]=get(),w[i]=get();
		For(i,1,N*2)f[i]=i;For(i,1,N-1)if(w[i]>=0)mrg(u[i],v[i],__builtin_popcount(w[i])&1);
		For(i,1,M){int x=get(),y=get(),v=get();mrg(x,y,v);}
		bool flag=1;For(i,1,N)if(getf(i)==getf(i+N)){flag=0;break;}if(!flag){cout<<"NO\n";continue;}
		cout<<"YES\n";For(i,1,N)if(getf(i)!=getf(1)&&getf(i+N)!=getf(1))mrg(1,i,0);
		For(i,1,N-1)if(w[i]>=0)cout<<u[i]<<' '<<v[i]<<' '<<w[i]<<'\n';else cout<<u[i]<<' '<<v[i]<<' '<<(getf(u[i])==getf(v[i])?0:1)<<'\n';
	}
}