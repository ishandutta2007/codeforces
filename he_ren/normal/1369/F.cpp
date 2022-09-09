#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,pii> piiii;
const int MAXN = 1e5 + 5;
const int LB = 64 + 5;

namespace Solver
{
	vector<ll> pos;
	int f[LB], g[LB];
	
	ll s,e;
	
	int query(ll x, int p)
	{
		if(g[p]) return f[p];
		else return f[p] ^ ((pos[p] - x) & 1);
	}
	
	int solve(ll s,ll e, bool win)
	{
		pos.clear();
		
		for(int i=0; i<=63 && (e>>i)>=s; ++i)
			pos.push_back(e>>i);
		
		if(win) f[0] = 1, g[0] = 0;
		else f[0] = 0, g[0] = 1;
		for(int i=1; i<(int)pos.size(); ++i)
		{
			if(query(pos[i]*2, i-1)) f[i] = 0, g[i] = 1;
			else
			{
				g[i] = 0;
				if(query(pos[i]+1, i-1)) f[i] = 0;
				else f[i] = 1;
			}
		}
		
		return query(s, (int)pos.size()-1);
	}
}

ll s[MAXN], e[MAXN];

bool f[MAXN][2];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%lld%lld",&s[i],&e[i]);
	
	f[1][0] = Solver::solve(s[1], e[1], 0);
	f[1][1] = Solver::solve(s[1], e[1], 1);
	
	for(int i=2; i<=n; ++i)
		for(int j=0; j<=1; ++j)
		{
			bool res = Solver::solve(s[i], e[i], j);
			if(res) f[i][j] = f[i-1][1];
			else f[i][j] = f[i-1][0];
		}
	printf("%d %d",!f[n][1],!f[n][0]);
	return 0;
}