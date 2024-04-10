#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<map>
#include<cstring>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}

int n,cnt=0;
int f[100005];
int b[100005];
int s[100005];
int num[100005];

int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	  f[i]=read();
	for(int i=1;i<=n;i++)
	   if(f[i]!=f[f[i]]) return 0*puts("-1");
	for(int i=1;i<=n;i++)
	{
	   if(!b[f[i]]) b[f[i]]=++cnt,num[cnt]=f[i];	
	    s[i]=b[f[i]];
	}
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)
	   printf("%d ",s[i]);
	cout<<endl;
	for(int i=1;i<=cnt;i++)	
	{
		printf("%d ",num[i]);
	}
	
	return 0;
}