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

const int MAXN = 505;

int n,tot;
int sz[MAXN];
int p[MAXN];
int t[MAXN];
int fa[MAXN];

bool cmp(const int &a,const int &b)
{
	return sz[a] < sz[b];
}

int ask(vector<int> &a,vector<int> &b,int u)
{
	if (!a.size() || !b.size())
		return 0;
	cout << a.size() << endl;
	for (int i = 0;i < a.size();i++)
		cout << a[i] << ' ';
	cout << endl;
	cout << b.size() << endl;
	for (int i = 0;i < b.size();i++)
		cout << b[i] << ' ';
	cout << endl;
	cout << u << endl;
	cout.flush();
	int ans = 0;
	cin >> ans;
	return ans;
}

void solve(int l,int r,int u)
{
	if (l > r)
		return;
	vector<int> v1,v2;
	v2.push_back(1);
	for (int i = l;i <= r;i++)
		v1.push_back(t[i]);
	if (!ask(v1,v2,u))
		return;
	if (l == r)
	{
		fa[t[l]] = u;
		return;
	}
	int mid = l + r >> 1;
	solve(l,mid,u);
	solve(mid + 1,r,u);
}

int main()
{
	cin >> n;
	sz[1] = n - 1;
	for (int i = 2;i <= n;i++)
	{
		vector<int> v1,v2;
		for (int j = 2;j <= n;j++)
			if (i != j)
				v1.push_back(j);
		v2.push_back(1);
		sz[i] = ask(v1,v2,i);
	}
	for (int i = 1;i <= n;i++)
		p[i] = i;
	sort(p + 1,p + n + 1,cmp);
	for (int i = 1;i < n;i++)
	{
		tot = 0;
		for (int j = 1;j < i;j++)
			if (!fa[p[j]])
				t[++tot] = p[j];
		solve(1,tot,p[i]);
	}
	for (int i = 2;i <= n;i++)
		if (!fa[i])
			fa[i] = 1;
	cout << "ANSWER" << endl;
	for (int i = 2;i <= n;i++)
		cout << fa[i] << ' ' << i << endl;
	cout.flush();
	return 0;
}