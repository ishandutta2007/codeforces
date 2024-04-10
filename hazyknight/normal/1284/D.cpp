#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 400005;

struct Seg
{
	int l,r;
	ll ans;
}a[MAXN],b[MAXN];

int n,tot;
int val[MAXN];

ll Xor[MAXN];
ll mask[MAXN];

map<int,int> match;

ll Rand()
{
	ll res = 0;
	for (int i = 0;i < 4;i++)
		res = res << 15 | rand();
	return res;
}

int main()
{
	srand(time(0));
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		mask[i] = Rand();
	for (int i = 1;i <= n;i++)
	{
		scanf("%d%d%d%d",&a[i].l,&a[i].r,&b[i].l,&b[i].r);
		val[++tot] = a[i].l;
		val[++tot] = a[i].r;
		val[++tot] = b[i].l;
		val[++tot] = b[i].r;
	}
	sort(val + 1,val + tot + 1);
	tot = unique(val + 1,val + tot + 1) - val - 1;
	for (int i = 1;i <= tot;i++)
		match[val[i]] = i;
	for (int i = 1;i <= n;i++)
	{
		a[i].l = match[a[i].l];
		a[i].r = match[a[i].r];
	}
	for (int i = 1;i <= n;i++)
	{
		b[i].l = match[b[i].l];
		b[i].r = match[b[i].r];
	}
	memset(Xor,0,sizeof(Xor));
	for (int i = 1;i <= n;i++)
		Xor[a[i].l] ^= mask[i];
	for (int i = tot;i >= 1;i--)
		Xor[i] ^= Xor[i + 1];
	for (int i = 1;i <= n;i++)
		a[i].ans ^= Xor[a[i].r + 1];
		
	memset(Xor,0,sizeof(Xor));
	for (int i = 1;i <= n;i++)
		Xor[b[i].l] ^= mask[i];
	for (int i = tot;i >= 1;i--)
		Xor[i] ^= Xor[i + 1];
	for (int i = 1;i <= n;i++)
		b[i].ans ^= Xor[b[i].r + 1];
		
	memset(Xor,0,sizeof(Xor));
	for (int i = 1;i <= n;i++)
		Xor[a[i].r] ^= mask[i];
	for (int i = 1;i <= tot;i++)
		Xor[i] ^= Xor[i - 1];
	for (int i = 1;i <= n;i++)
		a[i].ans ^= Xor[a[i].l - 1];
	
	memset(Xor,0,sizeof(Xor));
	for (int i = 1;i <= n;i++)
		Xor[b[i].r] ^= mask[i];
	for (int i = 1;i <= tot;i++)
		Xor[i] ^= Xor[i - 1];
	for (int i = 1;i <= n;i++)
		b[i].ans ^= Xor[b[i].l - 1];
	
	for (int i = 1;i <= n;i++)
		if (a[i].ans != b[i].ans)
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}