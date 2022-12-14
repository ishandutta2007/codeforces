#include<iostream>
#include<vector>
#include<cstdio>
#define MN 100000
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,f[MN+5][2],g[MN+5][2],h[MN+5];
vector<int> v[MN+5];

void Solve(int x)
{
	f[x][1]=g[x][0]=h[x]=1;
	for(int i=0;i<v[x].size();++i)	
	{
		int y=v[x][i];Solve(y);
		int t1=f[x][0],t2=g[x][0];
		f[x][0]=(f[x][0]+1LL*f[x][0]*f[y][0]+1LL*f[x][1]*f[y][1])%mod;
		f[x][1]=(f[x][1]+1LL*t1*f[y][1]+1LL*f[x][1]*f[y][0])%mod;
		g[x][0]=(g[x][0]+1LL*g[x][1]*f[y][1])%mod;
		g[x][1]=(g[x][1]+1LL*t2*f[y][1])%mod;
		h[x]=(h[x]+1LL*h[x]*f[y][0])%mod;      
	}
	f[x][0]=(2LL*f[x][0]+mod-g[x][1])%mod;
	f[x][1]=(2LL*f[x][1]+mod-h[x])%mod;
}

int main()
{
	n=read();
	for(int i=2;i<=n;++i) v[read()].push_back(i);
	Solve(1);printf("%d\n",(f[1][0]+f[1][1])%mod);
	return 0;
}