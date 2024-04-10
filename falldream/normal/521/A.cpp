#include<iostream>
#include<cstdio>
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,num[4],mx=0,mxnum=0;
char st[100005];
int main()
{
	n=read();scanf("%s",st+1);
	for(int i=1;i<=n;++i)
	{
		if(st[i]=='A') ++num[0];
		if(st[i]=='C') ++num[1];
		if(st[i]=='G') ++num[2];
		if(st[i]=='T') ++num[3];
	}
	for(int i=0;i<4;++i) if(num[i]>mx) mx=num[i],mxnum=1; else if(num[i]==mx) ++mxnum;
	int ans=1;
	for(int i=1;i<=n;++i) ans=1LL*ans*mxnum%mod;
	printf("%d\n",ans);
	return 0;
}