#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e2 + 5;
const int MAXM = 1e5 + 5;
const int inf = 0x3f3f3f3f;

const int C = 1e5;
inline ll calc(ll x){ return (x + C - 1) / C;}

int t[MAXN], b[MAXN];
ll a[MAXN];

pii f[MAXM];

inline int to(int x,int k){ return t[k] == 1? x + a[k]: (int)min(calc(x * a[k]), (ll)inf);}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d%lld%d",&t[i],&a[i],&b[i]);
		if(t[i] == 1) a[i] = calc(a[i]);
	}
	
	for(int i=1; i<=m; ++i) f[i] = make_pair(inf, 0);
	for(int i=0; i<m; ++i) if(f[i].first < inf)
	{
		int cur = f[i].first;
		if(i && f[i].second < b[cur])
		{
			int j = to(i, cur);
			if(j <= m) f[j] = min(f[j], make_pair(cur, f[i].second + 1));
		}
		for(int k=cur+1; k<=n; ++k)
		{
			int j = to(i, k);
			if(j <= m) f[j] = min(f[j], make_pair(k, 1));
		}
	}
	
	for(int i=1; i<=m; ++i)
		printf("%d ",f[i].first < inf? f[i].first: -1);
	return 0;
}