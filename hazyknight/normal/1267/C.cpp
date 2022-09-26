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

const int MAXN = 2005;

int n,tot,m,odd,odd2,zero;
int d[MAXN];
int u[MAXN * 3];
int v[MAXN * 3];

set<pair<int,int> > S;

bool ok()
{
	if (zero == n)
		return 1;
	return tot / 2 - n + zero + 1 <= (n - zero - 1 - max(odd / 2,odd2)) / 2;
}

void calc(int u,int val)
{
	zero += !d[u] * val;
	tot += d[u] * val;
	odd += (d[u] & 1) * val;
	odd2 += (d[u] == 1) * val;
}

void addE(int a,int b)
{
	calc(a,-1);
	calc(b,-1);
	m++;
	if (a > b)
		swap(a,b);
	u[m] = a;
	v[m] = b;
	d[a]--;
	d[b]--;
	calc(a,1);
	calc(b,1);
}

void popE()
{
	calc(u[m],-1);
	calc(v[m],-1);
	d[u[m]]++;
	d[v[m]]++;
	calc(u[m],1);
	calc(v[m],1);
	m--;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&d[i]);
		S.insert(make_pair(d[i],i));
		calc(i,1);
	}
	if (tot / 2 < n - 1)
	{
		puts("-1");
		return 0;
	}
	if (tot & 1)
	{
		puts("-1");
		return 0;
	}
	if (!ok())
	{
		puts("-1");
		return 0;
	}
	while (S.size())
	{
		pair<int,int> a = *S.begin();
		S.erase(a);
		if (a.first == 1)
		{
			bool flag = 0;
			for (set<pair<int,int> >::iterator it = S.begin();it != S.end();it++)
				if (it->first > 1)
				{
					addE(a.second,it->second);
					if (ok())
					{
						flag = 1;
						pair<int,int> b = *it;
						S.erase(b);
						b.first--;
						S.insert(b);
						break;
					}
					popE();
				}
			if (!flag)
			{
				addE(a.second,S.begin()->second);
				break;
			}
		}
		if (a.first == 2)
		{
			pair<int,int> b = *S.begin();
			S.erase(b);
			addE(a.second,b.second);
			bool flag = 0;
			for (set<pair<int,int> >::iterator it = S.begin();it != S.end();it++)
				if (it->first > 2)
				{
					addE(a.second,it->second);
					addE(b.second,it->second);
					if (ok())
					{
						flag = 1;
						pair<int,int> c = *it;
						S.erase(c);
						c.first -= 2;
						S.insert(c);
						break;
					}
					popE();
					popE();
				}
			if (!flag)
			{
				S.insert(a);
				S.insert(b);
				popE();
				set<pair<int,int> >::iterator it = S.begin(),nxt = S.begin();
				nxt++;
				while (1)
				{
					if (nxt == S.end())
						nxt = S.begin();
					addE(it->second,nxt->second);
					if (nxt == S.begin())
						break;
					it++;
					nxt++;
				}
				break;
			}
		}
	}
	printf("%d\n",m);
	for (int i = 1;i <= m;i++)
		printf("2 %d %d\n",u[i],v[i]);
	return 0;
}