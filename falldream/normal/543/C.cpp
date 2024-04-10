#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
inline int read()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,m,mx[55][55],tot[55][55],s[55][55],a[25][25],f[1<<20];
char st[25][25];
inline void R(int&x,int y){y<x?x=y:0;}
int main()
{
	n=read();m=read();memset(f,40,sizeof(f));
	for(int i=1;i<=n;++i) scanf("%s",st[i]+1);
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) a[i][j]=read();
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j) 
			s[i][st[j][i]-'a']|=1<<j-1,
			mx[i][st[j][i]-'a']=max(mx[i][st[j][i]-'a'],a[j][i]),
			tot[i][st[j][i]-'a']+=a[j][i];
	}
	f[0]=0;
	for(int i=0;i<(1<<n)-1;++i)
	{
		int j=1;
		for(;i&(1<<j-1);++j);
		for(int k=1;k<=m;++k) 
			R(f[i|s[k][st[j][k]-'a']],f[i]+tot[k][st[j][k]-'a']-mx[k][st[j][k]-'a']),
			R(f[i|(1<<j-1)],f[i]+a[j][k]);
	}
	printf("%d\n",f[(1<<n)-1]);
	return 0;
}