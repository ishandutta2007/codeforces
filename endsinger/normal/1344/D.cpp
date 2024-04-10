#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int n,k,a[N],ans[N],g;
int dt(int a,int b)
{
	int k1=b*(a-b*b);
	b++;
	int k2=b*(a-b*b);
	return k2-k1;
}
int solve(int x)
{
	int t=0;
	for(int i=1;i<=n;i++)
	{
		int l=0,r=a[i]+1;
		while(r-l>1)
		{
			int m=l+r>>1;
			if(dt(a[i],m)>x)
				l=m;
			else
				r=m;
		}
		ans[i]=l;
		t+=l;
	}
	g=t-k;
	return g>=0;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int l=-8e18,r=1e18;
	while(r-l>1)
	{
		int m=l+r>>1;
		if(solve(m))
			l=m;
		else
			r=m;
	}
	solve(l);
	for(int i=1;i<=n;i++)
	{
		if(g&&dt(a[i],ans[i])==l+1)
			g--,ans[i]--;
		cout<<ans[i]<<' ';
	}
	return 0;
}