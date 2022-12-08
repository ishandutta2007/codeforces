#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

const int MN = 1e3 + 100;
int N;
struct E
{
public:
	int n, v;
};
vector<E> a[MN];
bool test(void)
{
	for(int i = 1;i <= N;i++)
		if(a[i].size() == 2)
			return 0;
	return 1;
}

int c[MN][MN];
int l[MN];
int r;
int predfs(int n, int p = 0)
{
	int e = 0;
	for(E& x : a[n])
		if(x.n == p);
		else
			l[n]=predfs(x.n,n), e++;
	if(!e) l[n]=n;
	return l[n];
}
void push(int a, int b, int x, int y, int v)
{
	//printf("%d %d %d %d %d\n", a, b, x, y, v);
	c[a][b]-=v>>1;
	c[x][y]-=v>>1;
	c[a][x]+=v>>1;
	c[b][y]+=v>>1;
}
int dfs(int n, int p = 0, int v = 0, int o = 0) //returns any leaf in subtree
{
	int e = 0, f = l[n];
	for(E& x : a[n])
		if(x.n == p);
		else if(e++)
			dfs(x.n, n, x.v, l[n]);
		else
			l[n] = dfs(x.n, n, x.v, n!=r?l[n]:r);
	//printf("\t%d %d %d\n", n, f, l[n]);
	if(v)
		push(f, l[n], r, o, v);
	return l[n];
}

int main(void)
{
	scanf("%d", &N);
	for(int i = 0, x, y, v;i < N-1;i++)
		scanf("%d%d%d", &x, &y, &v), a[x].push_back({y,v}), a[y].push_back({x,v});
	if(!test())
		return printf("NO\n"), 0;
	for(int i = 1;i <= N;i++)
		if(a[i].size() == 1) {r = i; break;}
	//assert(1 <= r && r <= N);
	predfs(r);
	dfs(r);
	for(int i = 1;i <= N;i++)
		for(int j = i+1;j <= N;j++)
			c[i][j]+=c[j][i];
	int m = 0;
	for(int i = 1;i <= N;i++)
		for(int j = i+1;j <= N;j++)
			if(c[i][j])
				m++;
	printf("YES\n%d\n", m);
	for(int i = 1;i <= N;i++)
		for(int j = i+1;j <= N;j++)
			if(c[i][j])
				printf("%d %d %d\n", i, j, c[i][j]);
	return 0;
}