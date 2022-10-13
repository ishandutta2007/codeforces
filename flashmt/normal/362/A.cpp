#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a[10];
	int test;
	cin >> test;
	while (test--)
	{
		for (int i = 0; i < 8; i++) cin >> a[i];
		
		vector <int> sx, sy;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (a[i][j] == 'K')
					sx.push_back(i + j), sy.push_back(i - j);
					
		int ans = 0;
		
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (a[i][j] != '#')
				{
					int dx0 = abs(i + j - sx[0]), dy0 = abs(i - j - sy[0]);
					int dx1 = abs(i + j - sx[1]), dy1 = abs(i - j - sy[1]);
					if (dx0 % 4 || dy0 % 4 || dx1 % 4 || dy1 % 4) continue;
					ans |= (dx0 + dy0 + dx1 + dy1) % 8 == 0;
				}
				
		puts(ans ? "YES" : "NO");
	}
}