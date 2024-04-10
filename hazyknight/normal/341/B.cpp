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

const int MAXN = 100005;

int n;
int a[MAXN];
int MX[MAXN];

void modify(int p,int v)
{
	while (p <= n)
	{
		MX[p] = max(MX[p],v);
		p += p & -p;
	}
}

int query(int p)
{
	int res = 0;
	while (p >= 1)
	{
		res = max(res,MX[p]);
		p -= p & -p;
	}
	return res;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for (int i = 1;i <= n;i++)
		modify(a[i],query(a[i] - 1) + 1);
	printf("%d\n",query(n));
	return 0;
}