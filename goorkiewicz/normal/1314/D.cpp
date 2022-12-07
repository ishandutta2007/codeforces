#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf = 1000000005;
const int N = 81;
const int K = 11;
int n, i, j, d, k, T, out, seed;
int e [N][N];
int dis [N][N];
bool col [N];

inline int fastrand ()
	{ 
	seed = (214013 * seed + 2531011); 
	return ((seed>>16)&0x7FFF); 
	}

void relax ()
	{
	for (i=1; i<=n; i++)
		col[i] = (bool)(fastrand()%2);

	for (d=0; d<=k; d++)
		for (i=1; i<=n; i++)
			dis[d][i] = inf;

	dis[0][1] = 0;
	
	for (d=0; d<k; d++)
		for (i=1; i<=n; i++)
			for (j=1; j<=n; j++)
				if (col[i] != col[j])
					dis[d+1][j] = min(dis[d+1][j], dis[d][i] + e[i][j]);
	
	out = min(out, dis[k][1]);
	}

int main ()
	{
	scanf ("%d%d", &n, &k);

	for (i=1; i<=n; i++)
		for (j=1; j<=n; j++)
			scanf ("%d", &e[i][j]);
	
	out = inf;
	
	T = 10000;
	while (T--)
		relax();
	
	printf ("%d\n", out);
	return 0;
	}