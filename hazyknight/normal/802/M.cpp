#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int n,sum,k;
int a[2205];

int main()
{
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= k;i++)
		sum += a[i];
	cout << sum << endl;
	return 0;
}