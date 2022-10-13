#include <bits/stdc++.h>
using namespace std;

int main()
{
	int test;
	
	cin >> test;
	while (test--)
	{
		int n, p, a[25][25] = {0};
		
		cin >> n >> p;
		for (int i = 0; i < n; i++) 
		{
			a[i][(i + 1) % n] = a[(i + 1) % n][i] = 1;
			a[i][(i + 2) % n] = a[(i + 2) % n][i] = 1;
		}
		
		for (int i = 0; i < n && p; i++)
			for (int j = i + 1; j < n && p; j++)
				if (!a[i][j])
				{
					a[i][j] = a[j][i] = 1;
					p--;
				}
				
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (a[i][j])
					cout << i + 1 << ' ' << j + 1 << endl;
	}
}