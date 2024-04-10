#include <cstdio>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <vector>

const int MN = 1e5+10;
int N, M, K, d[MN], p[MN];
bool v[MN];
std::vector<int> a[MN], c[2];
void tree(int n=1, int p=0, int b=0)
{
	c[b].push_back(n);
	for(int x:a[n])
		if(x!=p)
			tree(x, n, !b);
}
void try1(int n=1)
{
	v[n]=1;
	for(int x:a[n])
	{
		if(p[n] == x) continue;
		if(v[x])
		{
			if(d[x] > d[n]) continue;
			if(d[n]-d[x]<K)
			{
				printf("2\n");
				printf("%d\n", d[n]-d[x]+1);
				for(int k=n;k!=x;k=p[k])
					printf("%d ", k);
				printf("%d\n", x);
				exit(0);
			}
		}
		else
			p[x]=n, d[x]=d[n]+1, try1(x);
	}
}
void try2(int n=1)
{
	v[n]=1;
	int lc=-1;
	for(int x:a[n])
	{
		if(p[n] == x) continue;
		if(v[x])
		{
			if(d[x] > d[n]) continue;
			if(!~lc || d[x] > d[lc])
				lc=x;
		}
		else
			try2(x);//no need to set p,d
	}
	if(~lc)
	{
		printf("1\n");
		assert(d[n]-d[lc]+1 > K);
		for(int k=n, l=0;l < K;k=p[k], ++l)//should be ok not including x
			if(!(l&1))
				printf("%d ", k);
		printf("\n");
		exit(0);
	}
}
int main(void)
{
	scanf("%d%d%d", &N, &M, &K);
	for(int i=0,x,y;i<M;++i)
		scanf("%d%d", &x, &y), a[x].push_back(y), a[y].push_back(x);
	if(M+1==N)
	{
		tree();
		if(c[1].size() > c[0].size()) std::swap(c[0], c[1]);
		printf("1\n");
		for(int i=0;i<(K+1)/2;++i)
			printf("%d ", c[0][i]);
		printf("\n");
		return 0;
	}
	try1();
	memset(v, 0, sizeof v);
	try2();
	assert(0);
	return 0;
}