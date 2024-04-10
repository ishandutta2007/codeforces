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

int n,len,h,ans;

multiset<int> S;
vector<int> rollback[MAXN << 2];
vector<int> tag[MAXN << 2];

void modify(int o,int l,int r,int x,int y,int v)
{
	if (l >= x && r <= y)
	{
		tag[o].push_back(v);
		return;
	}
	int mid = l + r >> 1;
	if (mid >= x)
		modify(o << 1,l,mid,x,y,v);
	if (mid + 1 <= y)
		modify(o << 1 | 1,mid + 1,r,x,y,v);
}

void solve(int o,int l,int r)
{
	for (int i = 0;i < tag[o].size();i++)
	{
		multiset<int>::iterator it = S.lower_bound(h - tag[o][i]);
		if (it == S.end())
		{
			for (int j = 0;j < i;j++)
				S.insert(rollback[o][j]);
			return;
		}
		rollback[o].push_back(*it);
		S.erase(it);
	}
	if (l == r)
		ans++;
	else
	{
		int mid = l + r >> 1;
		solve(o << 1,l,mid);
		solve(o << 1 | 1,mid + 1,r);
	}
	for (int i = 0;i < tag[o].size();i++)
		S.insert(rollback[o][i]);
}

int main()
{
	scanf("%d%d%d",&n,&len,&h);
	for (int b,i = 1;i <= len;i++)
	{
		scanf("%d",&b);
		S.insert(b);
	}
	for (int a,i = 1;i <= n;i++)
	{
		scanf("%d",&a);
		modify(1,1,n - len + 1,max(1,i - len + 1),min(i,n - len + 1),a);
	}
	solve(1,1,n - len + 1);
	printf("%d\n",ans);
	return 0;
}