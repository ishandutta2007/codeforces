#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e2 + 5;

template<typename T>
inline void chk_max(T &a,T b){ if(a<b) a=b;}

struct Edge
{
	int next,to;
}e[MAXN<<1];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot] = (Edge){ head[u],v};
	head[u] = etot;
}

int n,d;
int a[MAXN];
deque<ll> qs[MAXN], *dp[MAXN];

void merge(deque<ll> *&p_,deque<ll> *&q_)
{
	if(p_ -> size() > q_ -> size()) swap(p_,q_);
	deque<ll> &p = *p_, &q = *q_;
	
	for(int i=0; i<(int)p.size(); ++i)
	{
		ll tmp = p[i];
		
		if(d+1-i < (int)q.size())
			tmp = p[i] + q[max(i, d+1-i)];
		
		if(d+1-i < (int)p.size())
			chk_max(tmp, q[i] + p[max(i, d+1-i)]);
		
		chk_max(q[i], tmp);
	}
	
	for(int i=p.size()<q.size()? (int)p.size()-1: (int)p.size()-2; i>=0; --i)
		chk_max(q[i], q[i+1]);
	
	p.clear();
}

void dfs_dp(int u,int fa)
{
	dp[u] = &qs[u];
	dp[u] -> push_back(a[u]);
	
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dfs_dp(v,u);
		
		dp[v] -> push_front(0);
		merge(dp[v], dp[u]);
	}
	
	if((int)dp[u] -> size() > d+1)
		dp[u] -> resize(d+1);
}

int main(void)
{
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	dfs_dp(1,0);
	
	printf("%lld",(*dp[1])[0]);
	return 0;
}