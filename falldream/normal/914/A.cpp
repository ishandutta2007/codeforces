#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
bool Check(int x)
{
	if(x<0) return false;
	int t=int(sqrt(x));
	for(int k=-3;k<=3;++k) if((t+k)*(t+k)==x) return true;
	return false;	
}
int main()
{
	int n=read(),ans=-1e9,x;
	for(int i=1;i<=n;++i) if(x=read(),!Check(x)) ans=max(ans,x);
	cout<<ans;
	return 0;
}