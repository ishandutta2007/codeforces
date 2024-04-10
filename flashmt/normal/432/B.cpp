#include <bits/stdc++.h>
using namespace std;

int n, home, away[100100], cntHome[100100];

int main()
{
	ios::sync_with_stdio(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> home >> away[i];
		cntHome[home]++;
	}
	
	for (int i = 0; i < n; i++)
		cout << n - 1 + cntHome[away[i]] << ' ' << n - 1 - cntHome[away[i]] << '\n';
}