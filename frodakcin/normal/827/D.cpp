#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

template<typename T> bool ckmax(T& a, T b){return a<b?a=b,1:0;}

const int MN = 2e5+10, MM = 2e5+10, MW = 1e9+10;
int N, M, dp[MN], dr[MN], p[MN][20], max[MN][20], w[MM], f[MM], to[MM*2], nx[MM*2], hd[MN], d[MN];
bool u[MM];
std::vector<int> add[MN], rem[MN];
std::multiset<int> set[MN];
struct edge
{
public:
	int u,v,w,i;
	bool operator < (edge o) const {return w<o.w;}
} e[MM];

int find(int n) {return dp[n]?dp[n]=find(dp[n]):n;}
bool merge(int a, int b)
{
	a=find(a),b=find(b);
	if(a==b) return 0;
	if(dr[a]<dr[b]) std::swap(a,b);
	dr[a]+=dr[a]==dr[b],dr[b]=-1,dp[b]=a;
	return 1;
}
void dfs(int n=1)
{
	for(int i=0;p[n][i]&&p[p[n][i]][i];++i)
		p[n][i+1]=p[p[n][i]][i], max[n][i+1]=std::max(max[n][i], max[p[n][i]][i]);
	for(int id=hd[n],x;~id;id=nx[id])
		if((x=to[id]) != p[n][0])
		{
			p[x][0]=n;
			max[x][0]=w[id>>1];
			d[x]=d[n]+1;
			dfs(x);
		}
}
int lca(int a, int b, int *w)
{
	*w = -1;
	if(d[b]<d[a]) std::swap(a,b);
	for(int i=0,x=d[b]-d[a];x;++i)
		if(x>>i&1)
			x^=1<<i, ckmax(*w, max[b][i]), b=p[b][i];
	if(a==b) return a;
	for(int i=17;i>=0;--i)
		if(p[a][i]!=p[b][i])
			ckmax(*w, std::max(max[a][i],max[b][i])),a=p[a][i],b=p[b][i];
	ckmax(*w, std::max(max[a][0], max[b][0]));
	return p[a][0];
}
void adde(int a, int b, int i)
{
	nx[i]=hd[a],hd[a]=i;
	to[i]=b;
}
void merge(std::multiset<int>& a, std::multiset<int>& b)
{
	if(a.size()<b.size()) std::swap(a,b);
	auto it=b.begin();
	for(;it!=b.end();it=b.erase(it))//this for loop isn't very fast but should be fine
		a.insert(*it);
}
void dfs2(int n=1)
{
	for(int x:add[n])
		set[n].insert(x);
	for(int id=hd[n],x;~id;id=nx[id])
		if((x=to[id]) != p[n][0])
		{
			dfs2(x);
			if(set[x].empty())
				f[id>>1]=-1;
			else
				f[id>>1] = *set[x].begin()-1;
			merge(set[n], set[x]);
		}
	for(int x:rem[n])
		set[n].erase(set[n].find(x));
}
int main(void)
{
	memset(hd, -1, sizeof hd);
	scanf("%d%d", &N, &M);
	for(int i=0,u,v;i<M;++i)
		scanf("%d%d%d", &u, &v, w+i), e[i]={u,v,w[i],i};
	std::sort(e, e+M);
	for(int i=0;i<M;++i)
		if(u[i]=merge(e[i].u, e[i].v))
			adde(e[i].u,e[i].v,e[i].i<<1), adde(e[i].v,e[i].u,e[i].i<<1|1);
	dfs();
	for(int i=0,x;i<M;++i)
		if(!u[i])
		{
			x = lca(e[i].u,e[i].v,f+e[i].i);
			--f[e[i].i];
			rem[x].push_back(e[i].w);
			rem[x].push_back(e[i].w);
			add[e[i].u].push_back(e[i].w);
			add[e[i].v].push_back(e[i].w);
		}
	dfs2();
	for(int i=0;i<M;++i)
		printf("%d%c", f[i], " \n"[i+1==M]);
	return 0;
}