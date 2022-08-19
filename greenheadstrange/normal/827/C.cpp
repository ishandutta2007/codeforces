#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define maxn 100025
using namespace std;
int l;
struct bit
{
	int d[maxn];
	int dv, id;
	bit(){memset(d, 0, sizeof(d)), dv = 0;}
	int lb(int x)
	{
		return x & (-x);
	}
	void ch(int pl, int num)
	{
	//	if(dv == 2)
	//		cout<<"CH"<<id<<" "<<dv<<" "<<pl<<" "<<num<<endl;
		int md = pl / dv, nst = pl % dv;
		md++;
		while(md * dv + nst < maxn)
		{
			d[md * dv + nst] += num;
			md += lb(md);
		}
	}	
	int q(int pl)
	{
	
		if(pl < 0) return 0;
		int md = pl / dv, nst = pl % dv;
		md++;
		int ans = 0;
		while(md)
		{
			ans += d[md * dv + nst];
			md -= lb(md);	
		}
	//	if(dv == 2)
	//		cout<<"Q"<<id<<" "<<dv<<" "<<pl<<" "<<ans<<endl;
		return ans;
	}
}p[4][11];
char inp[maxn];
// A : 0 T : 1 G : 2 C : 3
int gt(char a)
{
	if(a == 'A') return 0;
	if(a == 'T') return 1;
	if(a == 'G') return 2;
	return 3;
}
int mxs(int a, int b, int md)
{	// <= a max mod b (mod md)
	b %= md;
	int ns = a % md;
	int ans = a - (ns - b);
	if(ans > a) ans -= md;
//	cout<<"Query"<<a<<" "<<b<<" "<<md<<" "<<ans<<endl;
	return ans;
}
int main()
{
	scanf("%s", inp + 1);
	for(int i = 0; i < 4; i++)
		for(int j = 1; j <= 10; j++)
			p[i][j].dv = j, p[i][j].id = i;
	l = strlen(inp + 1);
	for(int i = 1; i <= l; i++)
	{
		int ns = gt(inp[i]);
		for(int j = 1; j <= 10; j++)
			p[ns][j].ch(i, 1);
	}
	int q;
	scanf("%d", &q);
	for(int i = 1; i <= q; i++)
	{
		int tp;
		scanf("%d", &tp);
		if(tp == 1)
		{
			int x;
			char in[10];
			scanf("%d%s", &x, in);
			int lst = gt(inp[x]), nst = gt(in[0]);
			inp[x] = in[0];
			for(int j = 1; j <= 10; j++)
				p[nst][j].ch(x, 1), p[lst][j].ch(x, -1);
		}
		else
		{
			int l, r;
			scanf("%d%d", &l, &r);
			char e[15];
			scanf("%s", e + 1);
			int nlen = strlen(e + 1);
			int ans = 0;
			for(int j = 1; j <= nlen; j++)
			{
				int mx1 = mxs(l, l - 1 + j, nlen), mx2 = mxs(r, l - 1 + j, nlen);
				if(mx1 == l) mx1 -= nlen;
				int nans = p[gt(e[j])][nlen].q(mx2) - p[gt(e[j])][nlen].q(mx1);
				ans += nans;
			//	cout<<j<<" "<<nans<<endl;
			}
			printf("%d\n", ans);
		}
	}
	return 0;	
} 
/*
ATGCATGC
4
2 2 6 TA
*/