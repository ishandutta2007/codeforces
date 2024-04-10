#include<iostream>
#include<cstdio>
#define MN 1000
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,C[MN*2+5][MN*2+5],ans=1;
int main()
{
	n=read();
	for(int i=0;i<=MN<<1;++i) C[i][0]=1;
	for(int i=1;i<=MN<<1;++i) for(int j=1;j<=i;++j) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	for(int i=1,t=0;i<=n;++i)
	{
		int x=read();
		ans=1LL*ans*C[x+t-1][t]%mod;
		t+=x;
	}	
	printf("%d\n",ans);
	return 0;
}