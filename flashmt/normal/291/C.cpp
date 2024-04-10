#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#include <string>
#include <vector>
using namespace std;

long long a[100100];
int n, k;

long long conv(string s)
{
	s += '.';
	long long x = 0, res = 0;
	for (int i = 0; i < int(s.size()); i++)
		if (s[i] >= '0' && s[i] <= '9') x = x * 10 + s[i] - '0';
		else res = (res << 8) + x, x = 0;
	return res;
}

int countDif(long long mask)
{
	set <long long> s;
	for (int i = 0; i < n; i++) s.insert(mask & a[i]);
	return s.size();
}

int main()
{
	string s;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		a[i] = conv(s);
	}
	
	long long all = (1LL << 32) - 1, ans = -1;
	
	for (int i = 0; i < 32; i++)
	{
		long long mask = all ^ ((1LL << i) - 1);
		if (countDif(mask) == k) ans = mask;
	}
	
	if (ans < 0) cout << ans << endl;
	else
	{
		vector <long long> r;
		for (int i = 0; i < 4; i++) r.push_back(ans & 255), ans >>= 8;
		for (int i = 3; i >= 0; i--) cout << r[i] << (i ? '.' : '\n');
	}
}