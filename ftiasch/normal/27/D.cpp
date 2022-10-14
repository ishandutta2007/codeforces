// Codeforces Beta Round #27
// Problem D -- Ring Road 2
#include <cstdio>
#include <cstring>

#define N 100

using namespace std;

int n, m, a[N], b[N], c[N];
bool flag = true;

void dfs(int u, int p)
{
	int dt = (n - a[u]) % n;
	if(c[u] == -1)
	{
		c[u] = p;
		for(int v = 0; v != m; ++ v)
			if((a[v] + dt) % n && (b[v] + dt) % n && ((a[v] + dt) % n - (b[u] + dt) % n) * ((b[v] + dt) % n - (b[u] + dt) % n) < 0)
				dfs(v, 1 - p);
	}
	else
	if(c[u] != p)
		flag = false;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i != m; ++ i)
	{
		scanf("%d%d", a + i, b + i);
		a[i] --, b[i] --;
	}
	memset(c, -1, sizeof(c));
	for(int i = 0; i != m; ++ i)
		if(c[i] == -1)
			dfs(i, 0);
	if(flag)
		for(int i = 0; i != m; ++ i)
			printf("%c", c[i]? 'i': 'o');
	else
		printf("Impossible");
	printf("\n");
	return 0;
}