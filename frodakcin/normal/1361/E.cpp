#include <cstdio>
#include <ctime>
#include <cstring>
#include <random>
#include <numeric>
#include <algorithm>
#include <vector>

const int MAGIC = 100, MN = 1e5+10, MM = 2e5+10;

std::mt19937 rng(time(NULL));
int N, M, T, c[MN], t[MN], b[MN], d[MN], cnt[MN], dif[MN], at[MN], l[MN], jmp[MN], s[MN];
bool u[MN], v[MN], ok[MN];
std::vector<int> a[MN], ans;

bool dfst(int n)
{
	v[n]=u[n]=1;
	s[n]=1;
	for(int x:a[n])
		if(u[x])
			continue;
		else if(v[x])
			return 0;
		else
		{
			if(!dfst(x))
				return 0;
			s[n]+=s[x];
		}
	u[n]=0;
	return 1;
}
bool test(int n)
{
	memset(u+1, 0, N*sizeof*u);
	memset(v+1, 0, N*sizeof*v);
	return dfst(n) && s[n] == N;
}
void dfs(int n)
{
	v[n]=1;
	at[d[n]]=n, dif[d[n]]=0;
	cnt[n]=0, l[n]=d[n];
	for(int x:a[n])
		if(v[x])
		{
			++cnt[n];
			++dif[d[x]];
			l[n]=std::min(l[n], d[x]);
		}
		else
		{
			d[x]=d[n]+1;
			dfs(x);
			l[n]=std::min(l[n], l[x]);
			cnt[n] += cnt[x];
		}
	cnt[n] -= dif[d[n]];
	if(cnt[n]==1)
		jmp[n]=at[l[n]];
	else
		jmp[n]=-1;
}
void dfs2(int n)
{
	v[n]=1;
	if(!ok[n]&&~jmp[n])
		ok[n]=ok[jmp[n]];
	for(int x:a[n])
		if(!v[x])
			dfs2(x);
}
void solve(int n)
{
	memset(v+1, 0, N*sizeof*v);
	d[n]=0;
	dfs(n);
	memset(ok+1, 0, N*sizeof*ok);
	memset(v+1, 0, N*sizeof*v);
	ok[n]=1;
	dfs2(n);
}
int main(void)
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &N, &M);
		for(int i=0,x,y;i<M;++i)
			scanf("%d%d", &x, &y), a[x].push_back(y);
		std::iota(b, b+N, 1);
		std::shuffle(b, b+N, rng);
		for(int i=std::min(MAGIC, N)-1;i>=0;--i)
			if(test(b[i]))
			{
				solve(b[i]);
				for(int i=1;i<=N;++i)
					if(ok[i])
						ans.push_back(i);
				break;
			}
		if(ans.size()*5 < N)
			printf("-1\n");
		else
			for(int i=0;i<ans.size();++i)
				printf("%d%c", ans[i], " \n"[i+1==ans.size()]);
		ans.clear();
		for(int i=1;i<=N;++i)
			a[i].clear();
	}
}