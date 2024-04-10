#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

int f1[111], f2[111], f3[111], f4[111];

int main()
{
	f1[0] = 0; f1[1] = 1; f1[2] = 0;
	f2[0] = 1; f2[1] = 2; f2[2] = 3;
	f3[0] = 0; f3[1] = 1; f3[2] = 0;
	f4[0] = 1; f4[1] = 0; f4[2] = 1;
	
	for (int i = 3; i <= 100; i++)
	{
		set <int> s;
		s.insert(f2[i - 2]);
		for (int j = 0; j <= i - 3; j++) s.insert(f2[j] ^ f2[i - 3 - j]);
		while (s.count(f1[i])) f1[i]++;
		
		s.clear();
		s.insert(f2[i - 1]);
		s.insert(f2[i - 2]);
		s.insert(f2[i - 2] ^ 1);
		s.insert(f4[i - 2]);
		for (int j = 0; j <= i - 3; j++) s.insert(f2[j] ^ f4[i - 3 - j]);
		s.insert(f3[i - 2]);
		for (int j = 0; j <= i - 3; j++) s.insert(f2[j] ^ f3[i - 3 - j]);
		while (s.count(f2[i])) f2[i]++;
		
		s.clear();
		s.insert(f3[i - 1]);
		s.insert(f4[i - 2]);
		s.insert(f3[i - 2] ^ 1);
		for (int j = 0; j <= i - 3; j++) s.insert(f4[j] ^ f4[i - 3 - j]);
		for (int j = 0; j <= i - 3; j++) s.insert(f3[j] ^ f3[i - 3 - j]);
		while (s.count(f3[i])) f3[i]++;
		
		s.clear();
		s.insert(f4[i - 1]);
		s.insert(f3[i - 2]);
		s.insert(f4[i - 2] ^ 1);
		for (int j = 0; j <= i - 3; j++) s.insert(f3[j] ^ f4[i - 3 - j]);
		while (s.count(f4[i])) f4[i]++;
	}
	
	int r, n, a[111][3] = {0}, x, y;
	cin >> r >> n;
	while (n--)
	{
		cin >> x >> y;
		a[x][y] = 1;
		for (int i = x - 1; i <= x + 1; i++)
			if (i > 0 && i <= r) a[i][3 - y] = 1;
	}
	
	int sumXor = 0;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= 2; j++)
			if (!a[i][j])
			{
				int maskLeft = 1 << j, cnt = 0;
				if (a[i][3 - j] == 0) maskLeft |= 1 << (3 - j), cnt = 1;
				a[i][j] = a[i][3 - j] = 1;
				
				int maskRight = 0;
				for (int k = i + 1; k <= r; k++)
				{
					if (a[k][1] + a[k][2] == 0) maskRight = 6, cnt++;
					else
						if (a[k][1] + a[k][2] == 2) break;
						else
						{
							if (a[k][1] == 0) maskRight = 2;
							else maskRight = 4;
						}
					a[k][1] = a[k][2] = 1;
				}
				
				if (maskLeft < maskRight) swap(maskLeft, maskRight);		
				if (maskLeft == 6 && maskRight == 6) sumXor ^= f1[cnt];
				if (maskLeft == 6 && maskRight < 6) sumXor ^= f2[cnt];
				if (maskLeft < 6 && maskLeft == maskRight) sumXor ^= f3[cnt];
				if (maskLeft < 6 && maskLeft != maskRight) sumXor ^= f4[cnt];
			}
			
	puts(sumXor ? "WIN" : "LOSE");
}