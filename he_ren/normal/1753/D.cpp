#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

string s[MAXN];

int main(void)
{
	int n,m,A,B;
	scanf("%d%d%d%d",&n,&m,&A,&B);
	for(int i=0; i<=n+1; ++i)
		s[i].resize(m+2, 0);
	for(int i=1; i<=n; ++i)
	{
		static char tmp[MAXN];
		scanf("%s",tmp+1);
		for(int j=1; j<=m; ++j)
			s[i][j] = tmp[j];
	}
	
	static vector<ll> dis[MAXN];
	static vector<int> vis[MAXN];
	for(int i=0; i<=n+1; ++i)
	{
		dis[i].resize(m+2, linf);
		vis[i].resize(m+2, 0);
	}
	
	priority_queue< pair<ll,pii> > q;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			if(s[i][j] == '.')
			{
				dis[i][j] = 0;
				q.emplace(make_pair(0ll, make_pair(i, j)));
			}
	
	auto chk = [&] (int x,int y,ll k)
	{
		if(dis[x][y] > k)
		{
			dis[x][y] = k;
			q.emplace(make_pair(-dis[x][y], make_pair(x, y)));
		}
	};
	
	ll ans = linf;
	while(q.size())
	{
		int x,y; tie(x,y) = q.top().second; q.pop();
		if(vis[x][y]) continue;
		vis[x][y] = 1;
		
//		printf("x = %d, y = %d, dis = %lld\n",x,y,dis[x][y]);
		
		if(s[x][y-1] == 'R')
			chk(x, y-2, dis[x][y] + B);
		if(s[x][y+1] == 'L')
			chk(x, y+2, dis[x][y] + B);
		if(s[x-1][y] == 'D')
			chk(x-2, y, dis[x][y] + B);
		if(s[x+1][y] == 'U')
			chk(x+2, y, dis[x][y] + B);
		
		if(s[x][y-1] == 'D' || s[x-1][y] == 'R')
			chk(x-1, y-1, dis[x][y] + A);
		
		if(s[x][y-1] == 'U' || s[x+1][y] == 'R')
			chk(x+1, y-1, dis[x][y] + A);
		
		if(s[x][y+1] == 'D' || s[x-1][y] == 'L')
			chk(x-1, y+1, dis[x][y] + A);
		
		if(s[x][y+1] == 'U' || s[x+1][y] == 'L')
			chk(x+1, y+1, dis[x][y] + A);
		
		if(s[x][y-1] == '.' || s[x][y+1] == '.' || s[x+1][y] == '.' || s[x-1][y] == '.')
			ans = min(ans, dis[x][y]);
	}
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
		{
			ans = min(ans, dis[i][j] + dis[i][j+1]);
			ans = min(ans, dis[i][j] + dis[i+1][j]);
		}
	
	if(ans == linf)
		printf("-1\n");
	else
		printf("%lld\n",ans);
	return 0;
}