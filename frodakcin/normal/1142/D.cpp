#include <iostream>
#include <cstdio>

using namespace std;

using ll = long long;

const int MN = 1e5 + 100;

int N;
char s[MN];
int a[MN];
ll f;
int d[MN][11];

int u[11];

int main(void)
{
	scanf(" %s", s);
	for(N=0;s[N];N++) a[N] = s[N] - '0';
	for(int i = 0;i < 11;i++)
	{
		for(int j = 0;j < i;j++)
			u[i] += j;
		u[i] = (u[i] + 10)%11;
	}
	for(int i = 1;i <= N;i++)
	{
		int v = a[i-1];
		if(v)
			d[i][v]++;
		for(int j = v + 1;j < 11;j++)
			d[i][(u[j] + v)%11] += d[i-1][j];
		for(int j = 0;j < 11;j++)
			f += d[i][j];
	}
	printf("%lld\n", f);
	return 0;
}