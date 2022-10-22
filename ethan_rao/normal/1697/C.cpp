#include "bits/stdc++.h"
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
const int N = 1e6 + 10;
vector<int> f(const string &s)
{
	int n = s.size(), i, j = 0;
	vector<int> r;
	for (i = 0; i < n; i++)
	{
		j += s[i] == 'a';
		if (s[i] == 'b')
			r.push_back(j);
	}
	return r;
}
vector<int> g(const string &s)
{
	int n = s.size(), i, j = 0;
	vector<int> r;
	for (i = 0; i < n; i++)
	{
		j += s[i] == 'b';
		if (s[i] == 'c')
			r.push_back(j);
	}
	return r;
}
vector<int> h(const string &s)
{
	int n = s.size(), i, j = 0;
	vector<int> r;
	for (i = 0; i < n; i++)
	{
		j += s[i] == 'a';
		if (s[i] == 'c')
			r.push_back(j);
	}
	return r;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int testcase;
	for (cin >> testcase; testcase--;)
	{
		string s, t;
		int n, m, i, j;
		cin >> n >> s >> t;
		auto a = f(s), b = f(t), c = g(s), d = g(t);
		if (a.size() != b.size() || c.size() != d.size())
			goto no;
		n = a.size(), m = c.size();
		/*for (i = 0; i < n; i++)
			cout << a[i] << " \n"[i + 1 == n];
		for (i = 0; i < n; i++)
			cout << b[i] << " \n"[i + 1 == n];
		for (i = 0; i < m; i++)
			cout << c[i] << " \n"[i + 1 == m];
		for (i = 0; i < m; i++)
			cout << d[i] << " \n"[i + 1 == m];*/
		for (i = 0; i < n; i++)
			if (a[i] < b[i])
				break;
		for (j = 0; j < m; j++)
			if (c[j] < d[j])
				break;
		if (i == n && j == m && h(s) == h(t))
			cout << "YES\n";
		else
			goto no;
		continue;
	no:
		cout << "NO\n";
	}
}