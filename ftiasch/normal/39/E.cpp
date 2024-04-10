#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int a, b, n, sqrt_a, f[40000][40], g[40];

bool over(int a, int b)
{
	long long s = 1;
	for(int i = 0; i < b; ++ i)
	{
		s *= (long long)(a);
		if(s >= n)
			return true;
	}
	return false;
}

int solve(int a, int b)
{
	if(a >= sqrt_a && b == 1)
		return (n - 1 - a) & 1;
	if(f[a][b] == -1)
	{
		f[a][b] = 0;
		if(!over(a + 1, b) && !solve(a + 1, b))
			f[a][b] = 1;
		if(!over(a, b + 1) && !solve(a, b + 1))
			f[a][b] = 1;
	}
	return f[a][b];
}

int main()
{
	scanf("%d%d%d", &a, &b, &n);
	memset(f, -1, sizeof(f));
	sqrt_a = (int)ceil(sqrt(n));
	if(a == 1)
	{
		g[39] = 2;
		for(int i = 38; i >= b; -- i)
		{
			g[i] = (g[i + 1] == 2)? 2: 0;
			if(!g[i + 1])
				g[i] = 1;
			if(!over(2, i) && !solve(2, i))
				g[i] = 1;				
		}
		if(g[b] == 2)			
			printf("Missing\n");
		else
			printf(g[b] == 1? "Masha\n": "Stas\n");
	}
	else
		printf(solve(a, b) == 1? "Masha\n": "Stas\n");
	return 0;
}