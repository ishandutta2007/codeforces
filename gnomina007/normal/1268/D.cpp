#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
//#include <bits/stdc++.h>


using namespace std;


using ll = long long;
bool ck(vector<int>&degs, vector<int>&vals, int size)
{
	sort(degs.begin(), degs.end());
	reverse(degs.begin(), degs.end());
	int sum = 0;
//	cout << "Ck" << endl;
	for (int i = 0; i<size-1; i++)
	{
		sum += degs[i];
		//cout << i << ' ' << sum << endl;
		if (sum >= vals[i])
		{
			return false;
		}
	}
	return true;
}
bool check(vector<vector<int>>&matr, int size)
{
	vector<int>degs(size), vals(size);
	for (int i = 0; i < size; i++)
	{
		vals[i] = (i + 1)*(size - i - 1) + (i*(i + 1)) / 2;
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (matr[i][j] == 1)
			{
				degs[i]++;
		   }
		}
	}
//	cout << "AAAAAA" << endl;
	for (int i = 0; i < size; i++)
	{
	//	cout << vals[i] << ' ' << degs[i] << endl;
	}
//	cout << endl;
	return ck(degs, vals, size);
}
int ibit(int mask, int i)
{
	return (mask >> i) % 2;
}
pair<int,int> ans(vector<int>&trs, vector<vector<int>>&bs)
{
	for (int i = 0; i < 20; i++)
	{
		int val = 0;
		for (int j = 0; j < trs.size(); j++)
		{
			int jj = trs[j];
			if (bs[jj].size() == i)
			{
				val++;
			}
		}
		if (val > 0)
		{
			return make_pair(i, val);
		}
	}
	return make_pair(-1, -1);
}
int check_one(vector<vector<int>>&matr, int size)
{
	vector<int>degs(size), vals(size);
	for (int i = 0; i < size; i++)
	{
		vals[i] = (i + 1)*(size - i - 1) + (i*(i + 1)) / 2;
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (matr[i][j] == 1)
			{
				degs[i]++;
			}
		}
	}
	int cur = 0;
	for (int i = 0; i < size; i++)
	{
		vector<int>degs1 = degs;
		for (int h = 0; h < size; h++)
		{
			if (h != i)
			{
				if (matr[h][i] == 0)
				{
					degs1[h]++;
					degs1[i]--;
				}
				else
				{
					degs1[h]--;
					degs1[i]++;
				}
			}
		}
		if (ck(degs1, vals, size))
		{
			cur++;
		}
	}
	return cur;
}
ll facts[228];
void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	facts[0] = 1;
	for (int i = 0; i < 100; i++)
	{
		facts[i + 1] = facts[i] * (i + 1);
		facts[i + 1] %= 998244353;
	}
//	cout << "Here" << endl;
	int n;
	cin >> n;
	vector<vector<int>>matr(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char x;
			cin >> x;
			matr[i][j] = x - '0';
		}
	}
	if (n < 15)
	{
		vector<vector<int>>bs(1<<n);
		vector<int>trs;
		for (int mask = 0; mask < (1 << n); mask++)
		{
			for (int j = 0; j < n; j++)
			{
				if (ibit(mask, j) == 1)
				{
					bs[mask].push_back(j);
				}
			}
			vector<vector<int>>m1 = matr;
			for (int i = 0; i < bs[mask].size(); i++)
			{
				int vl = bs[mask][i];
				for (int h = 0; h < n; h++)
				{
					if (h != vl)
					{
						m1[h][vl] ^= 1;
						m1[vl][h] ^= 1;
					}
				}
			}
			//cout << mask << ' ' << check(m1, n) << endl;
			if (check(m1, n))
			{
				trs.push_back(mask);
			}
		}
		pair<int, int>bv = ans(trs, bs);
		if (bv.first == -1)
		{
			cout << -1 << endl;
		}
		else
		{
			ll h = bv.second;
			h *= facts[bv.first];
			h %= 998244353;
			cout << bv.first << ' ' << h << endl;
		}
	}
	else
	{
		if (check(matr, n))
		{
			cout << 0 << ' ' << 1 << endl;
		}
		else
		{
			cout << 1 << ' ' << check_one(matr, n) << endl;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
//	solve();
	//int n; 
	//cin >> n;
	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	solve(fin);

	cout << "clock: " << setprecision(4) << (clock() - st) / (double)CLOCKS_PER_SEC << endl;
#else
	solve();
	int n;
	cin >> n;
#endif

	return 0;
}