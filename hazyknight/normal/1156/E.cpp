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

const int MAXN = 200005;

int n,ans;
int a[MAXN];
int MAX[MAXN];
int pos[MAXN];

void solve(int l,int r)
{
	if (l == r)
		return;
	int mid = l + r >> 1;
	MAX[mid] = a[mid];
	for (int i = mid - 1;i >= l;i--)
		MAX[i] = max(MAX[i + 1],a[i]);
	MAX[mid + 1] = a[mid + 1];
	for (int i = mid + 2;i <= r;i++)
		MAX[i] = max(MAX[i - 1],a[i]);
	for (int i = mid - 1;i >= l;i--)
		ans += (a[i] != MAX[i] && pos[MAX[i] - a[i]] >= mid + 1 && pos[MAX[i] - a[i]] <= r && MAX[pos[MAX[i] - a[i]]] < MAX[i]);
	for (int i = mid + 1;i <= r;i++)
		ans += (a[i] != MAX[i] && pos[MAX[i] - a[i]] <= mid && pos[MAX[i] - a[i]] >= l && MAX[pos[MAX[i] - a[i]]] < MAX[i]);
	solve(l,mid);
	solve(mid + 1,r);
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		pos[a[i]] = i;
	}
	solve(1,n);
	printf("%d\n",ans);
	return 0;
}