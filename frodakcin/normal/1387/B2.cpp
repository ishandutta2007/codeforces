#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>

template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}
template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}

const int MN = 1e5+10;
const int INF = 0x3f3f3f3f;

using ll = long long;

int N, ord[MN], ctr, ans[MN], s[MN];
ll f;
std::vector<int> a[MN];

int dfs(int n=1, int p=0)
{
	s[n]=1;
	for(int x:a[n])
		if(x!=p)
			s[n]+=dfs(x, n);
	return s[n];
}

int get_centroid(int n, int ms, int p=0)
{
	for(int x:a[n])
		if(x!=p && 2*s[x] >= ms)
			return get_centroid(x, ms, n);
	return n;
}

void dfs2(int n, int p=0)
{
	ord[ctr++]=n;
	s[n]=1;
	for(int x:a[n])
		if(x!=p)
			dfs2(x, n), s[n]+=s[x];
	f += s[n]*2;
}
int main()
{
	scanf("%d", &N);
	for(int i=0,x,y;i+1<N;++i)
		scanf("%d%d", &x, &y), a[x].push_back(y), a[y].push_back(x);
	int C = get_centroid(1, dfs());
	dfs2(C); f-=N*2;
	assert(ctr == N);
	for(int i=0;i<N;++i)
		ans[ord[i]] = ord[(i+N/2)%N];
	printf("%lld\n", f);
	for(int i=1;i<=N;++i)
		printf("%d%c", ans[i], " \n"[i==N]);
	return 0;
}