#include <cstdio>
#include <cstring>
#include <cassert>

int N, a[303000], p[303000], c[303000*30][2], s[303000*30], X;

int main()
{
	memset(c, -1, sizeof c);
	scanf("%d", &N);
	for(int i=0;i<N;++i)
		scanf("%d", a+i);
	for(int i=0;i<N;++i) scanf("%d", p+i);
	for(int i=0;i<N;++i)
	{
		int n=0;
		for(int j=29;j>=0;--j)
		{
			bool x=p[i]>>j&1;
			++s[n];
			n=~c[n][x]?c[n][x]:c[n][x]=++X;
		}
		++s[n];
	}
	for(int i=0;i<N;++i)
	{
		int n=0;
		int v=0;
		for(int j=29;j>=0;--j)
		{
			bool x=a[i]>>j&1;
			--s[n];
			if(~c[n][x] && s[c[n][x]]) n=c[n][x];
			else n=c[n][!x], v|=1<<j;
			assert(~n && s[n]);
		}
		--s[n];
		printf("%d%c", v, " \n"[i+1==N]);
	}
	return 0;
}