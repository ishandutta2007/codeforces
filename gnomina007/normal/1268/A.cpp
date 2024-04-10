#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
//#include <bits/stdc++.h>


using namespace std;


using ll = long long;
void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	vector<int> s;
	int k, n;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		char x;
		cin >> x;
		s.push_back(x - '0');
	}
	vector<int>ff(k);
	for (int i = 0; i < k; i++)
	{
		ff[i] = s[i];
	}
	int val = 0, cur = 0, pos = 0;
	while (cur == 0)
	{
		//	cout << cur << endl;
		if (pos == n)
		{
			//	cout << "Here" << endl;
			cur = 1;
			val = 1;
			break;
		}
		if (s[pos] < ff[pos%k])
		{
			//	cout << "sads" << endl;
			cur = 1;
			val = 1;
		}
		if (s[pos] > ff[pos%k])
		{
			//cout << "dsdsd" << endl;
			cur = 1;
			val = 2;
		}
		if (s[pos] == ff[pos%k])
		{
			pos++;
		}
	}
	//cout << val << endl;
	if (val == 2)
	{
		int pos = k - 1;
		while (ff[pos] == 9)
		{
			pos--;
		}
		ff[pos]++;
		pos++;
		while (pos < k)
		{
			ff[pos] = 0;
			pos++;
		}
	}
	cout << n << endl;
	for (int i = 0; i < n; i++)
	{
		cout << ff[i%k];
	}
	cout << endl;
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