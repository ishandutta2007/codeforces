#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <numeric>

void fail() {printf("NO\n");}
const int MN = 1e5+10;
int T, N, X, Y, a[MN], b[MN], c[MN], E, o[MN], q[MN], Q;
std::vector<int> v[MN];
void solve()
{
	scanf("%d%d%d", &N, &X, &Y);
	memset(c+1, 0, (N+1)*sizeof*c);
	for(int i=1;i<=N+1;++i) v[i].clear();

	for(int i=0;i<N;++i) scanf("%d", a+i), ++c[a[i]], v[a[i]].push_back(i);
	E=N+1;
	for(int i=1;i<=N;++i)
		if(!c[i])
		{
			E=i;
			break;
		}
	std::iota(o, o+(N+1), 1);
	std::sort(o, o+(N+1), [](int u, int v){return c[u]>c[v];});

	memset(b, -1, N*sizeof*b);
	if(X==Y)
	{
		printf("YES\n");
		for(int i=0;i<Y;++i) printf("%d%c", a[i], " \n"[i+1==N]);
		for(int i=Y;i<N;++i) printf("%d%c", E, " \n"[i+1==N]);
		return;
	}
	else
	{
		if(Y-X&1)
		{
			int i=o[0],j=o[1],k=o[2];
			if(X+1==Y||!c[k])//place 1
			{
				if(Y==N||!c[j]) return fail();
				--c[i], --c[j];
				b[v[i].back()]=j;v[i].pop_back();
				b[v[j].back()]=E;v[j].pop_back();
				--Y;
			}
			else//place 3
			{
				if(!c[k]) return fail();
				--c[i], --c[j], --c[k];
				b[v[i].back()]=j;v[i].pop_back();
				b[v[j].back()]=k;v[j].pop_back();
				b[v[k].back()]=i;v[k].pop_back();
				Y-=3;
			}
		}
		std::sort(o, o+(N+1), [](int u, int v){return c[u]>c[v];});
		int match = Y-X>>1;
		//match must be less than N/2 as well
		Q=0;
		for(int i=0;i<N;++i)//o[N] must be empty
			for(int j:v[o[i]])
				q[Q++]=j;
		for(int i=0,j=std::max(match, c[o[0]]);i<match;++i, ++j)
		{
			if(j>=Q) return fail();
			b[q[i]]=a[q[j]];
			b[q[j]]=a[q[i]];
		}
	}

	printf("YES\n");
	for(int i=0;i<N;++i)
	{
		if(!~b[i])
		{
			if(X)b[i]=a[i], --X;
			else b[i]=E;
		}
		printf("%d%c", b[i], " \n"[i+1==N]);
	}
}
int main()
{
	scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}