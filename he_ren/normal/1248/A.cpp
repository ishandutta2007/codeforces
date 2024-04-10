#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;

int t[2];

void solve(void)
{
	t[0]=t[1]=0;
	
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		int p;
		scanf("%d",&p);
		++t[p&1];
	}
	
	int m;
	ll ans=0;
	scanf("%d",&m);
	for(int i=1; i<=m; ++i)
	{
		int q;
		scanf("%d",&q);
		ans = ans + t[q&1];
	}
	cout<<ans<<endl;
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}