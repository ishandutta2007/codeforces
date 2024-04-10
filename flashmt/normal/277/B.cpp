#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	
	if (m == 3)
	{
		if (n > 4) puts("-1");
		else
		{
			puts("0 0");
			puts("0 3");
			puts("3 0");
			if (n == 4) puts("1 1");
		}
	}
	else
	{
		for (int i = 0; i < m; i++) cout << i << ' ' << 123456 + i * i << endl;
		for (int i = 0; i < n - m; i++) cout << i << ' ' << -123456 - i * i << endl;
	}
}