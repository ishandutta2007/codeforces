#include <iostream>
#include<vector>
#include<fstream>
#include<set>
#include<random>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;

using ll = long long;
using ull = unsigned long long;
const int mod = 998244353;
int maxn = 2000005;
int sum(int a, int b)
{
	int c = a + b;
	if (c >= mod)
		c -= mod;
	return c;
}
int dif(int a, int b)
{
	int c = a - b + mod;
	if (c >= mod)
		c -= mod;
	return c;
}
int mlt(int a, int b)
{
	long long p = a * 1LL * b;
	return p % mod;
}
void outp(vector<int>& v)
{
	cout << "HERE " << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	cout << endl;
}
vector<vector<int>>kids(vector<int>v)
{
	vector<vector<int>>ans;
	for (int i = 0; i < v.size(); i++)
	{
		vector<int>v1 = v;
		v1.push_back(0);
		if (v1[i] > v1[i + 1])
		{
			v1[i]--;
			while (v1.size() != 0 && v1.back() == 0)
				v1.pop_back();
			ans.push_back(v1);
		}
	}
	return ans;
}
int bp(int a, int b)
{
	if (b == 0)
		return 1;
	if (b % 2 == 0)
	{
		int val = bp(a, b / 2);
		return mlt(val, val);
	}
	int val = bp(a, b - 1);
	return mlt(val, a);
}
vector<int>fact(maxn), ofact(maxn), doublefact(maxn);
void prec()
{
	fact[0] = 1;
	for (int i = 1; i < maxn; i++)
		fact[i] = mlt(fact[i - 1], i);
	ofact[maxn - 1] = bp(fact[maxn - 1], mod - 2);
	for (int j = maxn - 2; j >= 0; j--)
		ofact[j] = mlt(ofact[j + 1], j + 1);
	doublefact[0] = 1;
	for (int i = 1; i < maxn; i++)
	{
		doublefact[i] = mlt(doublefact[i - 1], 2 * i + 1);
	}
}
int c(int a, int b)
{
	if (a < 0)
		return 0;
	if (a > b)
		return 0;
	int val = mlt(fact[b], ofact[a]);
	val = mlt(val, ofact[b - a]);
	return val;
}
int main()
{
	int tests;
	cin >> tests;
	for (int test = 0; test < tests; test++)
	{
		int n;
		cin >> n;
		//, .
		vector<vector<int>>want0(n + 1, vector<int>(n + 1)),want1=want0;
		want0[0][0] = 1;
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				if (i + j > 0)
				{
					if (i > 0)
					{
						if (j % 2 == 0 && want1[i - 1][j] == 0)
							want0[i][j] = 1;
						if (j % 2 == 1 && want0[i - 1][j] == 0)
							want0[i][j] = 1;
					}
					if (j > 0)
					{
						if (j % 2 == 0 && want1[i][j-1] == 0)
							want0[i][j] = 1;
						if (j % 2 == 1 && want0[i][j-1] == 0)
							want0[i][j] = 1;
					}
					if (i > 0)
					{
						if (j % 2 == 0 && want0[i - 1][j] == 0)
							want1[i][j] = 1;
						if (j % 2 == 1 && want1[i - 1][j] == 0)
							want1[i][j] = 1;
					}
					if (j > 0)
					{
						if (j % 2 == 0 && want0[i][j - 1] == 0)
							want1[i][j] = 1;
						if (j % 2 == 1 && want1[i][j - 1] == 0)
							want1[i][j] = 1;
					}
				}
			}
		}
		int odd = 0, even = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			if (x % 2 == 0)
				even++;
			else
				odd++;
		}
		if (want0[even][odd])
			cout << "Alice \n";
		else
			cout << "Bob \n";
	}
}