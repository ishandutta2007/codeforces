#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <random>
#include <list>
#include <array>
#include <fstream>
#include <chrono>
typedef long long ll;
typedef long double ld;
using namespace std;

int k;
void finish(vector<int>& f, vector<int>& invf)
{
	vector<int> unused;
	for (int i = 0; i < k; i++) if (invf[i] == -1) unused.push_back(i);
	for (int i = 0; i < k; i++)
	{
		if (f[i] == -1)
		{
			f[i] = unused.back();
			unused.pop_back();
		}
	}
	cout << "YES\n";
	for (int i = 0; i < k; i++) cout << (char)('a' + f[i]);
	cout << "\n";
}
bool rek(string& a, string& b, string& s, vector<int> f, vector<int> invf, int i, bool fa = true, bool fb = true)
{
	if (i == s.size() || !(fa + fb)) // uz mozeme skoncit lubovolone
	{
		finish(f, invf);
		return true;
	}
	if (fa && fb && a[i] == b[i]) // equal
	{
		if ((f[s[i]] > -1 && f[s[i]] != a[i]) || (invf[a[i]] > -1 && invf[a[i]] != s[i])) return false;
		f[s[i]] = a[i];
		invf[a[i]] = s[i];
		return rek(a, b, s, f, invf, i + 1, true, true);
	}
	if (f[s[i]] != -1)
	{
		if ((fa && a[i] > f[s[i]]) || (fb && b[i] < f[s[i]])) return false;
		return rek(a, b, s, f, invf, i + 1, (fa & (a[i] == f[s[i]])), (fb & (b[i] == f[s[i]])));
	}
	if (fa && fb && a[i] != b[i])
	{
		for (int j = a[i] + 1; j < b[i]; j++)
		{
			if (invf[j] == -1)
			{
				f[s[i]] = j;
				invf[j] = s[i];
				return rek(a, b, s, f, invf, i + 1, false, false);
			}
		}
		bool ans = false;
		if (invf[a[i]] == -1)
		{
			f[s[i]] = a[i]; invf[a[i]] = s[i];
			ans |= rek(a, b, s, f, invf, i + 1, true, false);
			f[s[i]] = -1; invf[a[i]] = -1;
		}
		if (!ans && invf[b[i]] == -1)
		{
			f[s[i]] = b[i]; invf[b[i]] = s[i];
			ans |= rek(a, b, s, f, invf, i + 1, false, true);
		}
		return ans;
	}
	if (fa)
	{
		for (int j = k - 1; j >= a[i]; j--)
		{
			if (invf[j] == -1)
			{
				f[s[i]] = j;
				invf[j] = s[i];
				return rek(a, b, s, f, invf, i + 1, j == a[i], false);
			}
		}
	}
	if (fb)
	{
		for (int j = 0; j <= b[i]; j++)
		{
			if (invf[j] == -1)
			{
				f[s[i]] = j;
				invf[j] = s[i];
				return rek(a, b, s, f, invf, i + 1, false, j == b[i]);
			}
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> k;
		string s, a, b;
		cin >> s >> a >> b;
		int n = s.size();
		for (int i = 0; i < n; i++)
		{
			a[i] -= 'a';
			b[i] -= 'a';
			s[i] -= 'a';
		}
		vector<int> f(k, -1), invf(k, -1);
		if (!rek(a, b, s, f, invf, 0)) cout << "NO\n";
	}
	return 0;
}