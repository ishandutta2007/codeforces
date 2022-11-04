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

const int MAXN = 100005;

int T,n;
int v[MAXN];

char a[MAXN];
char b[MAXN];

vector<int> ans;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%s%s",&n,a + 1,b + 1);
		ans.clear();
		int l = 1,r = n;
		bool rev = 0;
		for (int i = 1;i <= n;i++)
		{
			int st = (a[l] - '0') ^ rev,ed = (a[r] - '0') ^ rev;
			if (ed != b[n - i + 1] - '0')
			{
				if (st != ed)
				{
					a[l] = ((a[l] - '0') ^ 1) + '0';
					ans.push_back(1);
				}
				rev ^= 1;
				swap(l,r);
				ans.push_back(max(l,r) - min(l,r) + 1);
			}
			if (l > r)
				r++;
			else
				r--;
		}
		printf("%d ",(int)ans.size());
		for (int i = 0;i < ans.size();i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}