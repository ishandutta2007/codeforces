#include <iostream>
#include <cstring>
#include <cstdio>
#define maxn 1505
using namespace std;
char inp[maxn];
int ans[26][maxn];
int st[maxn], sts = 0, ed[maxn];
int nd[maxn], sum[maxn];
int npl = 0;
int main()
{
	int n;
	scanf("%d", &n);
	scanf("%s", inp);
	for(int i = 0; i < 26; i++)
	{
		sts = 0;
		for(int j = 0; j < n; j++)
			if(inp[j] == char(i + 'a'))
			{
				st[sts] = j;
				while(inp[j] == char(i + 'a') && j < n)
					j++;
				j--;
				ed[sts] = j;
				sts++;
			}

		for(int j = 0; j < sts; j++)
		{
			if(j)
				sum[j] = sum[j - 1] + ed[j] - st[j] + 1, 
				nd[j] = nd[j - 1] + st[j] - ed[j - 1] - 1;	
			else sum[j] = ed[j] - st[j] + 1, nd[j] = 0;
		}
		for(int j = 0; j < sts; j++)
			for(int k = j; k < sts; k++)
				if(j)
					ans[i][nd[k] - nd[j]] = max(ans[i][nd[k] - nd[j]], sum[k] - sum[j - 1]);
				else
					ans[i][nd[k] - nd[j]] = max(ans[i][nd[k] - nd[j]], sum[k]);
		for(int j = 1; j < maxn; j++)
			ans[i][j] = max(ans[i][j], ans[i][j - 1]);
	}
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++)
	{
		int t;
		char m;
		scanf("%d", &t);
		getchar();
		scanf("%c", &m);
		printf("%d\n", min(ans[m - 'a'][t] + t, n));
	}
	return 0;
 }