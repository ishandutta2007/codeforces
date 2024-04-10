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

int n,k;
int a[MAXN];
int b[MAXN];

int pre(int p)
{
	return p == 1 ? n : p - 1;
}

int nxt(int p)
{
	return p == n ? 1 : p + 1;
}

int ct;

int ask(int p)
{
	cout << "? " << p << ' ' <<endl;
	cout.flush();
	int v;
	cin >> v;
	return v;
}

int dis(int u,int v)
{
	return min(u - v,n + v - u);
}

void stage2(int u,int c)
{
	if (c < k)
	{
		for (int j = u;;j = nxt(j))
		{
			int tt = ask(j);
			if (tt > c)
			{
				cout << "! " << nxt(u) << endl;
				exit(0);
			}
			else
			{
				u = j;
				c = tt;
			}
		}
	}
	else
	{
		for (int j = u;;j = pre(j))
		{
			int tt = ask(j);
			if (tt < c)
			{
				cout << "! " << j << endl;
				exit(0);
			}
			else
			{
				u = j;
				c = tt;
			}
		}
	}
}

int main()
{
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
		a[i] = k;
	vector<int> v;
	for (int i = 1;i <= n;i++)
		v.push_back(i);
	for (int i = 0;;)
	{
		int p = v[min((int)v.size() - 1,i)];
		int c = ask(p);
		i++;
		if (c != k)
			stage2(p,c);
		c = ask(nxt(p));
		i++;
		if (c != k)
			stage2(nxt(p),c);
		vector<int> tmp;
		for (int j = 0;j < v.size();j++)
			if (dis(v[j],p) >= i - 2)
				tmp.push_back(v[j]);
		swap(tmp,v);
	}
	return 0;
}