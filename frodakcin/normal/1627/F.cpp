#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}
template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}

const int INF = 0x3f3f3f3f;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

struct state
{
	public:
		int n, d;
		bool operator > (const state& o) const {return d > o.d || !(o.d > d) && n > o.n;}
};

void solve()
{
	int N, K;
	scanf("%d%d", &N, &K);
	std::vector<int> wx((K+1)*(K+1)), wy((K+1)*(K+1));
	for(int i=0;i<N;++i)
	{
		int r1, c1, r2, c2;
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		if(r1 == r2)
			++wx[(r1-1) + std::min(c1, c2) * (K+1)];
		else
			++wy[std::min(r1, r2) + (c1-1) * (K+1)];
	}
	auto fix=[](int& a, int& b){a=b=a+b;};
	//handle change in x
	for(int r=0;r<K/2;++r)
		for(int c=0;c<=K;++c)
			fix(wx[r+c*(K+1)], wx[K-r-1+(K-c)*(K+1)]);
	//handle change in y
	for(int r=0;r<=K;++r)
		for(int c=0;c<K/2;++c)
			fix(wy[r+c*(K+1)], wy[K-r+(K-c-1)*(K+1)]);

	std::vector<int> dis((K+1)*(K+1), INF);
	std::vector<char> vis((K+1)*(K+1), 0);
	std::priority_queue<state, std::vector<state>, std::greater<state> > pq;
	pq.push({K/2*(K+2), dis[K/2*(K+2)] = 0});
	for(;!pq.empty();)
	{
		auto n = pq.top(); pq.pop();
		if(vis[n.n]) continue;
		vis[n.n]=1;

		int y=n.n/(K+1);
		int x=n.n-y*(K+1);

		for(int i=0;i<4;++i)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx < 0 || K < nx || ny < 0 || K < ny) continue;
			int nid = nx + ny * (K+1);
			int nd = n.d + (i&1 ? wy[std::min(n.n, nid)] : wx[std::min(n.n, nid)]);
			if(ckmin(dis[nid], nd))
				pq.push({nid, nd});
		}
	}

	/*
	for(int i=0;i<=K;++i)
	{
		for(int j=0;j<=K;++j)
			printf("[%d %d %d] ", dis[i+j*(K+1)], wx[i+j*(K+1)], wy[i+j*(K+1)]);
		printf("\n");
	}
	*/

	int ans=INF;
	for(int i=0;i<=K;++i)
		ckmin(ans, std::min({dis[i], dis[i+K*(K+1)], dis[i*(K+1)], dis[K+i*(K+1)]}));
	printf("%d\n", N - ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}