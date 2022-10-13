#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	string a[4];
	for (int i = 0; i < 4; i++) cin >> a[i];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			int cnt = 0;
			for (int ii = i; ii <= i + 1; ii++)
				for (int jj = j; jj <= j + 1; jj++)
					cnt += a[ii][jj] == '.';
			if (cnt != 2) 
			{
				puts("YES");
				return 0;
			}
		}
	puts("NO");
}