#include<iostream>
#include<cstring>
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
char st[MN+5];
int f[MN+5][MN+5][2],num[MN+5],n,K; 
inline void R(int&x,int y){x+=y;x>=mod?x-=mod:0;}
int main()
{
	scanf("%s",st+1);n=strlen(st+1);K=read();
	if(!K) return 0*puts("1");
	for(int i=2;i<=1000;++i)
	{
		int s=0;
		for(int j=0;j<10;++j) if(i&(1<<j)) ++s;
		num[i]=num[s]+1;
	}
	f[0][0][1]=1;
	for(int i=1;i<=n;++i) for(int j=0;j<i;++j) for(int k=0;k<2;++k) if(f[i-1][j][k]) for(int l=0;l<2;++l)
	{
		if(l>st[i]-'0'&&k) continue;
		int Nk=k&(l==st[i]-'0');
		R(f[i][j+l][Nk],f[i-1][j][k]);
	}
	int ans=0;
	for(int i=1;i<=n;++i) if(num[i]+1==K) R(ans,f[n][i][0]),R(ans,f[n][i][1]);
	if(K==1) R(ans,mod-1);
	printf("%d\n",ans);
	return 0;
}