#include <cstdio>
#include <cstring>
#include <algorithm>
#include <numeric>

template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

const int MN = 5e3+10;
const int K = 20; // exact

char bad[]="trygub";

int N, A, B, l[K], r[K], c[K], ord[K];
bool ok[1<<K], dp[1<<K];
char s[MN];

int main()
{
	std::sort(bad, bad+6);
	std::iota(ord, ord+K, 0);
	scanf("%d%d%d %s", &N, &A, &B, s);
	for(int i=0;i<N;++i)
	{
		int v=0;
		for(int j=0;j<6;++j) v += s[i] > bad[j];
		s[i] -= 97+v;
	}

	memset(l, -1, sizeof l);
	for(int i=0;i<N;++i)
	{
		if(l[s[i]]==-1)
			l[s[i]]=i;
		r[s[i]]=i;
		++c[s[i]];
	}
	std::sort(ord, ord+K, [](int u, int v){return l[u]<l[v];});

	for(int i=0;i<1<<K;++i)
	{
		int ub=-1, lb=N, num=0;
		for(int j=0;j<K;++j)
			if(i>>j&1)
				if(c[j])
					ckmin(lb, l[j]), ckmax(ub, r[j]), num += c[j];
		ok[i] = num == 0 || num*B >= A*(ub-lb+1);
	}

	dp[0]=1;
	for(int i=1;i<1<<K;++i)
	{
		if(ok[i])
			for(int j=0;j<K;++j)
				if(i>>j&1)
					dp[i] |= dp[i^1<<j];
		if(dp[i]) continue;

		int q=0, rb=-1;
		for(int k=0, j;k<K;++k)
		{
			j=ord[k];
			if(i>>j&1)
			{
				if(q && rb < l[j])
					dp[i] |= dp[q] && dp[i^q];
				q|=1<<j, ckmax(rb, r[j]);
			}
		}
	}

	int f=0;
	for(int i=0;i<K;++i)
		f += c[i] && dp[(1<<K)-1^1<<i];
	printf("%d", f);
	for(int i=0;i<K;++i)
		if(c[i] && dp[(1<<K)-1^1<<i])
		{
			char v=97+i;
			for(int j=0;j<6;++j)
				v += v >= bad[j];
			printf(" %c", v);
		}
	printf("\n");

	return 0;
}