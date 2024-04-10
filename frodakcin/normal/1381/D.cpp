#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

template<typename T> bool ckmax(T& a, const T& b) {return a<b?a=b,1:0;}

const int MN = 1e5+10;

int T, N, A, B, h[MN], p[MN], am, bm;
bool ok, v[MN];
std::vector<int> a[MN], t;
std::queue<int> q;

void dfs(int n)
{
	for(int x:a[n])
		if(x!=p[n])
			p[x]=n, dfs(x);
}
void dfs1(int n)
{
	v[n]=1;
	h[n]=1;
	for(int x:a[n])
		if(!v[x])
		{
			dfs1(x);
			ckmax(h[n], h[x]+1);
		}
}
void dfs2(int n)
{
	v[n]=1;
	h[n]=1;
	for(int x:a[n])
		if(!v[x])
		{
			//printf("%d -> %d\n", n, x);
			dfs2(x);
			if(h[n]>=t.size() && h[x]+1 >= t.size())
				ok=1;
			ckmax(h[n], h[x]+1);
		}
}
void solve()
{
	ok=0;
	scanf("%d%d%d", &N, &A, &B);
	for(int i=0,x,y;i+1<N;++i)
		scanf("%d%d", &x, &y), a[x].push_back(y), a[y].push_back(x);
	p[A]=0; dfs(A);
	for(int n=B;n;n=p[n]) t.push_back(n);
	std::reverse(t.begin(), t.end());
	for(int x:t) v[x]=1;
	for(int x:t) dfs1(x);
	memset(v+1, 0, N*sizeof*v);
	for(int x:t) v[x]=1;

	am=0, bm=t.size()-1;
	q.push(1);
	q.push(-(int)t.size());
	for(int n;!q.empty();)
	{
		n=q.front(); q.pop();
		if(n<0)
		{
			n*=-1;--n;
			int nam=std::min(n-1, n-(int)t.size()+h[t[n]]);
			for(;am<nam;) q.push((++am)+1);
		}
		else
		{
			--n;
			int nbm=std::max(n+1, n+(int)t.size()-h[t[n]]);
			for(;bm>nbm;) q.push(-(--bm)-1);
		}
	}
	assert(am+1<t.size() && bm>0);
	for(int i=0;!ok&&i<t.size();++i)
	{
		int x=(i<=am)+(i>=bm);
		if(x==2&&h[t[i]]>=t.size()) ok=1;
		if(x==1) dfs2(t[i]);
	}

	if(ok) printf("YES\n");
	else printf("NO\n");
	t.clear();
	memset(v+1, 0, N*sizeof*v);
	for(int i=1;i<=N;++i) a[i].clear();
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}