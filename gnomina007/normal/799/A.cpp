#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<cmath>
#include<algorithm>
#include<stdio.h>
using namespace std;
int n, t, k, d, a1, a2, a3, x;
int main()
{
	cin >> n >> t >> k >> d;
	a1 = t*((n + k - 1) / k);
	a3 = a1 - 1;
	a2 = max(a3 - d, 0);
	if ((a3 / t)*k + (a2 / t)*k >= n)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}

}