#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

const int inf = 12345;

int m[26][26];

char gc()
{
	char c = 0;
	while (c <= ' ') cin >> c;
	return c;
}

int main()
{
	ios_base::sync_with_stdio(0);
	string a, b; cin >> a >> b;
	if (a.length() != b.length()) { cout << -1; return 0; }
	int k; cin >> k;
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			m[i][j] = inf;
	for (int i = 0; i < 26; i++) m[i][i] = 0;
	for (int i = 0; i < k; i++)
	{
		int a = gc() - 'a', b = gc() - 'a', c;
		cin >> c;
		m[a][b] = min(m[a][b], c);
		//m[b][a] = min(m[b][a], c);
		//cout << a << " " << b << " " << c << endl;
	}
	for (int k = 0; k < 26; k++)
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < 26; j++)
				if (m[i][k] < inf && m[k][j] < inf)
					m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
	/*
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
			if (m[i][j] == inf) cout << setw(3) << '?'; else cout << setw(3) << m[i][j];
		cout << endl;
	}		
	*/
	int n = a.length();
	string ans;
	int cost = 0;
	for (int i = 0; i < n; i++)
	{
		int q = inf;
		for (char c = 'a'; c <= 'z'; c++)
	        {
	        	int p = m[a[i] - 'a'][c - 'a'] + m[b[i] - 'a'][c - 'a'];
			q = min(q, p);
		}
		if (q == inf) { cost = -1; ans = ""; break; }		
		for (char c = 'a'; c <= 'z'; c++)
		{
			int p = m[a[i] - 'a'][c - 'a'] + m[b[i] - 'a'][c - 'a'];
			if (p != q) continue;
			cost += p;
			ans += c;
			break;
		}
	}
	cout << cost << endl << ans;
}