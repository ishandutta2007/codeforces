#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <cmath> 

using namespace std;

int a,b,x;
int s[205];

bool flag;

int main()
{
	cin >> a >> b >> x;
	if (a < b)
	{
		swap(a,b);
		flag = true;
	}
	s[1] = 0;
	a--;
	int p = 1;
	while (x)
	{
		p++;
		s[p] = s[p - 1] ^ 1;
		if (s[p])
			b--;
		else
			a--;
		x--;
	}
	while (a)
	{
		cout << (0 ^ flag);
		a--;
	}
	if (s[p] == 0)
	{
		while (b)
		{
			s[p + 1] = s[p];
			s[p] = 1;
			p++;
			b--;
		}
	}
	else
	{
		while (b)
		{
			s[p + 1] = 1;
			p++;
			b--;
		}
	}
	for (int i = 1;i <= p;i++)
		cout << (s[i] ^ flag);
	cout << endl;
	return 0;
}