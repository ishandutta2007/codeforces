#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int n;
int a[100005]; 

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	int s = sqrt(n),id = 1,cnt = 0;
	if ((s + 1) * (s + 1) == n)
		s++;
	for (int i = 1;i <= n / s;i++)
	{
		int need = s;
		if (i <= n % s)
			need++;
		int tmp = id + need - 1;
		id = tmp + 1;
		while (need)
		{
			a[tmp] = ++cnt;
			tmp--;
			need--;
		}
	}
	for (int i = 1;i <= n;i++)
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}