#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <set>

using namespace std;

int n;

long long T;
long long a[150005];
long long b[150005];

set<long long> S;

bool check(int p)
{
	for (int i = 1;i <= n;i++)
		if (a[i] % p != 0 && b[i] % p != 0)
			return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> a[1] >> b[1];
	T = a[1];
	for (int i = 2;i * i <= T;i++)
		while (T % i == 0)
			T /= i,S.insert(i);
	if (T != 1)
		S.insert(T);
	T = b[1];
	for (int i = 2;i * i <= T;i++)
		while (T % i == 0)
			T /= i,S.insert(i);
	if (T != 1)
		S.insert(T);
	for (int i = 2;i <= n;i++)
		cin >> a[i] >> b[i];
	for (set<long long>::const_iterator i = S.begin();i != S.end();i++)
		if (check(*i))
		{
			cout << (*i) << endl;
			return 0;
		}
	cout << -1 << endl;
	return 0;
}