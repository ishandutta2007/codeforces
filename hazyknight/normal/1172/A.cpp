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

int n;
int a[MAXN];
int b[MAXN];

bool mark[MAXN];

queue<int> Q;

bool ok(int t)
{
	memset(mark,0,sizeof(mark));
	while (!Q.empty())
		Q.pop();
	for (int i = 1;i <= n;i++)
		if (a[i])
			mark[a[i]] = 1;
	for (int i = 1;i <= n;i++)
		Q.push(b[i]);
	while (t > n)
	{
		int top = Q.front();
		if (top)
			mark[top] = 1;
		Q.pop();
		Q.push(0);
		t--;
	}
	int i = 1;
	while (t > 0 && i <= n)
	{
		if (!mark[i])
		{
			i++;
			continue;
		}
		int top = Q.front();
		if (top)
			mark[top] = 1;
		Q.pop();
		Q.push(i);
		i++;
		t--;
	}
	for (int i = 1;i <= n;i++,Q.pop())
		if (Q.front() != i)
			return 0;
	return 1;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for (int i = 1;i <= n;i++)
		scanf("%d",&b[i]);
	int low = 0,high = 2 * n;
	while (low < high)
	{
		int mid = low + high >> 1;
		if (ok(mid))
			high = mid;
		else
			low = mid + 1;
	}
	printf("%d\n",low);
	return 0;
}