#include <cstdio>
#include <vector>

const int MN = 2e5+10;
int N, c[2];
std::vector<int> a[MN];

void dfs(int n=1, int p=-1, bool d=0)
{
	++c[d];
	for(auto x:a[n])
		if(x!=p)
			dfs(x, n, !d);
}
int main()
{
	scanf("%d", &N);
	for(int i=1,x,y;i<N;++i)
		scanf("%d%d", &x, &y), a[x].push_back(y), a[y].push_back(x);
	dfs();
	printf("%d\n", std::min(c[0], c[1])-1);
	return 0;
}