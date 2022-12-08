#include <cstdio>
#include <vector>

template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

const int MN = 2e5+10;

int N, c[MN], X, D;
std::vector<int> a[MN];

void dfs(int n=1, int p=0, int cp=0, int l=0)
{
	if(c[n])
	{
		if(cp!=c[n]) ++l;
		cp=c[n];
	}

	if(ckmax(D, l)) X=n;

	for(int x:a[n])
		if(x!=p)
			dfs(x, n, cp, l);
}

void solve()
{
	scanf("%d", &N);
	for(int i=1;i<=N;++i) scanf("%d", c+i);
	for(int i=0,u,v;i+1<N;++i) scanf("%d%d", &u, &v), a[u].push_back(v), a[v].push_back(u);

	D=-1; dfs();
	D=-1; dfs(X);
	printf("%d\n", D/2+1);
}

void reset()
{
	for(int i=1;i<=N;++i) a[i].clear();
}

int T;
int main()
{
	scanf("%d", &T);
	while(T--) solve(), reset();
	return 0;
}