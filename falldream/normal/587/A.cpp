#include<iostream>
#include<cstdio>
#define MN 1000500
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,num[MN+5],ans=0;
int main()
{
	n=read();
	for(int i=1;i<=n;++i) ++num[read()];
	for(int i=0;i<=MN;++i) num[i+1]+=num[i]/2,ans+=(num[i]&1);
	cout<<ans;
	return 0;
}