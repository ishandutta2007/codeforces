#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 50 + 5;
const int inf = 0x3f3f3f3f;

inline int rnd(void){ return (rand()<<15) | rand();}
inline int rnd(int l,int r){ return rnd() % (r-l+1) + l;}

int fa[MAXN];
inline void init(int n){ for(int i=1; i<=n; ++i) fa[i] = i;}
int find(int u){ return fa[u] == u? u: fa[u] = find(fa[u]);}
inline void connect(int u,int v){ fa[find(u)] = find(v);}

int n, d;
int a[MAXN][MAXN], b[MAXN], deg[MAXN];

vector< pair<int,pii> > e;
vector<pii> e2;
vector<int> has;

int mx_sum;

inline int get_res(void)
{
	init(n);
	int rem = n, sum = 0;
	for(int i=0; i<(int)has.size(); ++i) if(has[i])
	{
		int u = e2[i].first, v = e2[i].second;
		if(find(u) == find(v)) return mx_sum;
		sum += a[u][v];
		connect(u,v);
		--rem;
	}
	
	static int cur[MAXN];
	memcpy(cur, deg, (n+1)<<2);
	for(int i=0; i<(int)e.size() && rem>1; ++i)
	{
		int u = e[i].second.first, v = e[i].second.second;
		if(cur[u] == b[u] || cur[v] == b[v]) continue;
		if(find(u) != find(v))
		{
			sum += a[u][v];
			connect(u, v);
			--rem;
			++cur[u]; ++cur[v];
		}
	}
	
	return rem == 1? sum: mx_sum;
}

int main(void)
{
	srand((unsigned long long)new char ^ time(0));
	
	scanf("%d%d",&n,&d);
	for(int i=1; i<=d; ++i) scanf("%d",&b[i]);
	for(int i=1; i<=n; ++i)
		for(int j=i+1; j<=n; ++j)
		{
			scanf("%d",&a[i][j]);
			a[j][i] = a[i][j];
			
			if(i <= d) e2.push_back(make_pair(i,j));
			e.push_back(make_pair(a[i][j], make_pair(i,j)));
		}
	
	for(int i=d+1; i<=n; ++i) b[i] = inf;
	has.resize(e2.size());
	sort(e.begin(), e.end());
	
	mx_sum = inf;
	
	int ans = get_res(), cur = ans;
	int tot = 0;
	for(double T=1e6; T>=1e-6; T*=0.99993)
	{
		int pos;
		while(1)
		{
			pos = rand() % (int)e2.size();
			int u = e2[pos].first, v = e2[pos].second;
			if(has[pos])
			{
				--deg[u]; --deg[v]; has[pos] = 0;
				--tot;
				break;
			}
			else
			{
				if(tot >= n || deg[u] == b[u] || deg[v] == b[v]) continue;
				++deg[u]; ++deg[v]; has[pos] = 1;
				++tot;
				break;
			}
		}
		
		int res = get_res();
		if(res < cur){ cur = res; ans = min(ans, cur); continue;}
		if(rand() < exp(-(res - ans) / T) * RAND_MAX){ cur = res; continue;}
		
		int u = e2[pos].first, v = e2[pos].second; 
		if(has[pos])
		{
			--deg[u]; --deg[v];
			has[pos] = 0; --tot;
		}
		else
		{
			++deg[u]; ++deg[v];
			has[pos] = 1; ++tot;
		}
	}
	
	printf("%d",ans);
	return 0;
}