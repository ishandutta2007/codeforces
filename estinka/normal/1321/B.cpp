// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
typedef long long ll;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	map<int, ll> m;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		m[a-i] += 1ll*a;
	}
	ll cena = 0;
	for (pair<int, ll>i : m)
	{
		cena = max(cena, i.second);
	}
	cout << cena << "\n";
	return 0;
}