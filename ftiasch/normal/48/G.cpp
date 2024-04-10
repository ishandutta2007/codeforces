// Codeforces Beta Round #45
// Problem G -- Galaxy Union
#include <cstdio>
#include <cstring>
#include <iostream>

#define N 200000

#define LL long long

using std::cin;
using std::cout;

int n, m, gu[N], gv[N + N], gn[N + N], dg[N], hd, tl, qu[N], pa[N], ci[N], si[N];
LL gw[N + N], cw[N], dd[N], td[N], wst, ws[N];

inline LL get_w(int i, int j){return ws[j] - ws[i] + (i <= j? 0: wst);}

int main()
{
	cin >> n;
	memset(dg, 0, sizeof(dg));
	memset(gu, -1, sizeof(gu));
	for(int i = 0, a, b, c; i != n; ++ i)
	{
		cin >> a >> b >> c;
		dg[-- a] ++, dg[-- b] ++;
		gv[i + i] = b, 	gv[i + i + 1] = a;
		gw[i + i] = gw[i + i + 1] = c;
		gn[i + i] = gu[a], gu[a] = i + i;
		gn[i + i + 1] = gu[b], gu[b] = i + i + 1;
	}
	
	hd = tl = 0;
	for(int i = 0; i != n; ++ i)
		if(dg[i] == 1)
			qu[tl ++] = i;
	for(; hd != tl; ++ hd)
		for(int i = gu[qu[hd]]; i != -1; i = gn[i])
		{
			if(dg[gv[i]] == 1)
				continue;
			pa[qu[hd]] = i;
			if(-- dg[gv[i]] == 1)
				qu[tl ++] = gv[i];
		}
	m = 1;
	for(ci[0] = 0; dg[ci[0]] != 2; ++ ci[0]);
	for(int i = 0; i != m; ++ i)
	{
		int pv = i? ci[i - 1]: -1;
		for(int j = gu[ci[i]]; j != -1; j = gn[j])
			if(dg[gv[j]] == 2 && gv[j] != pv)
			{
				cw[i] = gw[j];
				if(gv[j] != ci[0])
				{
					ci[m ++] = gv[j];
					break;
				}
			}
	}
	
	for(int i = 0; i != n; ++ i)
		si[i] = 1;
	memset(dd, 0, sizeof(dd));
	for(int i = 0; i != tl; ++ i)
	{
		int u = qu[i], v = gv[pa[u]], w = gw[pa[u]];
		si[v] += si[u];
		dd[v] += dd[u] + si[u] * w;
	}
	
	LL tmp = 0;
	for(int i = 0; i != m; ++ i)
		tmp += dd[ci[i]];
	for(int i = 0; i != m; ++ i)
		td[ci[i]] = tmp;
	
	wst = ws[0] = 0;
	for(int i = 0; i != m; ++ i)
	{
		wst += cw[i];
		if(i)
			ws[i] = ws[i - 1] + cw[i - 1];
	}
	
	int p = 0;
	while(p != m - 1 && get_w(0, p + 1) < get_w(p + 1, 0))
		p ++;
	
	int tmp_s_l = 0, tmp_s_r = 0;
	LL tmp_w_l = 0, tmp_w_r = 0;
	for(int i = 0; i != m; ++ i)
		if(i > p)
			tmp_s_l += si[ci[i]], tmp_w_l += si[ci[i]] * get_w(i, 0);
		else
			tmp_s_r += si[ci[i]], tmp_w_r += si[ci[i]] * get_w(0, i);
	td[ci[0]] += tmp_w_l + tmp_w_r;
	
	for(int i = 1; i != m; ++ i)
	{
		tmp_w_r -= cw[i - 1] * (tmp_s_r -= si[ci[i - 1]]);
		tmp_w_l += cw[i - 1] * (tmp_s_l += si[ci[i - 1]]);
		if(p == i - 1)
		{
			p = i;
			tmp_w_l -= wst * si[ci[i]];
			tmp_s_l -= si[ci[i]];
			tmp_s_r += si[ci[i]];
		}
		while((p + 1) % m != i && get_w(i, (p + 1) % m) < get_w((p + 1) % m, i))
		{
			p = (p + 1) % m;
			tmp_s_r += si[ci[p]], tmp_w_r += si[ci[p]] * get_w(i, p);
			tmp_s_l -= si[ci[p]], tmp_w_l -= si[ci[p]] * get_w(p, i);
		}
		td[ci[i]] += tmp_w_l + tmp_w_r;		
	}
 
	for(int i = tl - 1; i != -1; -- i)
	{
		int u = qu[i], v = gv[pa[u]], w = gw[pa[u]];
		td[u] = td[v] + (n - si[u] * 2) * w;
	}

	for(int i = 0; i != n; ++ i)
		cout << td[i] << " ";
	cout << "\n";
	return 0;
}