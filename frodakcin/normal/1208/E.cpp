#include <cstdio>
#include <algorithm>

template<class T> bool mx(T* a, T b) {return *a<b?*a=b,1:0;}

using ll = long long;
const int MN = 1e6 + 100;
const int INF = 1e9 + 100;
int N, W;

ll p[MN], f;
int L, l[MN], m;
int q[MN];

void solve(void)
{
	scanf("%d", &L);
	for(int i = 0;i < L;i++) scanf("%d", l+i);
	if(L*2<W)
	{
		p[0] += m = std::max(l[0], 0);
		for(int i = 1;i < L;i++)
			if(l[i]>m)
				p[i]-=m, p[i]+=m=l[i];
		m = std::max(l[L-1], 0);
		for(int i = 1;i < L;i++)
			if(l[L-i-1]>m)
				p[W-i]+=m, p[W-i]-=m=l[L-i-1];
	}
	else
	{
		int k = W-L;
		for(int x = 0, i = 0, j = 0, a = 0, b;x < W;x++)
		{
			if(x < L)
			{
				for(;j>i&&l[q[j-1]]<=l[x];--j);
				q[j++] = x;
			}
			if(q[i]+k<x) ++i;
			b = l[q[i]];
			if(b < 0 && (x>=L||x+L<W)) b = 0;
			p[x] += b-a, a=b;
		}
	}
}
int main(void)
{
	scanf("%d%d", &N, &W);
	for(int i = 0;i < N;i++)
		solve();
	for(int i = 0;i < W;i++)
		printf("%lld%c", f+=p[i], " \n"[i==W-1]);
	return 0;
}