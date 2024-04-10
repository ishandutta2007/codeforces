#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005
using namespace std;
struct th
{
	long long a, b, h;
	bool operator < (const th & x)const
	{
		return b < x.b || ( b == x.b && a < x.a);	
	}	
}hano[maxn];

struct ST
{
	long long l, r;
	long long max;
	ST *ch[2];
}pool[maxn * 10], *root;
long long cnt = 0;
void bdtree(ST *a, long long l, long long r)
{
	a->l = l, a->r = r, a->max = 0;
	if(l == r) return ;
	long long mid = (l + r) / 2;
	a->ch[0] = &pool[cnt++], a->ch[1] = &pool[cnt++];
	bdtree(a->ch[0], l, mid), bdtree(a->ch[1], mid + 1, r);
}
void ins(ST *a, long long l, long long num)
{
	a->max = max(a->max, num);
	if(a->l == a->r) return ;
	long long mid = (a->l + a->r) / 2;
	if(l <= mid) ins(a->ch[0], l, num);
	else ins(a->ch[1], l, num);
}
long long query(ST *a, long long l, long long r)
{
	if(l > r) return 0;
	if(a->l == l && a->r == r) return a->max;
	long long mid = (a->l + a->r) / 2;
	if(r <= mid) return query(a->ch[0], l, r);
	else if(l > mid) return query(a->ch[1], l, r);
	return max(query(a->ch[0], l, mid), query(a->ch[1], mid + 1, r));
}
struct sor
{
	long long kind, num, id; // 0 a 1 b;
	bool operator < (const sor & a)const
	{
		return num < a.num;
	}
}sorted[maxn * 2];
long long n;

int main()
{
	scanf("%I64d", &n);
	for(long long i = 0; i < n; i++)
	{
		sorted[(i << 1)].id = sorted[(i << 1) | 1].id = i;
		sorted[(i << 1)].kind = 0, sorted[(i << 1) | 1].kind = 1;
		scanf("%I64d%I64d%I64d", &sorted[(i << 1)].num, &sorted[(i << 1) | 1].num, &hano[i].h);
	}
	
	sort(sorted, sorted + n * 2);
	for(long long i = 0; i < n * 2; i++)
	{
		if(i)
			if(sorted[i].num != sorted[i - 1].num)
				cnt++;
		if(sorted[i].kind) hano[sorted[i].id].b = cnt;
		else hano[sorted[i].id].a = cnt;
	}
	
	cnt = 0;
	root = &pool[cnt++];
	
	bdtree(root, 0, n * 2);
	sort(hano, hano + n);
	long long ans = 0; // remember to change to long long
	for(long long i = 0; i < n; i++)
	{
		long long nans = hano[i].h;
		nans += query(root, hano[i].a + 1, hano[i].b);
		ans = max(ans, nans);
		ins(root, hano[i].b, nans);
	}
	printf("%I64d\n", ans);
	return 0;
}