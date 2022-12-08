#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <vector>

const int MN = 1e3+10;
int T, N, d[MN], p[MN], L, X, root;
std::vector<int> a[MN], q, in[MN];
bool u[MN];
char s[100];

void dfs(int n)
{
	in[d[n]].push_back(n);
	for(auto x:a[n])
		if(p[n]!=x)
			p[x]=n, d[x]=d[n]+1, dfs(x);
}
void solve()
{
	scanf("%d", &N);
	for(int i=0,x,y;i+1<N;++i)
		scanf("%d%d", &x, &y), a[x].push_back(y), a[y].push_back(x);

	printf("? %d", N); for(int i=1;i<=N;++i) printf(" %d", i); printf("\n");
	fflush(stdout);
	scanf("%d%d", &root, &L);
	if(!~root||!~L) exit(0);

	d[root]=0, p[root]=0, dfs(root);
	int l = (L+1)/2, r=L+1;//l = answer
	X=-1;
	for(;r-l>1;)
	{
		int m=l+(r-l)/2;
		for(int i=m;i<=L;++i)
			for(auto x:in[i])
				q.push_back(x);
		int x, d;
		if(!q.empty())
		{
			printf("? %u", q.size()); for(auto x:q)printf(" %d", x);printf("\n");
			fflush(stdout);
			q.clear();

			scanf("%d%d", &x, &d);
			if(!~x||!~d) exit(0);
		}
		else
		{
			d=-1, x=-1;
		}
		if(d == L)
		{
			l=m;
			if(!~X || ::d[x] > ::d[X])
				X = x;
		}
		else
			r=m;
	}
	if(!~X || d[X] != l)
	{
		for(auto x:in[l]) q.push_back(x);
		printf("? %u", q.size()); for(auto x:q)printf(" %d", x);printf("\n");
		fflush(stdout);
		q.clear();
		scanf("%d%*d", &X);
		if(!~X) exit(0);
	}
	for(int i=X;i!=root;i=p[i])
		u[i]=1;
	int t = L-d[X];
	for(auto x:in[t]) if(!u[x]) q.push_back(x);
	if(q.size()>1)
	{
		printf("? %u", q.size()); for(auto x:q)printf(" %d", x);printf("\n");
		fflush(stdout);
		q.clear();

		scanf("%d%*d", &t);
		if(!~t) exit(0);
	}
	else
		t=q[0], q.clear();
	printf("! %d %d\n", X, t);
	fflush(stdout);

	scanf(" %s", s);
	if(s[0]=='I') exit(0);

	memset(u+1, 0, N*sizeof*u);
	for(int i=0;i<N;++i) in[i].clear(), a[i+1].clear();
}

int main()
{
	scanf("%d", &T);
	for(;T--;)
		solve();
	return 0;
}