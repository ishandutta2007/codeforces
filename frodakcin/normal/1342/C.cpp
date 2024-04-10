#include <cstdio>

using ll = long long;

int p[202*202], A, B, C, T, Q;
ll L, R;
void brute()
{
	for(int i = 0;i < C;++i)
		if(i%A%B != i%B%A)
			p[i] = 1;
		else
			p[i] = 0;
	p[C] = 0;
	for(int i = 0;i < C;++i)
		p[i+1] += p[i];
}
ll solve(ll v)
{
	return  p[C]*(v/C) + p[v%C];
}
int main(void)
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &A, &B, &Q);
		C = A*B;
		brute();
		while(Q--)
		{
			scanf("%lld%lld", &L, &R);
			printf("%lld%c", solve(R)-solve(L-1), " \n"[!Q]);
		}
	}
	return 0;
}