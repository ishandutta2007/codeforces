#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 105
#define int long long
using namespace std;
const ll INF = 1e18 + 1e13;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
inline ll readll()
{
	ll x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int x, k, n, q;
long long c[maxn];
struct node
{
	int pos;
	long long val;
}p[maxn];
int st[maxn], num;
struct mat
{
	ll a[105][105];
}temp[40];
int id[(1 << 10)];
long long now[105];
bool cmp(node aaa, node bbb)
{
	return aaa.pos < bbb.pos;
}
mat cheng(mat x, mat y)
{
	mat res;
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= num; j++)
		{
			res.a[i][j] = INF;
			for (register int k = 1; k <= num; k++)
			{
				res.a[i][j] = min(res.a[i][j], x.a[i][k] + y.a[k][j]);
			}
		}
	}
	return res;
} 
void cheng2(ll *f, mat xx)
{
//	printf("\n\n\n");
//		for (int j = 1; j <= num; j++) printf("%lld ", now[j]);
//		printf("\n");
	static ll res[105];
	for (int i = 1; i <= num; i++) res[i] = f[i];
	for (int i = 1; i <= num; i++)
	{
		f[i] = INF;
		for (int j = 1; j <= num; j++)
		{
			if(res[j] + xx.a[j][i] < f[i]) f[i] = res[j] + xx.a[j][i];
		}
	} 
//		for (int j = 1; j <= num; j++) printf("%lld ", now[j]);
//		printf("\n");
//	printf("\n\n\n");
}
signed main()
{
	scanf("%d%d%d%d", &x, &k, &n, &q);
	for (int i = 1; i <= k; i++) scanf("%lld", &c[i]);
	long long ans = 0;
	int tmp = q;
	q = 0;
	for (int i = 1; i <= tmp; i++)
	{
		q++;
		scanf("%d%lld", &p[q].pos, &p[q].val);
		if(p[q].pos <= n - x) continue;
		else
		{
			ans += p[q].val;
			q--;
		}
	}
	p[++q] = (node){n - x + 1, 0};
	sort(p + 1, p + q + 1, cmp);
	for (int i = 0; i < (1 << k); i++)
	{
		int cnt = 0;
		for (int j = 0; j < k; j++) cnt += ((i >> j) & 1);
		if(cnt != x) continue;
		st[++num] = i;
		id[i] = num;
	} 
//	printf("%d\n", num);
//	for (int i = 1; i <= num; i++)
//	{
//		for (int j = 0; j < k; j++) printf("%d ", (st[i] >> j) & 1);
//		printf("\n");
//	}
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= num; j++)
		{
			temp[0].a[i][j] = INF;
		} 
	} 
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if(!(st[i] & 1))
			{
				temp[0].a[i][id[st[i] >> 1]] = 0;
				continue;
			}
			if((st[i] >> j) & 1) continue;
			else temp[0].a[i][id[(st[i] ^ (1 << j)) >> 1]] = c[j];
		} 
	}
//	for (int i = 1; i <= num; i++)
//	{
//		for (int j = 1; j <= num; j++)
//		{
//			printf("%lld ", temp[0].a[i][j]);
//		}
//		printf("\n");
//	} 
	for (int i = 1; i < 31; i++) temp[i] = cheng(temp[i - 1], temp[i - 1]);
	for (int i = 1; i <= num; i++) now[i] = INF;
	now[id[(1 << x) - 1]] = 0;
	p[0].pos = 1;
	for (int i = 1; i <= q; i++)
	{
		int step = p[i].pos - p[i - 1].pos;
//		printf("???????%d %lld\n", p[i].pos, p[i].val); 
		for(int c = 0; c <= 30; c++)
		{
			if((step >> c) & 1) 
			{
//				printf("\n%d\n", c); 
			cheng2(now, temp[c]); 
			} 
			
//		for (int j = 1; j <= num; j++) printf("%lld ", now[j]);
//		printf("\n");
		}
//		printf("^^^^^^^");
//		for (int j = 1; j <= num; j++) printf("%lld ", now[j]);
//		printf("\n");
		for (int j = 1; j <= num; j++)
		{
			if(st[j] & 1) now[j] += p[i].val;
			if(now[j] > INF) now[j] = INF;
		}
//		for (int j = 1; j <= num; j++) printf("%lld ", now[j]);
//		printf("\n");
	}
	printf("%lld", ans + now[id[(1 << x) - 1]]);
	return 0;
}