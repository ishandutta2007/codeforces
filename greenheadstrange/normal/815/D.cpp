#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 500005
#define ll long long 
using namespace std;
struct ST
{
    ST *ch[2];
    int l, r, max, lz;
    ll sum;
}pool[maxn << 2], *root;
int cnt = 0;
void bdtree(ST *a, int l, int r)
{
    a->l = l, a->r = r, a->sum = 0, a->max = a->lz = 0;
    if(l == r) return ;
    int mid = (l + r) >> 1;
    a->ch[0] = &pool[cnt++], a->ch[1] = &pool[cnt++];
    bdtree(a->ch[0], l, mid), bdtree(a->ch[1], mid + 1, r);
}
void update(ST *a)
{
    a->max = max(a->ch[0]->max, a->ch[1]->max);
    a->sum = a->ch[0]->sum + a->ch[1]->sum;
}
void actlz(ST *a, int num)
{
    a->max = num, a->sum = (a->r - a->l + 1) * (ll)num, a->lz = num;
}
void pushdown(ST *a)
{
    if(!a->lz) return ;
    actlz(a->ch[0], a->lz), actlz(a->ch[1], a->lz), a->lz = 0; 
}
void alto(ST *a, int l, int r, int lz)
{
    if(a->l == l && a->r == r)
    { 
        actlz(a, lz);
        return ;
    }
    pushdown(a);
    int mid = (a->l + a->r) >> 1;
    if(r <= mid) alto(a->ch[0], l, r, lz);
    else if(l > mid) alto(a->ch[1], l, r, lz);
    else alto(a->ch[0], l, mid, lz), alto(a->ch[1], mid + 1, r, lz);
    update(a);
}
int find(ST *a, int l, int r, int num)
{
    // 
    int mid = (a->l + a->r) >> 1;
    if(a->l == l && a->r == r)
    {
        if(a->l == a->r)
            if(a->max <= num) return a->l;
            else return maxn;
        else
        {
            pushdown(a);
            if(a->ch[1]->max <= num)
                return min(find(a->ch[0], l, mid, num), mid + 1);
            else return find(a->ch[1], mid + 1, r, num);
        }
    }
    pushdown(a);
    if(r <= mid) return find(a->ch[0], l, r, num);
    else if(l > mid) return find(a->ch[1], l, r, num);
    else return min(find(a->ch[0], l, mid, num), find(a->ch[1], mid + 1, r, num));
}
struct th
{
    int a, b, c;
    bool operator < (const th &a)const
    {
        return c < a.c;
    }
}sop[maxn];

int main()
{
    int n, p, q, r;
    scanf("%d%d%d%d", &n, &p, &q, &r);
    for(int i = 0; i < n; i++)
            scanf("%d%d%d", &sop[i].a, &sop[i].b, &sop[i].c);
    sort(sop, sop + n);
    root = &pool[cnt++];
    bdtree(root, 1, p);
    for(int i = 0; i < n; i++)
    {
    	int npl = find(root, 1, sop[i].a, sop[i].b);
    	if(npl == maxn) continue;
    	alto(root, npl, sop[i].a, sop[i].b);
	}
	ll ans = 0;
	ans = p, ans *= q, ans *= r;
	ans -= (r - sop[n - 1].c) * root->sum;
	//int tms = 0;
    for(int i = n - 1; i >= 0; i--)
    {
    	int npl = find(root, 1, p, sop[i].b);
    	if(npl != maxn) alto(root, npl, p, sop[i].b);
    	alto(root, 1, sop[i].a, q);
    	int ltm = 0;
    	if(i) ltm = sop[i - 1].c;
    	if(ltm != sop[i].c) 
			ans -= (sop[i].c - ltm) * (root->sum);
	}
	printf("%I64d\n", ans);
    return 0;
}