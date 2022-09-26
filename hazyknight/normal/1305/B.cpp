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

const int MAXN = 1005;

int n,tot;

char s[MAXN];

bool vis[MAXN];

vector<int> a[MAXN];
vector<int> b[MAXN];

int main()
{
	scanf("%s",s + 1);
	n = strlen(s + 1);
	while (1)
	{
		int i = 1,j = n;
		tot++;
		while (i < j)
		{
			while (i <= n && (s[i] == ')' || vis[i]))
				i++;
			while (j >= 1 && (s[j] == '(' || vis[j]))
				j--;
			if (i >= j)
				break;
			vis[i] = vis[j] = 1;
			a[tot].push_back(i);
			b[tot].push_back(j);
			i++,j--;
		}
		if (!a[tot].size())
		{
			tot--;
			break;
		}
	}
	printf("%d\n",tot);
	for (int i = 1;i <= tot;i++)
	{
		printf("%d\n",(int)a[i].size() + (int)b[i].size());
		for (int j = 0;j < a[i].size();j++)
			printf("%d ",a[i][j]);
		for (int j = b[i].size() - 1;j >= 0;j--)
			printf("%d ",b[i][j]);
		printf("\n");
	}
	return 0;
}