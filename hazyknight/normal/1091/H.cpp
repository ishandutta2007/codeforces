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

int n,f,tot,ans,N = 200000;
int p[MAXN];
int dis[MAXN];
int SG[MAXN];

bool vis[MAXN];

bitset<MAXN> mask[105];

int main()
{
	scanf("%d%d",&n,&f);
	bitset<MAXN> t;
	for (int i = 2;i <= N;i++)
	{
		if (!vis[i])
		{
			p[++tot] = i;
			dis[i] = 1;
		}
		if (dis[i] <= 2 && i != f)
			t[i] = 1;
		for (int j = 1;i * p[j] <= N;j++)
		{
			vis[i * p[j]] = 1;
			dis[i * p[j]] = dis[i] + 1;
			if (i % p[j] == 0)
				break;
		}
	}
	for (int i = 0;i <= N;i++)
	{
		for (int j = 0;j <= 101;j++)
			if (!mask[j][i])
			{
				SG[i] = j;
				break;
			}
		mask[SG[i]] |= t << i;
	}
	for (int b,w,r,i = 1;i <= n;i++)
	{
		scanf("%d%d%d",&b,&w,&r);
		ans ^= SG[w - b - 1];
		ans ^= SG[r - w - 1];
	}
	puts(ans ? "Alice\nBob" : "Bob\nAlice");
	return 0;
}