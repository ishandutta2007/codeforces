#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>

using ll = long long;
//custom ckmin
bool ckmin(ll *a, ll b) {return !~*a||b<*a?*a=b,1:0;}
const int MN = 1e6 + 10, MM = 1e4 + 10;
const int MG = 1e3 + 10;

int N, M, d[MM], G, R;

struct loc
{
public:
	int n, g;//r if necessary
};
std::deque<loc> q;
int dis[MM][MG];//number of r's
bool vis[MM][MG];

ll ans = -1;
int main(void)
{
	memset(dis, -1, sizeof(dis));
	scanf("%d%d", &N, &M);
	for(int i = 0;i < M;++i)
		scanf("%d", d+i);
	std::sort(d, d+M);
	scanf("%d%d", &G, &R);
	dis[0][0] = 0;
	q.push_back({0, 0});
	while(!q.empty())
	{
		loc n = q.front();
		//printf("%d %d (%dR)\n", n.n, n.g, dis[n.n][n.g]);
		q.pop_front();
		int D = dis[n.n][n.g];
		if(vis[n.n][n.g])
			continue;
		vis[n.n][n.g] = 1;
		if(n.n > 0)
		{
			int ng = n.g + d[n.n] - d[n.n-1];
			if(ng < G)
			{
				if(!~dis[n.n-1][ng] || D < dis[n.n-1][ng])
					dis[n.n-1][ng] = D, q.push_front({n.n-1, ng});
			}
			else if(ng == G)
			{
				if(!~dis[n.n-1][0])
					dis[n.n-1][0] = D+1, q.push_back({n.n-1, 0});
			}
		}
		if(n.n+1 < M)
		{
			int ng = n.g + d[n.n+1] - d[n.n];
			if(ng < G)
			{
				if(!~dis[n.n+1][ng] || D < dis[n.n+1][ng])
					dis[n.n+1][ng] = D, q.push_front({n.n+1, ng});
			}
			else if(ng == G)
			{
				if(!~dis[n.n+1][0])
					dis[n.n+1][0] = D+1, q.push_back({n.n+1, 0});
			}
		}
	}
	if(~dis[M-1][0])
		ans = (ll)dis[M-1][0]*(R+G)-R;
	for(int i = 1;i < G;++i)
		if(~dis[M-1][i])
			ckmin(&ans, (ll)dis[M-1][i]*(R+G) + i);
	printf("%lld\n", ans);
	return 0;
}