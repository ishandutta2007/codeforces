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
const int N=100005;
int n,m,x,y,p,j,d[N],ans;
signed main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	read(m);
	read(n);
	read(x);
	read(y);
	p=y/x+1;
	j=1;
	for (int i=1;i<=n;++i)
		read(d[i]);
	for (int i=1;i<=n;++i)
	{
		bool b=1;
		while (d[i]>j*x&&j<=m&&i<=n&&b)
		{
			b=0;
			int s=d[i]/x-j+1,s1;
			if (s%p==0)
				s1=s/p;
			else
				s1=s/p+1;			
			if (j+s1*p<=m)
			{
				ans+=s1;
				j=j+s1*p;
			}
			else
			{
				s=m-j+1;
				if (s%p==0)
					s1=s/p;
				else
					s1=s/p+1;
				ans+=s1;
				j=j+s1*p;
			}
			while (d[i]<=(j-p)*x+y&&i<=n)
				++i,b=1;
		}
		if (i>n)
			break;
		++ans;
		j=(d[i]+y)/x+1;
		int k=d[i]+y;
		while (k>=d[i+1]&&i<n)
			++i;
	}
	if (j<=m)
	{
		int s=m-j+1,s1;
		if (s%p==0)
			s1=s/p;
		else
			s1=s/p+1;
		ans+=s1;
		j=j+s1*p;
	}
	cout<<ans;
	return 0;
}