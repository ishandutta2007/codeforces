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

const int MAXN = 100005;

int T,n;
int same[MAXN];
int res[MAXN];
int c[MAXN];
int L[MAXN];

vector<int> p,ans,cl[3];
vector<pair<int,int> > q;

int g[3][3] = 
{
	0,2,1,
	2,0,0,
	1,0,0,
};

string S;

void query()
{
	if (!q.size())
	{
		ans.resize(0);
		return;
	}
	cout << "Q " << q.size() << ' ';
	for (int i = 0;i < q.size();i++)
		cout << q[i].first << ' ' << q[i].second << ' ';
	cout << endl;
	cout.flush();
	string s;
	cin >> s;
	ans.resize(s.size());
	for (int i = 0;i < s.size();i++)
		ans[i] = s[i] - '0';
}

void setv(int l,int r,int v)
{
	for (int i = l;i <= r;i++)
		cl[v].push_back(i);
}

void print()
{
	cout << "A " << cl[0].size() << ' ' << cl[1].size() << ' ' << cl[2].size() << endl;
	for (int i = 0;i < 3;i++,cout << endl)
		for (int j = 0;j < cl[i].size();j++)
			cout << cl[i][j] << ' ';
	cout.flush();
}

void solve()
{
	cin >> n;
	for (int i = 2;i <= n;i += 2)
		q.push_back(make_pair(i - 1,i));
	query();
	q.clear();
	for (int i = 2;i <= n;i += 2)
		same[i] = ans[i / 2 - 1];
	for (int i = 3;i <= n;i += 2)
		q.push_back(make_pair(i - 1,i));
	query();
	q.clear();
	for (int i = 3;i <= n;i += 2)
		same[i] = ans[(i - 1) / 2 - 1];
	L[1] = 1;
	for (int i = 2;i <= n;i++)
		if (same[i])
			L[i] = L[i - 1];
		else
			L[i] = i;
	p.clear();
	for (int i = 1;i <= n;i++)
		if (L[i] == i)
			p.push_back(i);
	for (int op1 = 0;op1 <= 1;op1++)
		for (int op2 = 0;op2 <= 2;op2 += 2)
		{
			for (int i = 2 + op1 + op2;i < p.size();i += 4)
				q.push_back(make_pair(p[i - 2],p[i]));
			query();
			q.clear();
			for (int i = 2 + op1 + op2;i < p.size();i += 4)
				res[i] = ans[(i - 2 - op1 - op2) / 4];
		}
	cl[0].clear();
	cl[1].clear();
	cl[2].clear();
	if (p.size() == 1)
	{
		setv(1,n,0);
		print();
		return;
	}
	setv(1,p[1] - 1,c[0] = 0);
	if (p.size() == 2)
	{
		setv(p[1],n,1);
		print();
		return;
	}
	setv(p[1],p[2] - 1,c[1] = 1);
	for (int i = 2;i < p.size();i++)
	{
		int R = (i == p.size() - 1 ? n : p[i + 1] - 1);
		if (res[i])
			setv(p[i],R,c[i] = c[i - 2]);
		else
			setv(p[i],R,c[i] = g[c[i - 2]][c[i - 1]]);
	}
	print();
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> T;
	while (T--)
		solve();
	return 0;
}