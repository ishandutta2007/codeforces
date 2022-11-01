#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, char> cache;

void reset()
{
	cache.clear();
}

char query(int a, int b)
{
	if (cache.count({a, b}))
	{
		return cache[{a, b}];
	}
	else
	{
		cout << "? " << a << ' ' << b << endl;
		fflush(stdout);
		string ans;
		cin >> ans;
		return cache[{a, b}] = ans[0];
	}
}

int find(int a, int b, char less)
{
	int cnt = b - a + 1;
	if (cnt == 1)
	{
		return a;
	}
	int lowbit = cnt & (cnt ^ (cnt - 1));
	int mid;
	if (lowbit == cnt)
	{
		mid = cnt / 2;
	}
	else
	{
		mid = cnt - lowbit;
	}
	int x = find(a, a + mid - 1, less);
	int y = find(a + mid, b, less);
	char v = query(x, y);
	if (v == less)
	{
		return x;
	}
	else
	{
		return y;
	}
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
    	reset();
    	int n;
    	cin >> n;
    	int a = find(1, n, '<');
    	int b = find(1, n, '>');
    	cout << "! " << a << ' ' << b << endl;
    	fflush(stdout);
    }
}