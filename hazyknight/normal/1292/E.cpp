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

const int MAXN = 55;

int T,n;

//double counter;

char ans[MAXN];

vector<int> ask(string s)
{
//	counter += 1. / (s.size() * s.size());
	cout << "? " << s << endl;
	cout.flush();
	vector<int> res;
	int t = 0;
	cin >> t;
	if (t == -1)
		exit(0);
	res.resize(t);
	for (int i = 0;i < t;i++)
	{
		cin >> res[i];
		for (int j = 0;j < s.size();j++)
			ans[res[i] + j] = s[j];
	}
	return res;
}

bool finish(bool must = 0)
{
	if (!must)
	{
		for (int i = 1;i <= n;i++)
			if (!ans[i])
				return 0;
	}
	cout << "! ";
	for (int i = 1;i <= n;i++)
		cout << (ans[i] ? ans[i] : 'H');
	cout << endl;
	cout.flush();
	int r = 0;
	cin >> r;
	if (!r)
		exit(0);
//	cout << "# Total cost: " << counter << endl;
	return 1;
}

bool exist(vector<int> a,int b)
{
	for (int i = 0;i < a.size();i++)
		if (a[i] == b)
			return 1;
	return 0;
}

void solve()
{
//	counter = 0;
	cin >> n;
	vector<int> CC = ask("CC");
	vector<int> CO = ask("CO");
	vector<int> CH = ask("CH");
	if (!CC.size() && !CO.size() && !CH.size())
	{
		vector<int> OH = ask("OH");
		if (!OH.size())
		{
			bool ok = 0;
			for (int i = 0;i < n - 1;i++)
			{
				string s;
				for (int j = 1;j <= i;j++)
					s += 'H';
				for (int j = 1;j <= n - 1 - i;j++)
					s += 'O';
				if (ask(s).size())
					ok = 1;
			}
			if (finish())
				return;
			if (ok)
			{
				if (ans[n])
				{
					for (int i = 1;i <= n;i++)
						if (!ans[i])
							ans[i] = 'H';
				}
				else
					ans[n] = 'C';
				finish(1);
				return;
			}
			string s;
			for (int i = 1;i <= n;i++)
				s += 'H';
			if (!ask(s).size())
			{
				for (int i = 1;i < n;i++)
					ans[i] = 'H';
				ans[n] = 'C';
			}
			finish(1);
			return;
		}
		vector<int> HO = ask("HO");
		char c = 0;
		for (int i = 1;i < n;i++)
		{
			if (ans[i])
				c = ans[i];
			if (c)
				ans[i] = c;
		}
		c = 0;
		for (int i = n - 1;i >= 1;i--)
		{
			if (ans[i])
				c = ans[i];
			if (c)
				ans[i] = c;
		}
		if (finish())
			return;
		string s;
		for (int i = 1;i < n;i++)
			s += ans[i];
		s += 'C';
		if (!ask(s).size())
			ans[n] = ans[n - 1];
		finish(1);
		return;
	}
	int l,r;
	for (int i = 1;i < n;i++)
		if (ans[i])
		{
			l = i,r = i + 1;
			break;
		}
	while (l > 1)
	{
		if (ans[l - 1])
		{
			l--;
			continue;
		}
		string s;
		s += 'H';
		for (int i = l;i <= r;i++)
			s += ans[i];
		l--;
		if (!exist(ask(s),l))
			ans[l] = 'O';
	}
	while (r < n)
	{
		if (ans[r + 1])
		{
			r++;
			continue;
		}
		string s;
		for (int i = l;i <= r;i++)
			s += ans[i];
		s += 'H';
		r++;
		if (!exist(ask(s),l))
		{
			if (r == n)
			{
				s.back() = 'C';
				if (!exist(ask(s),l))
					ans[r] = 'O';
			}
			else
				ans[r] = 'O';
		}
	}
	finish(1);
}

int main()
{
	cin >> T;
	while (T--)
	{
		memset(ans,0,sizeof(ans));
		solve();
	}
	return 0;
}