#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005
using namespace std;
struct th
{
	int a, num;
	bool operator < (const th &a)const
	{
		return num < a.num;
	}
}c[maxn], d[maxn];
int cmx, dmx;
int cnt = 0, dcnt = 0;
int main()
{
	int n, cs, ds;
	scanf("%d%d%d", &n, &cs, &ds);
	for(int i = 1; i <= n; i++)
	{
		int b, p;
		char inp[2];
		scanf("%d%d", &b, &p);
		scanf("%s", inp);
		int tp = 0;
		if(inp[0] == 'C') tp = 1;
		else if(inp[0] == 'D') tp = 2;
		else cout<<"WAAA";
		
		if(tp == 1 && p > cs) continue;
		if(tp == 2 && p > ds) continue;
		if(tp == 1)
		{
			cmx = max(cmx, b);
			c[cnt].a = b, c[cnt].num = p, cnt++;
		}
		else
		{
			dmx = max(dmx, b);
			d[dcnt].a = b, d[dcnt].num = p, dcnt++;
		}
	}
	int ans = dmx + cmx;
	if(!dcnt || !cnt) ans = 0;
	sort(c, c + cnt), sort(d, d + dcnt);
	int npl = -1;
	int mp0 = -1, mp1 = -1;
	for(int i = cnt - 1; i >= 0; i--)
	{
		while(npl + 1 < cnt && c[npl + 1].num + c[i].num <= cs)
		{
			npl++;
			if(mp0 == -1 || c[mp0].a < c[npl].a) mp1 = mp0, mp0 = npl;
			else if(mp1 == -1 || c[mp1].a < c[npl].a) mp1 = npl;
		}
		int nmx = 0;
		if(mp0 != i && mp0 != -1) nmx = c[mp0].a;
		else if(mp1 != i && mp1 != -1) nmx = c[mp1].a;
		if(nmx) ans = max(ans, nmx + c[i].a);
	}
	npl = -1, mp0 = mp1 = -1;
	for(int i = dcnt - 1; i >= 0; i--)
	{
		while(npl + 1 < dcnt && d[npl + 1].num + d[i].num <= ds)
		{
			npl++;
			if(mp0 == -1 || d[mp0].a < d[npl].a) mp1 = mp0, mp0 = npl;
			else if(mp1 == -1 || d[mp1].a < d[npl].a) mp1 = npl;
		}
		int nmx = 0;
		if(mp0 != i && mp0 != -1) nmx = d[mp0].a;
		else if(mp1 != i && mp1 != -1) nmx = d[mp1].a;
		if(nmx) ans = max(ans, nmx + d[i].a);
	}
	printf("%d\n", ans);
	return 0;
 } 
 /*4 2 22
 1 2 C
 1 22 D
 2 1 C
 2 1 C*/