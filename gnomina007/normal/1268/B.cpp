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
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int sum = 0;
	ll val=0;
	for (int i = 0; i < n; i++)
	{
		val += a[i];
		int add = a[i] % 2;
		if (i % 2 == 0)
		{
			sum -= add;
		}
		else
		{
			sum += add;
		}
	}
	//cout << sum << endl;
	sum = abs(sum);
	cout << (val - sum) / 2 << endl;
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