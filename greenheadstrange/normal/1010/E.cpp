#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1000005
#define mod 998244353
int t[3];
int n, mm, k;
int l[3][2];
int nr[3][2];
struct th
{
	int m[3], tp; // -1 : -1 0 : + 1 else id
	th(){;}
}ps[maxn], nu[maxn];
bool cmp1(th a, th b)
{
	for(int i = 0; i < 3; i++)
		if(a.m[i] != b.m[i]) return a.m[i] < b.m[i];
	return a.tp < b.tp;
}
bool cmp2(th a, th b)
{
	for(int i = 1; i < 3; i++)
		if(a.m[i] != b.m[i]) return a.m[i] < b.m[i];
	return a.tp < b.tp;
}

int d[maxn];
int lb(int x)
{
	return x & (-x);
}
void upd(int a, int tp)
{
	while(a < maxn) 
		d[a] += tp, a += lb(a);
}
int qq(int a)
{
	int ns = 0;
	while(a)
		ns += d[a], a -= lb(a);
	return ns;
}
int cnt = 0;
int ans[maxn];
void work(int a, int b)
{
	if(a == b) return;
	int mid = (a + b) >> 1;
	work(a, mid), work(mid + 1, b);
	int ncnt = 0;
	for(int j = a; j <= mid; j++)
		if(ps[j].tp <= 0)
			nu[ncnt++] = ps[j];
	for(int j = mid + 1; j <= b; j++)
		if(ps[j].tp >= 1)
			nu[ncnt++] = ps[j];
	if(ncnt) 
	{
		sort(nu, nu + ncnt, cmp2);
		for(int j = 0; j < ncnt; j++)
			if(nu[j].tp >= 1)
				ans[nu[j].tp] += qq(nu[j].m[2]);
			else
				upd(nu[j].m[2], nu[j].tp * 2 + 1);
		for(int j = 0; j < ncnt; j++)
			if(nu[j].tp <= 0)
				upd(nu[j].m[2], -(nu[j].tp * 2 + 1));
	}
}
int main()
{
	for(int i = 0; i < 3; i++)
		cin>>t[i];
	cin>>n>>mm>>k;
	for(int i = 0; i < 3; i++)
		l[i][1] = 1, 
		l[i][0] = t[i];
	for(int i = 1; i <= n; i++)
	{
		int r[3];
		scanf("%d%d%d", &r[0], &r[1], &r[2]);
		for(int j = 0; j < 3; j++)
			l[j][0] = min(l[j][0], r[j]), 
			l[j][1] = max(l[j][1], r[j]);
	}
//	for(int j = 0; j < 3; j++)
//		cout<<l[j][0]<<" "<<l[j][1]<<endl;
	int ch = 1;
	for(int i = 1; i <= mm; i++)
	{
		int r[3];
		int fl = 0;
		scanf("%d%d%d", &r[0], &r[1], &r[2]);
		for(int j = 0; j < 3; j++)
			if(r[j] < l[j][0]) nr[j][0] = 1, nr[j][1] = r[j];
			else if(r[j] > l[j][1]) nr[j][0] = r[j], nr[j][1] = t[j];
			else nr[j][0] = 1, nr[j][1] = t[j], fl++; 
		if(fl == 3) ch = 0;
		for(int s = 0; s < 8; s++)
		{
			int nrr = 0;
			int fls = 0;
			for(int q = 0; q < 3; q++)
			{
				if(s & (1 << q)) 
					nrr ^= 1, 
					ps[cnt].m[q] = nr[q][1] + 1;
				else ps[cnt].m[q] = nr[q][0];
				if(ps[cnt].m[q] > t[q]) fls = 1; 
			}
			if(nrr) ps[cnt].tp = -1;
			else ps[cnt].tp = 0;
			cnt++;
			cnt -= fls;
		}
	}
	if(!ch) cout<<"INCORRECT"<<endl;
	else
	{
		cout<<"CORRECT"<<endl;
		for(int i = 1; i <= k; i++)
		{
			int r[3];
			scanf("%d%d%d", &r[0], &r[1], &r[2]);
			int cr = 0;
			for(int j = 0; j < 3; j++)
				if(r[j] >= l[j][0] && r[j] <= l[j][1])
					cr++;
			if(cr == 3) ans[i] = -1;
			else 
			{
				ps[cnt].m[0] = r[0], ps[cnt].m[1] = r[1], ps[cnt].m[2] = r[2];
				ps[cnt].tp = i;
				cnt++;
			}
		}
		if(cnt)
			sort(ps, ps + cnt, cmp1);
	//	for(int i = 0; i < cnt; i++)
	//		cout<<ps[i].m[0]<<" "<<ps[i].m[1]<<" "<<ps[i].m[2]<<" "<<ps[i].tp<<endl;
		if(cnt) work(0, cnt - 1);
		for(int i = 1; i <= k; i++)
			if(ans[i] < 0) puts("OPEN");
			else if(ans[i] == 0) puts("UNKNOWN");
			else puts("CLOSED");
	}
	return 0;	
}