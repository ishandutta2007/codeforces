#include <iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
#include<cassert>
#include<queue>
#include<fstream>
#include<iomanip>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve(istream& cin = std::cin, ostream& cout = std::cout)
{
	int t;
	cin >> t;
	for (int test = 0; test < t; test++)
	{
		int n;
		cin >> n;
		vector<int>v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		int good = 1;
		for (int j = 0; j < n - 1; j++)
			if (v[j] > v[j + 1])
				good = 0;
		if (good)
			cout << "NO \n";
		else
			cout << "YES \n";
	}
}


int main()
{	
	solve();
}