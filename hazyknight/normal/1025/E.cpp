#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef vector<pair<pair<int,int>,pair<int,int> > > vp;

int n,m;
int sx[55],sy[55],sid[55];
int tx[55],ty[55],tid[55];

vp ans1,ans2,ans3;

void go(int xa,int ya,int xb,int yb,vp &cur)
{
	if (xa == xb)
	{
		for (int i = ya;i < yb;i++)
			cur.push_back(make_pair(make_pair(xa,i),make_pair(xa,i + 1)));
		for (int i = ya;i > yb;i--)
			cur.push_back(make_pair(make_pair(xa,i),make_pair(xa,i - 1)));
	}
	else
	{
		for (int i = xa;i < xb;i++)
			cur.push_back(make_pair(make_pair(i,ya),make_pair(i + 1,ya)));
		for (int i = xa;i > xb;i--)
			cur.push_back(make_pair(make_pair(i,ya),make_pair(i - 1,ya)));
	}
}

void solve(int *x,int *y,int *id,vp &cur)
{
	for (int i = 1;i <= m;i++)
		for (int j = i + 1;j <= m;j++)
			if (x[i] > x[j])
				swap(x[i],x[j]),swap(y[i],y[j]),swap(id[i],id[j]);
	for (int i = m;i >= 1;i--)
		if (x[i] < i)
			go(x[i],y[i],i,y[i],cur);
	for (int i = 1;i <= m;i++)
		if (x[i] > i)
			go(x[i],y[i],i,y[i],cur);
	for (int i = 1;i <= m;i++)
		go(i,y[i],i,i,cur);
}

void print(vp &cur)
{
	for (int i = 0;i < cur.size();i++)
		cout << cur[i].first.first << ' ' << cur[i].first.second << ' ' << cur[i].second.first << ' ' << cur[i].second.second << endl;

}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1;i <= m;i++)
		cin >> sx[i] >> sy[i],sid[i] = i;
	for (int i = 1;i <= m;i++)
		cin >> tx[i] >> ty[i],tid[i] = i;
	solve(sx,sy,sid,ans1);
	solve(tx,ty,tid,ans3);
	for (int i = 0;i < ans3.size();i++)
		swap(ans3[i].first,ans3[i].second);
	reverse(ans3.begin(),ans3.end());
	for (int i = 1;i <= m;i++)
		for (int j = 1;j <= m;j++)
			if (tid[j] == sid[i])
			{
				sid[i] = j;
				break;
			}
	for (int i = 1;i <= m;i++)
		go(i,i,i,sid[i],ans2);
	for (int i = 1;i <= m;i++)
		go(i,sid[i],sid[i],sid[i],ans2);
	cout << ans1.size() + ans2.size() + ans3.size() << endl;
	print(ans1);
	print(ans2);
	print(ans3);
	return 0;
}