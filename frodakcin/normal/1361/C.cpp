#include <cstdio>
#include <cassert>
#include <vector>

const int MN = 5e5+10, MK=20;
int N;
int a[MN], b[MN], deg[1<<MK];
bool v[1<<MK], used[MN];
struct edge
{
	int n, id;
};
std::vector<edge> c[1<<MK];

int dfs(int n)
{
	int ctr=deg[n];
	v[n]=1;
	for(auto x:c[n])
		if(!v[x.n])
			ctr+=dfs(x.n);
	return ctr;
}
bool test(int bit, bool out = 0)//euler tour existence
{
	int all = (1<<bit)-1;
	for(int i=0;i<=all;++i)
		v[i] = deg[i] = 0, c[i].clear();
	for(int i=0;i<N;++i)
		++deg[a[i]&all], ++deg[b[i]&all], c[a[i]&all].push_back({b[i]&all, i<<1|1}), c[b[i]&all].push_back({a[i]&all, i<<1});
	for(int i=0;i<=all;++i)//all even deg
		if(deg[i]&1)
			return 0;
	if(dfs(a[0]&all) == N*2)//connected
		return 1;
	return 0;
}
void dfs2(int n, int p=-1)
{
	for(;!c[n].empty();)
	{
		edge x = c[n].back();
		c[n].pop_back();
		if(used[x.id/2])
			continue;
		used[x.id/2] = 1;
		dfs2(x.n, x.id);
		//printf("%d %d ", x.id+1, (x.id^1)+1);
	}
	if(~p)
		printf("%d %d ", p+1, (p^1)+1);
}
int main(void)
{
	scanf("%d", &N);
	for(int i=0;i<N;++i)
		scanf("%d%d", a+i, b+i);
	if(N==1) return printf("%d\n1 2\n", a[0]==b[0]?20:__builtin_ctz(a[0]^b[0])), 0;
	int ans=-1;
	for(int i=MK;i>=0;--i)
		if(test(i))
		{
			ans = i;
			break;
		}
	printf("%d\n", ans);
	dfs2(a[0]&(1<<ans)-1);
	printf("\n");
	return 0;
}