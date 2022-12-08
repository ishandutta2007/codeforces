#include <cstdio>

const int MN = 1e6 + 100;

int N;
int a[MN];
bool u[MN], v[MN];
int f[MN], F;

int dfs(int n)
{
	if(u[n]) return u[n] = 0, 1;
	if(v[n]) return 0;
	u[n] = v[n] = 1;
	int t = dfs(a[n]);
	if(t == 1)
	{
		f[F++] = n;
		return u[n]?u[n]=0,1:2;
	}
	u[n] = 0;
	return t;
}
void solve()
{
	scanf("%d", &N);
	for(int i = 0, x;i < N;++i)
		scanf("%d", &x), a[i] = i-x;
	for(int i = 0;i < N;++i)
		if(dfs(i))
			break;
	printf("%d\n", F);
	for(;F;)
		--F, printf("%d%c", f[F]+1, " \n"[!F]);
	for(int i = 0;i < N;++i)
		v[i] = 0;
}

int T;
int main(void)
{
	scanf("%d", &T);
	for(;T--;)
		solve();
	return 0;
}