#include <cstdio>
#include <vector>
#include <set>
#include <cassert>

const int MD = 2520;
const int LMD = MD*400000;
const int MN = 1e3 + 10;
const int MX = MD*MN;
int N, m[MN], k[MN], Q;
std::vector<int> e[MN];
bool v[MN][MD], u[MN][MD], ic[MN][MD];
int c[MN][MD], C;
std::set<int> q[MX];

int dfs(int n, int t)
{
	v[n][t] = u[n][t] = 1;
	int y = t+k[n];
	if(y>=MD) y-=MD;
	int x = e[n][y%m[n]];
	if(n==x && t==y)
		return c[n][t] = ++C, ic[n][t] = 1, u[n][t] = 0, -C;
	if(u[x][y])
		return c[x][y] = c[n][t] = ++C, ic[n][t] = 1, u[x][y] = u[n][t] = 0, C;
	else if(v[x][y])
		return ic[n][t] = 0, u[n][t] = 0, -(c[n][t]=c[x][y]);
	else
	{
		int z = dfs(x,y);
		if(ic[n][t] = z>0) c[n][t] = z;
		else c[n][t] = -z;
		if(z>0 && !u[n][t]) z = -z;
		u[n][t] = 0;
		return z;
	}
}
int main(void)
{
	scanf("%d", &N);
	for(int i = 1;i <= N;i++)
		scanf("%d", k+i), k[i] = (k[i]+LMD)%MD;
	for(int i = 1;i <= N;i++)
	{
		scanf("%d", m+i);
		e[i].assign(m[i], 0);
		for(int& x : e[i]) scanf("%d", &x);
	}
	for(int i = 1;i <= N;i++)
		for(int j = 0;j < MD;j++)
			if(!v[i][j])
				dfs(i, j);
	//for(int i = 1;i <= N;i++) for(int j = 0;j < MD;j++) printf("%d %d: %d %d\n", i, j, c[i][j], ic[i][j]);
	for(int i = 1;i <= N;i++)
		for(int j = 0;j < MD;j++)
			if(ic[i][j])
				q[c[i][j]].insert(i);
	scanf("%d", &Q);
	for(int i = 0, x, y;i < Q;i++)
		scanf("%d%d", &x, &y), printf("%d\n", q[c[x][(y+LMD)%MD]].size());
	return 0;
}