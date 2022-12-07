#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2005;
int n, i, j, p, res;
int S [N];
int c [N];
int out [N];
vector <int> e [N];
vector <int> vec [N];

void dfs (int u)
	{
	S[u] = 1;
	for (int v : e[u])
		{
		dfs(v);
		S[u] += S[v];
		for (int i : vec[v])
			vec[u].push_back(i);
		}

	if (c[u]+1 > S[u])
		{
		printf("NO\n");
		exit(0);
		}

	vec[u].insert(vec[u].begin() + c[u], u);
	}

int main ()
	{
	scanf ("%d", &n);
	for (i=1; i<=n; i++)
		{
		scanf("%d%d", &p, &c[i]);
		if (p == 0) j = i;
		e[p].push_back(i);
		}

	dfs(j);

	res = 1;
	for (int i : vec[j])
		out[i] = res++;
	
	printf("YES\n");

	for (i=1; i<=n; i++)
		printf("%d ", out[i]);
	printf ("\n");

	return 0;
	}