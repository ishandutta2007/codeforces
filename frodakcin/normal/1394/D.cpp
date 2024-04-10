#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

template<typename T> bool ckmax(T& a, const T& b) {return a<b?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

using ll = long long;

const int MN = 2e5+10;

int N, t[MN], h[MN];
ll dp[MN][2];
//0=down, 1=up
std::vector<int> a[MN];

void dfs(int n=1, int p=0)
{
	int deg[2]={0,0};//0=down, 1=up, equ=down->up
	ll f=0;
	std::vector<ll> v;
	for(int x:a[n])
		if(x!=p)
		{
			dfs(x, n);
			if(h[x]==h[n])
				v.push_back(dp[x][1]-dp[x][0]);
			++deg[h[x]<h[n]];
			f+=dp[x][h[x]<h[n]];
		}
	std::sort(v.begin(), v.end());
	if(p)
		for(int i=0;;++i)
		{
			ckmin(dp[n][0], f+(ll)t[n]*std::max(deg[0], deg[1]+1));
			ckmin(dp[n][1], f+(ll)t[n]*std::max(deg[0]+1, deg[1]));
			if(i==v.size()) break;
			++deg[1], --deg[0], f+=v[i];
		}
	else
	{
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0;;++i)
		{
			ckmin(ans, f+(ll)t[n]*std::max(deg[0], deg[1]));
			if(i==v.size()) break;
			++deg[1], --deg[0], f+=v[i];
		}
		printf("%lld\n", ans);
	}
}

int main()
{
	memset(dp, 0x3f, sizeof dp);
	scanf("%d", &N);
	for(int i=1;i<=N;++i) scanf("%d", t+i);
	for(int i=1;i<=N;++i) scanf("%d", h+i);
	for(int i=1,u,v;i<N;++i)
		scanf("%d%d", &u, &v), a[u].push_back(v), a[v].push_back(u);
	dfs();
	return 0;
}