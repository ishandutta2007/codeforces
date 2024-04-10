#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
#include<string>
using namespace std;
//p^{-1}q
int calc(int a, int b, vector<vector<int>>&dp)
{
//	cout << a << ' ' << b << endl;
	if (a + b <= 2)
		return 0;
	if (a+b<100)
	{
		return dp[a][b];
	}
	int a1 = a / 2, b1 = (b+1) / 2;
	if (a % 2 == 1)
	{
		a1++;
		b1 = b / 2;
	}
	return calc(a1+b1, a1,dp)+1;
}
pair<int,int> split(int a, int b, vector<vector<pair<int,int>>>& prev)
{
//	cout << a << ' ' << b << endl;
	if (a + b <= 2)
		return { -1,-1 };
	if (a + b < 100)
	{
		return prev[a][b];
	}
	int a1 = a / 2, b1 = (b + 1) / 2;
	if (a % 2 == 1)
	{
		a1++;
		b1 = b / 2;
	}
	return { a1, b1 };
}
int main()
{
	vector<vector<int>>dp(100, vector<int>(100, 10000));
	vector<vector<pair<int, int>>>move(100, vector<pair<int, int>>(100));
	for (int sum = 0; sum < 100; sum++)
	{
		for (int i = 0; i <= sum; i++)
		{
			int j = sum - i;
			if (i + j <= 2)
			{
				dp[i][j] = 0;
				move[i][j] = { -1,-1 };
			}
			else
			{
				for (int i1 = 0; i1 <= i; i1++)
				{
					for (int j1 = 0; j1 <= j; j1++)
					{
						int i2 = i - i1, j2 = j - j1;
						if (i1 + j1 < 100 && i2 + j2 < 100)
						{
							int val = max(dp[i1 + j1][i2], dp[i2 + j2][i1]) + 1;
							dp[i][j] = min(dp[i][j], val);
							if (dp[i][j] == val)
								move[i][j] = { i1, j1 };
						}
					}
				}
			}
			//		cout << i << ' ' << j << ' ' << dp[i][j] << endl;
		}
	}
	//a - posl, b predposl
	vector<int>a, b;
	int n;
	cin >> n;
	cout.flush();
	for (int i = 0; i < n; i++)
		a.push_back(i + 1);
	int q = 0;
	while (a.size() + b.size() > 2)
	{
		q++;
		pair<int, int>spl = split(a.size(), b.size(),move);
		vector<int>a1, b1, a2, b2;
		for (int i = 0; i < spl.first; i++)
			a1.push_back(a[i]);
		for (int i = spl.first; i < a.size(); i++)
			a2.push_back(a[i]);
		for (int i = 0; i < spl.second; i++)
			b1.push_back(b[i]);
		for (int i = spl.second; i < b.size(); i++)
			b2.push_back(b[i]);
		cout << "? " << a1.size() + b1.size() << ' ';
		for (auto aa : a1)
			cout << aa << ' ';
		for (auto bb : b1)
			cout << bb << ' ';
		cout << '\n';
		cout.flush();
		string s="NO";
		cin >> s;
		cout.flush();
		if (s == "YES")
		{
			a.resize(0);
			a.reserve(b1.size() + a1.size());
			for (auto aa : a1)
				a.push_back(aa);
			for (auto aa : b1)
				a.push_back(aa);
			b.resize(0);
			a.reserve(a2.size());
			for (auto aa : a2)
				b.push_back(aa);
		}
		else
		{
			a.resize(0);
			a.reserve(b2.size() + a2.size());
			for (auto aa : a2)
				a.push_back(aa);
			for (auto aa : b2)
				a.push_back(aa);
			b.resize(0);
			a.reserve(a1.size());
			for (auto aa : a1)
				b.push_back(aa);
		}
	}
	assert(q <= 53);
	vector<int>v;
	for (auto aa : a)
		v.push_back(aa);
	for (auto aa : b)
		v.push_back(aa);
	for (auto aa : v)
	{
		cout << "! " << aa<< '\n';
		cout.flush();
		char x, y;
		cin >> x >> y;
		cout.flush();
		if (y == ')')
		{
			exit(0);
		}
	}
}