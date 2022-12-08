#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>

template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}
template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}

const int MN = 1e5+10;
const int INF = 0x3f3f3f3f;

int N, dp[MN*2][2], ans[MN], en[MN], X;
std::vector<int> a[MN], b[MN], st[MN], cur;

void dfs(int n=1, int p=0)
{
	st[n].push_back(X++);
	dp[st[n].back()][0]=0,dp[st[n].back()][1]=INF;
	for(int x:a[n])
		if(x!=p)
		{
			dfs(x, n);
			dp[X][1] = std::min(dp[st[n].back()][1]+dp[X-1][1], std::min(dp[st[n].back()][0], dp[st[n].back()][1])+std::min(dp[X-1][0], dp[X-1][1])+1);
			dp[X][0] = std::min(INF, dp[st[n].back()][0]+dp[X-1][1]);
			st[n].push_back(X++);
		}
}

void adde(int u, int v) {b[u].push_back(v), b[v].push_back(u);}

void dfs2(int n, int p, bool m)//m = whether or not it was matched
{
	auto nx=st[n].rbegin(), it=nx++;
	for(int i=a[n].size()-1,x;i>=0;--i)
		if((x=a[n][i])!=p)
		{
			if(!m)
				dfs2(x, n, 1);
			else
			{
				int o=st[x].back();
				if(dp[*it][1]==dp[*nx][1]+dp[o][1])
					dfs2(x, n, 1);
				else if(dp[*it][1]==dp[*nx][0]+dp[o][1]+1)
					dfs2(x, n, 1), adde(n, x), m=0;
				else if(dp[*it][1]==dp[*nx][1]+dp[o][0]+1)
					dfs2(x, n, 0), adde(n, x);
				else if(dp[*it][1]==dp[*nx][0]+dp[o][0]+1)
					dfs2(x, n, 0), adde(n, x), m=0;
				else assert(0);//not possible
			}
			it=nx++;
		}
}

void dfs3(int n, int p=0)
{
	cur.push_back(n);
	for(int x:b[n])
		if(x!=p)
			dfs3(x, n);
}

int main()
{
	scanf("%d", &N);
	for(int i=0,x,y;i+1<N;++i)
		scanf("%d%d", &x, &y), a[x].push_back(y), a[y].push_back(x);
	dfs();
	printf("%d\n", dp[X-1][1]*2);
	dfs2(1, 0, 1);
	for(int i=1;i<=N;++i)
		if(!ans[i])
		{
			dfs3(i);
			ans[cur[0]]=cur.back();
			for(int i=1;i<cur.size();++i) ans[cur[i]]=cur[i-1];
			cur.clear();
		}
	for(int i=1;i<=N;++i) printf("%d%c", ans[i], " \n"[i==N]);
	return 0;
}