#include "bits/stdc++.h"
using namespace std;
typedef unsigned int ui;
typedef unsigned long long ll;
#define all(x) (x).begin(), (x).end()
const int N = 1e6 + 10;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int testcase;
	for (cin >> testcase; testcase--;)
	{
		int n, m, i, j, k;
		ll r = 1;
		cin >> n;
		string s;
		cin >> s;
		vector<int> a(n), ed(n);
		for (int &x : a)
			cin >> x, --x;
		for (i = 0; i < n; i++)
			if (!ed[i])
			{
				string t;
				for (j = i; !ed[j]; j = a[j])
				{
					t += s[j];
					ed[j] = 1;
				}
				m = t.size();
				for (j = 1; j <= m; j++)
					if (m % j == 0)
					{
						string s = t.substr(0, j);
						for (k = j; k < m; k += j)
							if (s != t.substr(k, j))
								break;
						if (k == m)
							break;
					}
				r = lcm(r, j);
			}
		cout << r << '\n';
	}
}