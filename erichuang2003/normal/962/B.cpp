#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

int n,a,b;
int sum,cnt;

string s;

char c;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> a >> b >> s;
	for (int i = 1;i <= n;i++)
	{
		c = s[i - 1];
		if (c == '*')
		{
			if (a > b)
			{
				int aa = min(a,(cnt + 1) / 2);
				int bb = min(b,cnt / 2);
				sum += aa + bb;
				a -= aa;
				b -= bb;
			}
			else
			{
				int aa = min(a,cnt / 2);
				int bb = min(b,(cnt + 1) / 2);
				sum += aa + bb;
				a -= aa;
				b -= bb;
			}
			cnt = 0;
		}
		else
			cnt++;
	}
	if (a > b)
	{
		int aa = min(a,(cnt + 1) / 2);
		int bb = min(b,cnt / 2);
		sum += aa + bb;
		a -= aa;
		b -= bb;
	}
	else
	{
		int aa = min(a,cnt / 2);
		int bb = min(b,(cnt + 1) / 2);
		sum += aa + bb;
		a -= aa;
		b -= bb;
	}
	cout << sum << endl;
	return 0;
}