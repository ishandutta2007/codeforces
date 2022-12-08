#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>

const int MN=1e6+10, MM=2e6+10;

int N, M, d[MN], hd[MN], to[MM*2], nx[MM*2], E, f[MM], F, ans;
bool u[MM], g[MM], v[MN];

void adde(int x, int y)
{
	nx[E]=hd[x];
	to[E]=y;
	hd[x]=E++;
}
void dfs(int n=0, int pe=-1)
{
	v[n]=1;
	for(int i, x;~hd[n];hd[n]=nx[hd[n]])
	{
		i=hd[n]/2;
		if(u[i])
			continue;
		u[i]=1;
		x=to[hd[n]];
		dfs(x, i);
	}
	if(~pe)
		f[F++] = pe;
}
int main(void)
{
	memset(hd, -1, sizeof hd);
	scanf("%d%d", &N, &M);
	for(int i=0,x,y;i<M;++i)
		scanf("%d%d", &x, &y), adde(x, y), adde(y, x), ++d[x], ++d[y];
	//assert(E==M*2);
	for(int i=1;i<=N;++i)
		if(d[i]&1)
			adde(0, i), adde(i, 0), ++d[0], ++d[i];
	for(int i=0;i<=N;++i)
	{
		if(v[i]) continue;
		F=0;
		dfs(i);
		for(int j=1;j<F;j+=2)
			if(f[j-1]<M&&f[j]<M&&f[(j+1)%F]<M)
				g[f[j]]=1;
	}
	ans=0;
	for(int i=0;i<M;++i)
		if(!g[i])
			++ans;
	printf("%d\n", ans);
	for(int i=0;i<M;++i)
		if(!g[i])
			printf("%d %d\n", to[i<<1], to[i<<1|1]);
	return 0;
}