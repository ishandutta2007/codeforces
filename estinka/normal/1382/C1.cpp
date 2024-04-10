// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
typedef long long ll;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		vector<int> v;
		for (int i=0;i<n;i++)
		{
			if (a[i] != b[i])
			{
				v.push_back(i + 1);
				v.push_back(1);
				v.push_back(i + 1);
			}
		}
		cout << v.size() << " ";
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}