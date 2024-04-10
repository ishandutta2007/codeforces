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

const int MAXN = 150005;

int n;
int pxa[MAXN];
int pya[MAXN];
int pxb[MAXN];
int pyb[MAXN];
int sxa[MAXN];
int sya[MAXN];
int sxb[MAXN];
int syb[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d%d%d%d",&pxa[i],&pya[i],&pxb[i],&pyb[i]);
	pxa[0] = sxa[n + 1] = -1e9;
	pya[0] = sya[n + 1] = -1e9;
	pxb[0] = sxb[n + 1] = 1e9;
	pyb[0] = syb[n + 1] = 1e9;
	for (int i = n;i >= 1;i--)
	{
		sxa[i] = max(pxa[i],sxa[i + 1]);
		sya[i] = max(pya[i],sya[i + 1]);
		sxb[i] = min(pxb[i],sxb[i + 1]);
		syb[i] = min(pyb[i],syb[i + 1]);
	}
	for (int i = 1;i <= n;i++)
	{
		pxa[i] = max(pxa[i],pxa[i - 1]);
		pya[i] = max(pya[i],pya[i - 1]);
		pxb[i] = min(pxb[i],pxb[i - 1]);
		pyb[i] = min(pyb[i],pyb[i - 1]);
	}
	for (int i = 1;i <= n;i++)
	{
		int Xa = max(pxa[i - 1],sxa[i + 1]);
		int Ya = max(pya[i - 1],sya[i + 1]);
		int Xb = min(pxb[i - 1],sxb[i + 1]);
		int Yb = min(pyb[i - 1],syb[i + 1]);
		if (Xa <= Xb && Ya <= Yb)
		{
			printf("%d %d\n",Xa,Ya);
			return 0;
		}
	}
	return 0;
}