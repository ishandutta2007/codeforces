// Codeforces Beta Round #17
// Problem E -- Palisection
#include <cstdio>
#include <cstring>
#include <algorithm>

#define N 4000000
#define M 51123987

using namespace std;

int n, l[N];
char s[N];
long long c[3][N];

int main()
{
	scanf("%d%s", &n, s);
	long long a = 1;
	l[0] = 1;
	for(int i = 1, j = 0; i != (n << 1) - 1; ++ i)
	{
		int p = i >> 1, q = i - p, r = ((j + 1) >> 1) + l[j] - 1;
		l[i] = r < q? 0: min(r - q + 1, l[(j << 1) - i]);
		while(p - l[i] != -1 && q + l[i] != n && s[p - l[i]] == s[q + l[i]])
			l[i] ++;
		if(q + l[i] - 1 > r)
			j = i;
		a += l[i];
	}
	a %= M, a = ((a * (a - 1)) % M * 25561994) % M;
	memset(c, 0, sizeof(c));
	for(int i = 0; i != (n << 1) - 1; ++ i)
	{
		int p = i >> 1;
		c[0][p] ++;
		if(p - l[i] != -1)
			c[0][p - l[i]] --;
	}
	for(int i = n - 1; i != -1; -- i)
		c[2][i] = (c[2][i + 1] + (c[1][i] = c[1][i + 1] + (c[0][i] += c[0][i + 1]))) % M;	
	for(int i = 0; i != (n << 1) - 1; ++ i)
	{
		int q = (i + 1) >> 1;
		a = (a - c[2][q + 1] + c[2][q + l[i] + 1]) % M;
	}
	printf("%d\n", int((a + M) % M));
	return 0;
}