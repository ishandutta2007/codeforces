#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;
const int inf = 0x3f3f3f3f;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

pii p[MAXN];
int lef[MAXN], rig[MAXN], f[MAXN][MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d%d",&p[i].first,&p[i].second);
	
	sort(p+1,p+n+1);
	p[0].first = -inf;
	for(int i=0; i<=n; ++i)
		lef[i] = p[i].first - p[i].second, rig[i] = p[i].first + p[i].second;
	
	for(int i=0; i<n; ++i)
		for(int j=0; j<=i; ++j)
		{
			int r = max(p[i].first, rig[j]), nj = j, cur = f[i][j];
			int fr = r, pre = -1, from = -inf, to = inf;
			for(int k=i+1; k<=n; ++k)
			{
				if(from == -inf)
					chk_max(f[k][nj], cur + min(p[k].second, max(p[k].first - r, 0)));
				else if(lef[k] <= to && lef[k] <= r)
					chk_max(f[k][nj], f[i][j] + (pre - fr) + (max(p[k].first, r) - max(min(from, lef[k]), pre)));
				
				if(lef[k] >= r)
					chk_max(f[k][nj], cur + p[k].second);
				
				if(p[k].first > r)
				{
					if(from == -inf) pre = r, from = p[k].first;
					else if(to == inf) to = r;
				}
				if(rig[k] > r)
				{
					cur += min(p[k].second, rig[k] - r);
					nj = k; r = rig[k];
				}
				chk_max(f[k][nj], cur);
			}
		}
	
	int ans = 0;
	for(int i=1; i<=n; ++i)
		for(int j=0; j<=i; ++j)
			chk_max(ans, f[i][j]);
	printf("%d",ans);
	return 0;
}