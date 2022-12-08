#include <cstdio>
#include <vector>

template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

const int MN = 1e5+10;

int T, N, A, B, DA, DB, maxd, fn, d[MN];
std::vector<int> a[MN];

void dfs(int n, int p=0)
{
	if(ckmax(maxd, d[n]))
		fn=n;
	for(int x:a[n])
		if(x!=p)
			d[x]=d[n]+1, dfs(x, n);
}
int main()
{
	scanf("%d", &T);
	for(int tc=1;tc<=T;++tc)
	{
		for(int i=1;i<=N;++i) a[i].clear();

		scanf("%d%d%d%d%d", &N, &A, &B, &DA, &DB);
		for(int i=0,u,v;i+1<N;++i)
			scanf("%d%d", &u, &v), a[u].push_back(v), a[v].push_back(u);
		if(DA*2>=DB)
		{
			printf("Alice\n");
			continue;
		}
		maxd=-1;d[A]=0;dfs(A);
		if(d[B] <= DA)
		{
			printf("Alice\n");
			continue;
		}
		maxd=-1;d[fn]=0;dfs(fn);
		if(maxd > DA*2)
			printf("Bob\n");
		else
			printf("Alice\n");
	}
	return 0;
}