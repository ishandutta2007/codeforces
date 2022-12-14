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
long long ans=0;
int a,b,c,l;
long long Solve()
{
	long long res=0;
	for(int i=0;i<=l;++i)	
	{
		if(b+c>a+i) continue;
		int mx=min(a+i-(b+c),l-i)+1;
		res+=1LL*mx*(mx+1)/2;	
	}
	return res;
}
int main()
{
	a=read();b=read();c=read();l=read();
	for(int i=0;i<=l;++i) ans+=1LL*(i+2)*(i+1)/2;
	ans-=Solve();
	swap(b,a);ans-=Solve();
	swap(c,a);ans-=Solve();
	cout<<ans;
	return 0;
}