#include <iostream>
#include <cstdio>

using namespace std;

const int ML = 1e6 + 100;

char z[ML];
void in(int * s, int& N)
{
	scanf(" %s", z);
	for(N = 0;z[N];N++) s[N] = z[N]=='R'?0:z[N]=='B'?1:2;
}
int s[ML], t[ML], S, T;

int p[ML][9], l, r;
using ll = long long;
ll f;

void mr(void)
{
	for(int j = 0;j < 9;j++)
		p[r+1][j] = p[r][j];
	if(r)
		p[r+1][t[r-1]+3*t[r]]++;
}
int main(void)
{
	in(s, S), in(t, T);
	t[T] = 0;
	l = r = 0, f = 0LL;
	for(int i = 0, k;i < S;i++)
	{
		for(;r<T&&s[i] != t[r];r++)
			mr();
		if(r < T)
			mr(), r++;
		if(i&&s[i-1]!=s[i])
		{
			k = s[i]+3*s[i-1];
			f += r-l-(p[r][k]-p[l][k]);
		}
		else
			f += r-l;
		if((l+=t[l]==s[i])==T)
			break;
	}
	printf("%lld\n", f);
	return 0;
}