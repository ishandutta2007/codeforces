#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll unsigned long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{c=getchar();}
	while(c>='0'&&c<='9')	t=t*10+c-48,c=getchar();
	return t*f;
}
int h1,a1,c1,h2,a2,ans;
inline bool check(int x)
{
	For(i,0,x)
	{
		if(i*c1+h1>a2*(x-1))
			if((x-i)*a1>=h2)	return 1;	
	}
	return 0;
}
int main()
{
	h1=read();a1=read();c1=read();
	h2=read();a2=read();
	int l=1,r=10000;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))	ans=mid,r=mid-1;else l=mid+1;
	}
	cout<<ans<<endl;
	For(i,0,ans)
	{
		if(i*c1+h1>a2*(ans-1))
			if((ans-i)*a1>=h2)	
			{
				For(j,1,i)	puts("HEAL");
				For(j,1,ans-i)	puts("STRIKE");
			}
	}
}