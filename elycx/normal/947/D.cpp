#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 100005
using namespace std;
char s[maxn], t[maxn];
int cnts[maxn], cntt[maxn];
int cntas[maxn], cntat[maxn];
int n, m, q, l1, l2, r1, r2;
int main()
{
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1);
	m = strlen(t + 1);
	for (int i = 1; i <= n; i++)
	{
		cnts[i] = cnts[i - 1];
		cntas[i] = cntas[i - 1] + 1;
		if(s[i] != 'A') 
		{
			cnts[i]++;
			cntas[i] = 0;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cntt[i] = cntt[i - 1];
		cntat[i] = cntat[i - 1] + 1;
		if(t[i] != 'A') 
		{
			cntt[i]++;
			cntat[i] = 0;
		}
	}
	int ans[maxn], top = 0; 
	scanf("%d", &q);
	while(q--)
	{
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		int cs = cnts[r1] - cnts[l1 - 1], ct = cntt[r2] - cntt[l2 - 1];
		if(cs > ct || (cs & 1) != (ct & 1))
		{
			ans[++top] = 0;
			continue;
		}
		if(cs == ct)
		{
			if(cs == 0)
			{
				if((r1 - l1) >= (r2 - l2) && (r1 - l1) % 3 == (r2 - l2) % 3) ans[++top] = 1;
				else ans[++top] = 0;
				continue;
			} 
			int x = min(r1 - l1 + 1, cntas[r1]), y = min(r2 - l2 + 1, cntat[r2]);
			if(x >= y && (x % 3) == (y % 3)) ans[++top] = 1;
			else ans[++top] = 0;
		}
		else
		{
			if(cs == 0)
			{
				if(r1 - l1 + 1 > cntat[r2]) ans[++top] = 1;
				else ans[++top] = 0;
			}
			else
			{
				if(cntas[r1] >= cntat[r2]) ans[++top] = 1;
				else ans[++top] = 0;
			}
		}
	}
	for (int i = 1; i <= top; i++) printf("%d", ans[i]);
	return 0;
}