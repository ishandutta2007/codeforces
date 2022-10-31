#include <iostream>
#include<vector>
#include<fstream>
#include<set>
#include<random>
#include<queue>
#include<algorithm>
using namespace std;

using ll = long long;
using ull = unsigned long long;
void merge(vector<int>& q, vector<int>&invq, int a, int b)
{
	int val = a;
	int t = 0;
	for (int i = 0; i < q.size(); i++)
	{
		val = q[val];
		if (val == b)
		{
			t = 1;
			break;
		}
	}
	int qa = q[a], qb = q[b];
	if (t == 0)
	{
		q[a] = qb;
		q[b]=qa;
	}
	for (int i = 0; i < q.size(); i++)
		invq[q[i]] = i;
}
int main()
{
	int test;
	cin >> test;
	for (int tt = 0; tt < test; tt++)
	{
		int n;
		cin >> n;
		vector<int>p(n), pp(n);
		for (int j = 0; j < n; j++)
		{
			int x;
			cin >> x;
			pp[x - 1] = j;
			p[j] = x - 1;
		}
		vector<int>colors(n, -1);
		int cur = 0;
		for (int i = 0; i < n; i++)
		{
			if (colors[i] == -1)
			{
				colors[i] = cur;
				int pos = i;
				for (int j = 0; j < n; j++)
				{
					colors[pos] = cur;
					pos = p[pos];
				}
				cur++;
			}
		}
		vector<vector<int>>groups(cur);
		for (int i = 0; i < n; i++)
			groups[colors[i]].push_back(i);
		int curmin = 0, curval = n - 1;
		vector<int>curv;
		vector<int>q = pp, invq = p;
		for (int i = 0; i < n - 1; i++)
		{
			merge(q, invq, i, i + 1);
		}

		vector<int>qq(n);
		int vall = 0, pos = 0;
		for (int i = 0; i < n; i++)
		{
			qq[pos] = vall;
			vall = q[vall];
			pos++;
		}
		int val = 0;
		for (int i = 0; i < n; i++)
		{
			val += abs(qq[i] - p[qq[(i + 1) % n]]);
		}
		for (int i = 0; i < n; i++)
			cout << qq[i] + 1 << ' ';
		cout << endl;
	}
}