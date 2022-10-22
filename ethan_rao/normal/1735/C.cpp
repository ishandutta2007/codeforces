#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int testcase;
	for (cin >> testcase; testcase--;)
	{
		vector<int> f(26), p(26, -1), flg(26);
		auto getf = [&](auto getf, int x) -> int
		{ return f[x] == x ? x : f[x] = getf(getf, f[x]); };
		iota(all(f), 0);
		string s;
		cin >> s >> s;
		int cnt = 26;
		for (auto &c : s)
		{
			c -= 'a';
			if (p[c] == -1)
			{
				for (int i = 0; i < 26; i++)
				{
					if ((!flg[i]) && (((i != c) && (cnt == 1)) || (getf(getf, i) != getf(getf, c))))
					{
						f[getf(getf, i)] = getf(getf, c);
						--cnt;
						p[c] = i;
						flg[i] = 1;
						c = i + 'a';
						break;
					}
				}
			}
			else
			{
				c = p[c] + 'a';
			}
		}
		cout << s << '\n';
	}
}