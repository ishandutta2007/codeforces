// Codeforces Beta Round #13
// Problem E -- Holes
#include <cmath>
#include <cstdio>
#include <algorithm>

#define N 100000

#define BLOCK(x) ((x) / c)

using namespace std;

int n, m, power[N], c, next[N], step[N];

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i != n; ++ i)
		scanf("%d", power + i);
	c = int(floor(sqrt(n)));
	for(int i = n - 1; i != -1; -- i)
		if(i + power[i] >= n || BLOCK(i + power[i]) != BLOCK(i))
			next[i] = i + power[i], step[i] = 1;
		else
			next[i] = next[i + power[i]], step[i] = step[i + power[i]] + 1;
	for(; m; -- m)
	{
		int t, a, b;
		scanf("%d%d", &t, &a);
		if(t)
		{
			int tmp, ans = 0;
			for(tmp = a - 1; next[tmp] < n; ans += step[tmp], tmp = next[tmp]);
			while(tmp + power[tmp] < n)
				tmp += power[tmp], ans ++;
			printf("%d %d\n", tmp + 1, ans + 1);
		}
		else
		{
			scanf("%d", &b);
			power[a - 1] = b;
			a = c * BLOCK(a - 1);
			for(int i = min(n - 1, a + c - 1); i != a - 1; -- i)
				if(i + power[i] >= n || BLOCK(i + power[i]) != BLOCK(i))
					next[i] = i + power[i], step[i] = 1;
				else
					next[i] = next[i + power[i]], step[i] = step[i + power[i]] + 1;			
		}
	}
	return 0;
}