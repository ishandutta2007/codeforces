#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define maxn 200005
using namespace std;
int pl[maxn], to[2][maxn], a[maxn];
int cnt[maxn], ns[maxn];
int ans[maxn];
const int dvs = 1600;
struct th
{
	int l, r, t;
	bool operator < (const th&a)const
	{
		if(l / dvs != a.l / dvs) return l < a.l;
		if(r / dvs != a.r / dvs) 
			 return r < a.r;
		return t < a.t;
	}
}p[maxn];
map <int, int> id;
int nt, nl, nr;
void ins(int a, int tp)
{
	ns[cnt[a]]--, 
	cnt[a] += tp, 
	ns[cnt[a]]++;
}
void act(int t, int tp)
{
	if(!pl[t]) return;
	a[pl[t]] = to[tp][t];
	if(pl[t] >= nl && pl[t] <= nr)
		ins(to[!tp][t], -1), 
		ins(to[tp][t], 1);
}
void read(int &a)
{
	char ch = getchar();
	while(ch > '9' || ch < '0')
		ch = getchar();
	a = 0;
	while(ch <= '9' && ch >= '0')
		a = a * 10 + ch - '0', ch = getchar();
}
char ots[5];
void otp(int a)
{
	for(int i = 0; i < 5; i++)
		ots[i] = a % 10 + '0', a /= 10;
	bool flag = 0;
	for(int i = 4; i >= 0; i--)
	{
		if(ots[i] != '0') flag = 1;
		if(flag) putchar(ots[i]);
	}
	putchar('\n');
}
int main()
{
	int n, q;
	read(n), read(q);
//	n = q = 5000;
	int idcnt = 1;
	for(int i = 1; i <= n; i++)
	{
		read(a[i]);
	//	a[i] = rand();
		if(!id[a[i]]) id[a[i]] = idcnt++;
		a[i] = id[a[i]];
	}
	int pcnt = 0;
	for(int i = 1; i <= q; i++)
	{
		int t, l, r;
		read(t), read(l), read(r);
	//	t = rand() % 2 + 1, l = rand() % n + 1, r = rand() % n + 1;
	//	if(l > r) swap(l, r);
		if(t == 1) p[pcnt].l = l, p[pcnt].r = r, p[pcnt++].t = i;
		else
		{
			if(!id[r]) id[r] = idcnt++;
			r = id[r];
			pl[i] = l, 
			to[0][i] = a[l], 
			a[l] = r, 
			to[1][i] = r;
		}
	}
	nt = q, nl = 2, nr = 1;
	sort(p, p + pcnt);
	for(int i = 0; i < pcnt; i++)
	{
		while(nt > p[i].t)
			act(nt, 0), nt--;
		while(nt < p[i].t)
			act(nt + 1, 1), nt++;
		while(nr < p[i].r)
			ins(a[nr + 1], 1), nr++;
		while(nl > p[i].l)
			ins(a[nl - 1], 1), nl--;
		while(nr > p[i].r)
			ins(a[nr], -1), nr--;
		while(nl < p[i].l)
			ins(a[nl], -1), nl++;
		for(int j = 1; j < maxn; j++)
			if(!ns[j])
			{
				ans[p[i].t] = j;
				break;
			}
	}
	for(int i = 1; i <= q; i++)
		if(!ans[i]) continue;
		else otp(ans[i]);
	return 0;
}