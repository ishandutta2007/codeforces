#include<iostream>
#include<cstring>
#include<cstdio>
#define mod 1000000007
#define MN 1000000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,l,ans=1;
char st[MN+5];
int Ha[MN+5],pw[MN+5];
int main()
{
	n=read();m=read();pw[0]=1;
	scanf("%s",st+1);l=strlen(st+1);
	for(int i=1;i<=l;++i) pw[i]=103LL*pw[i-1]%mod,Ha[i]=(Ha[i-1]*103LL+st[i])%mod;
	int pre=1-l;
	for(int i=1;i<=m;++i) 
	{
		int x=read();
		if(x>pre+l-1) for(int j=x-pre-l;j;--j) ans=26LL*ans%mod;
		else
		{
			int slen=pre+l-x;
			if((Ha[l]-1LL*Ha[l-slen]*pw[slen]%mod+mod)%mod!=Ha[slen]) return 0*puts("0");	
		}
		pre=x;
	}
	for(int j=pre+l;j<=n;++j) ans=26LL*ans%mod;
	printf("%d\n",ans);
	return 0;
}