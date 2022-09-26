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

const int MAXN = 100005;

int n;
int p[MAXN];
int b[MAXN];
int c[MAXN];

bool mark[MAXN];

void solve(int l,int r)
{
	if (l == r)
		return;
	int mid = l + r >> 1;
	solve(l,mid);
	solve(mid + 1,r);
	int p1 = l,p2 = mid + 1,p = l;
	for (int i = l;i <= mid;i++)
		if (b[i] > b[mid + 1])
			mark[b[i]] = 1;
	while (p1 <= mid && p2 <= r)
	{
		if (b[p1] > b[p2])
			c[p++] = b[p2++];
		else
			c[p++] = b[p1++];
	}
	while (p1 <= mid)
		c[p++] = b[p1++];
	while (p2 <= r)
		c[p++] = b[p2++];
	for (int i = l;i <= r;i++)
		b[i] = c[i];
}

int main()
{
	scanf("%d",&n);
	for (int a,i = 1;i <= n;i++)
	{
		scanf("%d",&a);
		p[a] = i;
	}
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&b[i]);
		b[i] = p[b[i]];
	}
	solve(1,n);
	int ans = 0;
	for (int i = 1;i <= n;i++)
		ans += mark[i];
	printf("%d\n",ans);
	return 0;
}