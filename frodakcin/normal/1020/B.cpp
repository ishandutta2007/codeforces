#include <cstdio>

const int MN = 1e3+10;

int N, p[MN], f[MN];
bool v[MN], u[MN];
int dfs(int n)
{
	v[n]=u[n]=1;
	if(u[p[n]]) return f[n]=n, u[p[n]]=0, u[n]=0, -1;
	else if(v[p[n]]) return u[n]=0, f[n]=f[p[n]];
	else
	{
		int t=dfs(p[n]);
		if(~t) return u[n]=0, f[n]=t;
		else if(u[n]) return u[n]=0, f[n]=n, -1;
		else return f[n]=n;
	}
}
int main()
{
	scanf("%d", &N);
	for(int i=1;i<=N;++i)
		scanf("%d", p+i);
	for(int i=1;i<=N;++i)
		if(!v[i])
			dfs(i);
	for(int i=1;i<=N;++i)
		printf("%d%c", f[i], " \n"[i==N]);
	return 0;
}