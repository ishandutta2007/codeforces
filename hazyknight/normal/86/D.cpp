#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>
 
using namespace std;

typedef long long ll;

const int MAXN = 200005;
const int MAXV = 1000005;
const int SIZE = 500;

struct Query
{
	int l,r,id;
	ll ans;
}q[MAXN];

int n,m;
int a[MAXN];

ll ANS;
ll cnt[MAXV];

bool cmp1(const Query &a,const Query &b)
{
	return a.l / SIZE == b.l / SIZE ? a.r < b.r : a.l < b.l;
}

bool cmp2(const Query &a,const Query &b)
{
	return a.id < b.id;
}

void mdf(int v,int val)
{
	ANS -= cnt[v] * cnt[v] * v;
	cnt[v] += val;
	ANS += cnt[v] * cnt[v] * v;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for (int i = 1;i <= m;i++)
	{
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id = i;
	}
	sort(q + 1,q + m + 1,cmp1);
	int L = 1,R = 0;
	for (int i = 1;i <= m;i++)
	{
		while (L > q[i].l)
			mdf(a[--L],1);
		while (R < q[i].r)
			mdf(a[++R],1);
		while (L < q[i].l)
			mdf(a[L++],-1);
		while (R > q[i].r)
			mdf(a[R--],-1);
		q[i].ans = ANS;
	}
	sort(q + 1,q + m + 1,cmp2);
	for (int i = 1;i <= m;i++)
		printf("%lld\n",q[i].ans);
	return 0;
}