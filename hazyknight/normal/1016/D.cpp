#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

int n,m;
int Xa,Xb;
int a[105];
int b[105];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i],Xa ^= a[i];
	for (int i = 1;i <= m;i++)
		cin >> b[i],Xb ^= b[i];
	if (Xa != Xb)
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for (int i = 1;i <= n - 1;i++)
	{
		for (int j = 1;j < m;j++)
			cout << 0 << ' ';
		cout << a[i] << endl;
	}
	for (int j = 1;j < m;j++)
		cout << b[j] << ' ',a[n] ^= b[j];
	cout << a[n] << endl;
	return 0;
}