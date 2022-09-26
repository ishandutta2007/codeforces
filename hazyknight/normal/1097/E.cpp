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
int a[MAXN];
int pre[MAXN];

bool mark[MAXN];

pair<int,int> MAX[MAXN];

vector<vector<int> > ans;

int getlim(int N)
{
	int low = 0,high = 500;
	while (low < high)
	{
		int mid = (low + high) >> 1;
		if (mid * (mid + 1) / 2 >= N)
			high = mid;
		else
			low = mid + 1;
	}
	return low;
}

void modify(int p,pair<int,int> v)
{
	while (p <= n)
	{
		if (v.first > MAX[p].first)
			MAX[p] = v;
		p += (p & -p);
	}
}

pair<int,int> query(int p)
{
	pair<int,int> res;
	while (p >= 1)
	{
		if (MAX[p].first > res.first)
			res = MAX[p];
		p -= (p & -p);
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--)
	{
		ans.clear();
		cin >> n;
		for (int i = 1;i <= n;i++)
			cin >> a[i];
		int N = n;
		while (N)
		{
			int lk = getlim(N);
			for (int i = 1;i <= n;i++)
				MAX[i] = make_pair(0,0);
			for (int i = 1;i <= N;i++)
				mark[i] = false;
			pair<int,int> res,MAXF;
			for (int i = 1;i <= N;i++)
			{
				res = query(a[i]);
				res.first++;
				pre[i] = res.second;
				res.second = i;
				if (res.first > MAXF.first)
					MAXF = res;
				modify(a[i],make_pair(res.first,i));
			}
			if (MAXF.first >= lk)
			{
				int cur = MAXF.second;
				vector<int> seq;
				while (cur)
				{
					mark[cur] = true;
					seq.push_back(a[cur]);
					cur = pre[cur];
				}
				ans.push_back(seq);
			}
			else
			{
				vector<int> seq;
				for (int i = N;i >= 1;i--)
					if (!seq.size() || seq.back() < a[i])
					{
						mark[i] = true;
						seq.push_back(a[i]);
					}
				ans.push_back(seq);
			}
			int tmp = 0;
			for (int i = 1;i <= N;i++)
				if (!mark[i])
					a[++tmp] = a[i];
			N = tmp;
		}
		cout << ans.size() << endl;
		for (int i = 0;i < ans.size();i++)
		{
			cout << ans[i].size() << ' ';
			while (ans[i].size())
			{
				cout << ans[i].back() << ' ';
				ans[i].pop_back();
			}
			cout << endl;
		}
	}
	return 0;
}