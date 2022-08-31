#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue> 
#define maxn 300005
using namespace std;
int n, m;
int num[maxn]; // i, j -> i * m + j
int extend[maxn];
int ext[maxn];// from i 
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d", &num[i * m + j]);
	for(int i = n; i >= 1; i--)
		for(int j = 1; j <= m; j++)
		{
			extend[i * m + j] = i;
			if(i != n && num[(i + 1) * m + j] >= num[i * m + j])
				extend[i * m + j] = extend[(i + 1) * m + j];
			ext[i] = max(ext[i], extend[i * m + j]);
		}
	int k;
	scanf("%d", &k);
	for(int i = 0; i < k; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		if(ext[l] >= r) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}