#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int MAXN = 200005;

int T,n;

bool vis[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 0;i < n;i++)
			vis[i] = 0;
		for (int a,i = 0;i < n;i++)
		{
			scanf("%d",&a);
			vis[((a + i) % n + n) % n] = 1;
		}
		bool ok = 1;
		for (int i = 0;i < n;i++)
			if (!vis[i])
				ok = 0;
		puts(ok ? "YES" : "NO");
	}
    return 0;
}