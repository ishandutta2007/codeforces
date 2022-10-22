#include <bits/stdc++.h>
#define constant const constexpr
#define clr(x,v) std::memset(x,v,sizeof(x))
typedef long double db;
typedef long long ll;
typedef std::string str;
constant int iinf = 0x3f3f3f;
constant ll linf = 0x3f3f3f3f3f3fLL;
constant db pi = std::acos(-1.0);
constant db eps = 1e-10;
constant ll mod = 1e9+7;
constant int maxN = 4e5+3;
typedef int intvec[maxN];
typedef ll llvec[maxN];
typedef bool boolvec[maxN];
typedef str strvec[maxN];
typedef char c_str[maxN];
typedef db dbvec[maxN];
template <typename T> inline constant T abs(T x) {return x>=0?x:-x;}
void quicker() {std::ios_base::sync_with_stdio(false);std::cin.tie(nullptr);}
ll pow(ll x,ll n,ll m)
{
	n %= m-1;
	if (n<0) return pow(x,n*(2-m),m);
	ll ans=1LL,tmp=x;
	while (n)
	{
		if (n&1) ans = ans*tmp%m;
		tmp = tmp*tmp%m;
		n >>= 1;
	}
	return ans;
}
int lowbit(int x) {return x&-x;}

int N,M,K,S;
std::deque<int> goods[maxN];
std::priority_queue<int,std::vector<int>,std::greater<int>> distX[maxN];
intvec head,to,next;
int edge_count;
intvec dist;
boolvec used;
void add(int u,int v)
{
	to[edge_count] = v;
	next[edge_count] = head[u];
	head[u] = edge_count++;
}
void biadd(int u,int v)
{
	add(u,v);
	add(v,u);
}
void clear()
{
	std::fill_n(head,maxN,-1);
	std::fill_n(to,maxN,-1);
	std::fill_n(next,maxN,-1);
	edge_count = 0;
}
void pre()
{
	std::fill_n(used,maxN,false);
	std::fill_n(dist,maxN,0);
}
int main()
{
	clear();
	int tmp,tmp2;
	std::scanf("%d %d %d %d",&N,&M,&K,&S);
	//read
	for (int i=1;i<=N;++i)
	{
		std::scanf("%d",&tmp);
		goods[tmp].push_back(i);
 	}
 	for (int i=0;i<M;++i)
 	{
 		std::scanf("%d %d",&tmp,&tmp2);
 		biadd(tmp,tmp2);
	}
 	//solve
 	for (int p=1;p<=K;++p)
 	{
 		//bfs
 		pre();
		for (int k: goods[p])
		{
			used[k] = true;
			dist[k] = 0;
			distX[k].push(0);
		}
		while (!goods[p].empty())
		{
			int u = goods[p].front();
			goods[p].pop_front();
			for (int j=head[u];~j;j=next[j])
			{
				int v = to[j];
				if (used[v]) continue;
				dist[v] = dist[u] + 1;
				distX[v].push(dist[v]);
				used[v] = true;
				goods[p].push_back(v);
			}
		}
	}
	for (int i=1;i<=N;++i)
	{
		ll ans = 0;
		for (int j=0;j<S;++j)
		{
			int t = distX[i].top();
			distX[i].pop();
			ans += t;
		}
		std::printf("%I64d",ans);
		if (i!=N) std::printf(" ");
		else std::printf("\n");
	}
}