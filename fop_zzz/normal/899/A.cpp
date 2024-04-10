#include<iostream>
#include<cstdio>
#define ll  long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{c=getchar();}
	while(c>='0'&&c<='9')	t=t*10+c-48,c=getchar();
	return t*f;
}
int n,cnt1,cnt2,ans;
int main()
{
	n=read();
	for(int i=1;i<=n;++i)	if(read()==1)	cnt1++;else cnt2++;
	ans=min(cnt1,cnt2);
	cnt1-=ans;
	cnt2-=ans;
	ans+=cnt1/3;
	cout<<ans<<endl;
}