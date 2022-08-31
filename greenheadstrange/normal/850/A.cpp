#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ld double
#define maxn 1005
using namespace std;
ld eps = 0.0000001;
struct vec
{
	ld tg[5];
	bool operator < (const vec &a)const
	{
		for(int i = 0; i < 5; i++)
			if(abs(tg[i] - a.tg[i]) > eps) return tg[i] < a.tg[i];
		return false;
	}
}p[maxn];
bool judge(vec a, vec b)
{
	ld ans = 0;
	for(int i = 0; i < 5; i++)
		ans += a.tg[i] * b.tg[i];
	if(ans > eps) return 1;
	return 0;
}
int x[5][maxn];
int n;
bool fl[maxn];
int st[maxn];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < 5; j++)
			scanf("%d", &x[j][i]);
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		int ncnt = 0;
		for(int j = 1; j <= n; j++)
			if(i == j) continue;
			else
			{
				for(int k = 0; k < 5; k++) 
					p[ncnt].tg[k] = x[k][j] - x[k][i];
				ncnt++;
			}
		sort(p, p + ncnt);
		int cts = 0;
		for(int j = 0; j < ncnt; j++)
			st[cts++] = j;
		if(cts > 100) fl[i] = 1;
		else 
		{
			for(int j = 0; j < cts; j++)
				for(int k = j + 1; k < cts; k++)
					if(judge(p[j], p[k])) fl[i] = 1;
		}
		if(!fl[i]) cnt++;
	}
	printf("%d\n", cnt);
	for(int i = 1; i <= n; i++)
		if(!fl[i]) printf("%d\n", i);
	return 0;
}