#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

const int MAXN = 40;

long long b[MAXN];
long long q,l,m;

map<long long,bool> match;

long long abso(long long o)
{
	return (o < 0) ? -o : o;
}

bool ok(long long o)
{
	if (match[o] || abso(o) > l)
		return false;
	return true;
}

int main()
{
	cin >> b[1] >> q >> l >> m;
	for (int i = 1,a;i <= m;i++)
		cin >> a,match[a] = true;
	if (abso(b[1]) > l)
		cout << 0 << endl;
	else if (q == 1)
	{
		if (!ok(b[1]))
			cout << 0 << endl;
		else
			cout << "inf" << endl;
	}
	else if (q == -1)
	{
		if (!ok(b[1]) && !ok(-b[1]))
			cout << 0 << endl;
		else
			cout << "inf" << endl;
	}
	else if (q == 0)
	{
		if (!ok(0))
		{
			if (ok(b[1]))
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else
			cout << "inf" << endl;
	}
	else if (b[1] == 0)
	{
		if (!ok(0))
			cout << 0 << endl;
		else
			cout << "inf" << endl;
	}
	else
	{
		int ans = 0;
		for (int i = 1;;i++)
		{
			if (i != 1)
				b[i] = b[i - 1] * q;
			if (abso(b[i]) > l)
				break;
			if (ok(b[i]))
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
/*
123 0 21 4
543453 -123 6 1424
*/