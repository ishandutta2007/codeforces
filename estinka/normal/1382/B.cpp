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
		vector<int> a(n);
		int jedna = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		while (jedna < n && a[jedna] == 1)
		{
			jedna++;
		}
		// ak mame 1, prvy tah je jasny.
		// Ak mame niekolko velkych skupin, vyhra prvy hrac (vzdy necha len jeden kamen).
		// Kazdy sa chce dostat k tej poslednej velkej skupine
		if (jedna == n)
		{
			if (jedna & 1)
			{
				cout << "First\n";
			}
			else
			{
				cout << "Second\n";
			}
		}
		else
		{
			if (jedna & 1)
			{
				cout << "Second\n";
			}
			else
			{
				cout << "First\n";
			}
		}
	}
	return 0;
}