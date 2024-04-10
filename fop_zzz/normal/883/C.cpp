#include<bits/stdc++.h>
using namespace std;
#define int long long
inline void read(int &x)
{
	char c=getchar();
	x=0;
	while (c>'9'||c<'0')
		c=getchar();
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}
const int inf=1e18;
int a,t,t0,t1,t2,p1,p2,a1,a2,ans;
signed main()
{
	//freopen("c.in","r",stdin);
	//freopen("c.out","w",stdout);
	read(a);
	read(t);
	read(t0);
	read(a1);
	read(t1);
	read(p1);
	read(a2);
	read(t2);
	read(p2);
	ans=inf;
	if (min(t0,min(t1,t2))*a>t)
	{
		printf("-1");
		return 0;
	}
	if (t0<=t1&&t0<=t2)
	{
		if (a*t0<=t)
			putchar('0');
		else
			printf("-1");
		return 0;
	}
	for (int i=0;i<=(a-1)/a1+1;++i)
	{
		int dt=t-t1*min(i*a1,a),sum=i*p1,da=max(0LL,a-a1*i),x;
		if (dt<0)
			break;
		if (da*t0<=dt)
		{
			ans=min(ans,sum);
			break;
		}
		if (da*t2>dt)
			continue;
		if (t0>t2)
		{
			x=(da*t0-dt+t0-t2-1)/(t0-t2);
			ans=min(ans,sum+((x-1)/a2+1)*p2);
		}
	}
	swap(a1,a2);
	swap(t1,t2);
	swap(p1,p2);
	for (int i=0;i<=(a-1)/a1+1;++i)
	{
		int dt=t-t1*min(i*a1,a),sum=i*p1,da=max(0LL,a-a1*i),x;
		if (dt<0)
			break;
		if (da*t0<=dt)
		{
			ans=min(ans,sum);
			break;
		}
		if (da*t2>dt)
			continue;
		if (t0>t2)
		{
			x=(da*t0-dt+t0-t2-1)/(t0-t2);
			ans=min(ans,sum+((x-1)/a2+1)*p2);
		}
	}
	if (ans>=(int)1e15)
		ans=-1;
	cout<<ans;
}