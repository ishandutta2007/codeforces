#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
long long x,ans=0;
int main()
{
	scanf("%lld",&x);
	for(long long i=3;i<=3*x;i*=3)
		if(x%i) ans=max(ans,x/i+1);
	cout<<ans;
	return 0;
}