#include<iostream>
#include<cstdio>
#include<map> 
#define MN 200000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int flag1=0,flag2=0,flag3=0,ff3,flag4=0;
int n,a[MN+5],x,y;
map<int,bool> mp;
int main()
{
	n=read();read();x=read();y=read();
	for(int i=1;i<=n;++i) mp[a[i]=read()]=1;
	for(int i=1;i<=n;++i) 
	{
		if(mp[a[i]-x]) flag1=i;
		if(mp[a[i]-y]) flag2=i;
		if(mp[a[i]-y+x]&&(a[i]-y>=0||a[i]+x<=a[n])) flag3=i,ff3=(a[i]-y>=0)?a[i]-y:a[i]+x;;	
		if(mp[a[i]-y-x]) flag4=i;
	}
	if(flag1&&flag2) puts("0");
	else if(flag1|flag2) printf("1\n%d",flag1?y:x);
	else if(flag3) printf("1\n%d",ff3);
	else if(flag4) printf("1\n%d",a[flag4]-x);
	else printf("2\n%d %d",x,y);
	return 0;
}