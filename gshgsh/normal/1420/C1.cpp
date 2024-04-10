#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define INF 0x3fffffffffffffff
#define MAXN 300001
int T,N,a[MAXN];ll f[MAXN][2];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),get();For(i,1,N)a[i]=get();f[0][0]=-INF;f[0][1]=0;
		For(i,1,N)f[i][0]=max(f[i-1][0],f[i-1][1]+a[i]),f[i][1]=max(f[i-1][1],f[i-1][0]-a[i]);cout<<max(f[N][0],f[N][1])<<endl;
	}
	return 0;
}