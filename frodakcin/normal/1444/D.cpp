#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <functional>

const int MV = 5e5+10;

int dp[MV];
//partition is very sus in terms of time complexity...

bool partition(int *a, int N, int v, std::vector<int> &g1, std::vector<int> &g2)
{
	memset(dp, -1, (v+1)*sizeof*dp);
	dp[0]=0;
	for(int i=0;i<N;++i)
		for(int j=v;j>=a[i];--j)
			if(!~dp[j] && ~dp[j-a[i]])
				dp[j]=i;
	if(!~dp[v])
		return 0;
	for(int i=v,x;i;i-=x)
	{
		x=a[dp[i]];
		a[dp[i]]=-1;
		g1.push_back(x);
	}
	for(int i=0;i<N;++i)
		if(~a[i])
			g2.push_back(a[i]);
	return 1;
}

void solve()
{
	int H, V, toth=0, totv=0;
	scanf("%d", &H);
	int l[H];
	for(int i=0;i<H;++i) scanf("%d", l+i), toth+=l[i];
	scanf("%d", &V);
	int p[V];
	for(int i=0;i<V;++i) scanf("%d", p+i), totv+=p[i];
	if(V!=H || toth&1 || totv&1)
		return (void) printf("No\n");

	std::vector<int> hp, hn, vp, vn;
	if(!partition(l, H, toth/2, hp, hn) || !partition(p, V, totv/2, vp, vn))
		return (void) printf("No\n");
	if(hp.size() < hn.size()) hp.swap(hn);
	if(vp.size() < vn.size()) vp.swap(vn);

	printf("YES\n");
	int x=0, y=0;
	if(hp.size() < vp.size())
	{
		std::sort(hp.begin(), hp.end(), std::greater<int>());
		std::sort(hn.begin(), hn.end(), std::greater<int>());
		std::sort(vp.begin(), vp.end());
		std::sort(vn.begin(), vn.end());
		for(int v:hn)
			hp.push_back(-v);
		for(int v:vn)
			vp.push_back(-v);
		for(int i=0;i<H;++i)
		{
			printf("%d %d\n", x += hp[i], y);
			printf("%d %d\n", x, y += vp[i]);
		}
	}
	else
	{
		std::sort(hp.begin(), hp.end());
		std::sort(hn.begin(), hn.end());
		std::sort(vp.begin(), vp.end(), std::greater<int>());
		std::sort(vn.begin(), vn.end(), std::greater<int>());
		for(int v:hn)
			hp.push_back(-v);
		for(int v:vn)
			vp.push_back(-v);
		for(int i=0;i<H;++i)
		{
			printf("%d %d\n", x, y += vp[i]);
			printf("%d %d\n", x += hp[i], y);
		}
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	for(;t--;)
		solve();
	return 0;
}