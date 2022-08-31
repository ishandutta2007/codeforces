#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#define maxn 300005
#define maxnod 2000005
#define ll long long
using namespace std;
struct sr
{
	int pl;
	ll num;
	bool operator < (const sr &a)const
	{
		return num < a.num;
	}
}p[maxn];
set <sr> a;

int size[maxnod], l[maxnod], r[maxnod], ch[maxnod][2];
short lz[maxnod]; // lz : 0 to 0 1 to 1 -1 change -2 nothing
int cnt = 0;
void bdtree(int id, int nl, int nr)
{
//	cout<<"BD"<<id<<" "<<nl<<" "<<nr<<" "<<cnt<<endl;
	l[id] = nl, r[id] = nr, size[id] = 0, lz[id] = 0;
	if(nl == nr) return;
	ch[id][0] = cnt++, ch[id][1] = cnt++;
	int mid = (l[id] + r[id]) >> 1;
	bdtree(ch[id][0], nl, mid), bdtree(ch[id][1], mid + 1, nr);
}
void actlazy(int id, int lazy)
{
	//cout<<"BF"<<id<<" "<<lazy<<" "<<lz[id]<<" "<<size[id]<<" "<<r[id] - l[id] + 1<<endl; 
	if(lazy == 1) size[id] = r[id] - l[id] + 1;
	if(lazy == 0) size[id] = 0;
	if(lazy == -1) size[id] = r[id] - l[id] + 1 - size[id];
	
	if(lazy != -1) lz[id] = lazy;
	else if(lz[id] == -1) lz[id] = -2;
	else if(lz[id] == -2) lz[id] = -1;
	else lz[id] = 1 - lz[id];
	//cout<<"AFT"<<id<<" "<<lazy<<" "<<lz[id]<<" "<<size[id]<<" "<<r[id] - l[id] + 1<<endl; 
}
void otp()
{
	for(int i = 1; i < cnt; i++)
		cout<<i<<" "<<l[i]<<" "<<r[i]<<" "<<size[i]<<" "<<lz[i]<<endl;
}
void pushdown(int id)
{
	if(lz[id] == -2) return ;
	actlazy(ch[id][0], lz[id]), actlazy(ch[id][1], lz[id]);
	lz[id] = -2;
}
void update(int id)
{
	size[id] = size[ch[id][0]] + size[ch[id][1]];	
}
void push(int id, int ql, int qr, int num)
{
	if(l[id] == ql && r[id] == qr)
	{
		actlazy(id, num);
		return;
	}
	pushdown(id);
	int mid = (l[id] + r[id]) >> 1;
	if(qr <= mid) push(ch[id][0], ql, qr, num);
	else if(ql > mid) push(ch[id][1], ql, qr, num);
	else push(ch[id][0], ql, mid, num), push(ch[id][1], mid + 1, qr, num);
	update(id);
}
int get(int id)
{	
	pushdown(id);
	int mid = (l[id] + r[id]) >> 1;
	if(l[id] == r[id])
		if(!size[id]) return l[id];
		else return -1;
	int ls = ch[id][0], rs = ch[id][1];
	if(size[ls] == r[ls] - l[ls] + 1) return get(rs);
	else return get(ls);
}

long long tr[maxn];
int t[maxn];
long long ql[maxn], qr[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	cnt = 0;
	for(int i = 1; i <= n; i++)
		scanf("%d%I64d%I64d", &t[i], &ql[i], &qr[i]), 
		p[cnt++].num = ql[i], p[cnt++].num = qr[i], p[cnt++].num = qr[i] + 1;
	p[cnt++].num = 1;
	sort(p, p + cnt);
	int ncnt = cnt;
	cnt = 0;
	for(int i = 0; i < ncnt; i++)
		if(i && p[i].num == p[i - 1].num) continue;
		else cnt++, p[i].pl = cnt, tr[cnt] = p[i].num, a.insert(p[i]);
	ncnt = cnt;
	cnt = 1;
	int root = cnt++;
	bdtree(root, 1, ncnt);
	set <sr>:: iterator it;
	sr new1;
	for(int i = 1; i <= n; i++)
	{
		new1.num = ql[i], it = a.find(new1);
		ql[i] = (*it).pl;
		new1.num = qr[i], it = a.find(new1);
		qr[i] = (*it).pl;
		if(t[i] == 1) push(root, ql[i], qr[i], 1);
		else if(t[i] == 2) push(root, ql[i], qr[i], 0);
		else push(root, ql[i], qr[i], -1);
		printf("%I64d\n", tr[get(root)]);
	}
	return 0;
 }