#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>

const int MG = 1e6 + 100;//CHECK CONSTRAINTS
bool u[MG], v[MG], c[MG];
char s[MG];
int dx[4], N, M, A, B, T;
std::vector<int> a[MG];
struct CYC
{
public:
	int n, l;
} cur;
std::stack<CYC> cyc;

bool dfs(int x)
{
	u[x] = v[x] = 1;
	int nx = x + dx[s[x]];
	a[nx].push_back(x);
	if(u[nx])
	{
		cyc.push({nx, 1});
		u[x] = 0;
		return u[nx] = 0, 1;
	}
	else if(v[nx])
		return u[x] = 0, 0;
	else
	{
		if(dfs(nx)) ++cyc.top().l;
		else return u[x] = 0, 0;
		if(!u[x]) return 0;
		return u[x] = 0, 1;
	}
}
void dfs2(int n, int d)
{
	v[n] = 1;
	if(c[n])
		u[d] = 1;
	for(int x : a[n])
		if(!v[x])
			dfs2(x, d+1 == cur.l ? 0 : d+1);
}

void solve()
{
	scanf("%d%d", &N, &M);
	dx[0] = -M, dx[1] = M, dx[2] = -1, dx[3] = 1;
	for(int i = 0;i < N;++i)
	{
		scanf(" %s", s);
		for(int j = 0;j < M;++j)
			c[i*M+j] = s[j] == '0';
	}
	for(int i = 0;i < N;++i)
		scanf(" %s", s+i*M);
	for(int i = N*M-1;i >= 0;--i)
		if(s[i] == 'U') s[i] = 0;
		else if(s[i] == 'D') s[i] = 1;
		else if(s[i] == 'L') s[i] = 2;
		else s[i] = 3;
	for(int i = 0;i < M*N;++i)
		if(!v[i])
			dfs(i);
	memset(u, 0, sizeof(u[0])*N*M);
	memset(v, 0, sizeof(v[0])*N*M);
	A = B = 0;
	for(;!cyc.empty();cyc.pop())
	{
		cur = cyc.top();
		dfs2(cur.n, 0);
		for(int i = 0;i < cur.l;++i)
			B += u[i];
		A += cur.l;
		memset(u, 0, sizeof(u[0])*cur.l);
	}
	memset(v, 0, sizeof(v[0])*N*M);
	for(int i = N*M-1;i >= 0;--i)
		a[i].clear();
	printf("%d %d\n", A, B);
}
int main(void)
{
	scanf("%d", &T);
	while(T--)
		solve();
	return 0;
}