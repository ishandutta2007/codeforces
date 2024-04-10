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
	int test;
	cin >> test;
	for (int tt = 0; tt < test; tt++)
	{
		int n, k;
		cin >> n;
		vector<int>v(n);
		vector<int>anses(n + 1);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
			anses[n-v[i]] = i + 1;
		}
		anses[n] = n;
		for (int i = 0; i < n; i++)
			cout << anses[i] << ' ';
		cout << endl;
	}
}