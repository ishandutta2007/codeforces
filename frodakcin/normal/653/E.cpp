#include <cstdio>
#include <cstring>
#include <vector>
#include <set>

int fail() {return printf("impossible\n"), 0;}

const int MN = 3e5+10;
int N, M, K, w[MN], r, nr;
bool v[MN];
std::vector<int> a[MN], ok;
std::set<int> g[MN];

void del(int n)
{
	v[n]=1;
	for(auto x:a[n])
		if(w[x]==nr)
		{
			g[w[x]].erase(x);
			g[++w[x]].insert(x);
		}
}

int main()
{
	scanf("%d%d%d", &N, &M, &K);
	for(int i=0,x,y;i<M;++i)
		scanf("%d%d", &x, &y), a[x].push_back(y), a[y].push_back(x);
	if(a[1].size()+K>N-1) return fail();
	for(int x:a[1]) v[x]=1;
	for(int i=2;i<=N;++i)
	{
		if(!v[i])
			ok.push_back(i);
		g[0].insert(i);
	}

	memset(v, 0, sizeof v);
	for(int x:ok)
		if(!v[x])
		{
			if(!K--) return fail();
			del(x), ++nr;
			for(;r<nr;++r)
				for(auto y:g[r])
					if(!v[y])
						del(y), ++nr;
		}

	if(nr<N-1) return fail();
	printf("possible\n");
	return 0;
}