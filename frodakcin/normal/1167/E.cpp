#include <cstdio>
#include <cstring>
#include <algorithm>

const int MN = 1e6+10;

int N, X;
int rb[MN], L[MN], R[MN], gl[MN], gr[MN], okb, oke;
int a[MN], min[MN];
long long ans;
int main(void)
{
	scanf("%d%d", &N, &X);
	memset(L, -1, sizeof L);
	memset(R, -1, sizeof R);
	for(int i=0;i<N;++i)
	{
		scanf("%d", a+i);
		if(!~L[a[i]]) L[a[i]] = i;
		R[a[i]] = i;
		if(i) gl[i] = std::max(a[i], gl[i-1]);
		else gl[i] = a[i];
	}
	for(int i=N-1;i>=0;--i)
	{
		if(i==N-1) gr[i] = a[i];
		else gr[i] = std::min(a[i], gr[i+1]);
	}
	for(int i=X;i>=1;--i)
		if(!~R[i] || gl[R[i]] <= i)
			oke = i-1;
		else
			break;
	for(int i=1;i<=X;++i)
		if(!~L[i] || gr[L[i]] >= i)
			okb = i+1;
		else
			break;

	min[1] = std::max(1, oke);
	for(int i=1;i<okb;++i)
	{
		if(~R[i])
			min[i+1] = std::max({i+1, gl[R[i]], oke});
		else
			min[i+1] = std::max(i+1, oke);//inclusive
	}
	for(int i=2;i<=okb;++i)
		min[i] = std::max(min[i], min[i-1]);

	for(int i=1;i<=okb;++i)
		ans += (X-min[i]+1);
	printf("%lld\n", ans);
	return 0;
}