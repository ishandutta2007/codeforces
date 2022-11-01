#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<cmath>
#define For(i,j,k)	for(ll i=j;i<=k;++i)
#define Dow(i,j,k)	for(ll i=k;i>=j;--i)
#define ll  long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{c=getchar();}
	while(c>='0'&&c<='9')	t=t*10+c-48,c=getchar();
	return t*f;
}
ll n,a[400001],cnt1,cnt2,q[400001],top,ans;
int main()
{
	n=read();
	For(i,1,n)	a[i]=read();
	For(i,1,n)
	{
		ll tmp=sqrt((int)a[i]);
		if(tmp*tmp==a[i])	cnt1++;
		else	cnt2++;
	}
	if(cnt1>cnt2)
	{
		For(i,1,n)
		{
			int tmp=sqrt(a[i]);
			if(tmp*tmp==a[i])	
			if(a[i]!=0)	q[++top]=1;
				else 	q[++top]=2;
		}
		sort(q+1,q+top+1);
		For(i,1,cnt1-n/2)	ans+=q[i];
		cout<<ans<<endl;
	}
	else
	{
		For(i,1,n)
		{
			int tmp=sqrt(a[i]);
			if(tmp*tmp!=a[i])	
				q[++top]=min(a[i]-tmp*tmp,(tmp+1)*(tmp+1)-a[i]);
		}
		sort(q+1,q+top+1);
		For(i,1,cnt2-n/2)	ans+=q[i];
		cout<<ans<<endl;
	}
}