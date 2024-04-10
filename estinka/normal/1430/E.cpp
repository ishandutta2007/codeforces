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
#include <chrono>
typedef long long ll;
typedef long double ld;
using namespace std;

class fenwick
{
	int N;
	vector<int> a;
public:
	fenwick(int n) :N(n)
	{
		a.resize(n + 1);
	}
	int sum(int r)
	{
		int rv = 0;
		for (; r >= 0; r = ((r & (r + 1)) - 1))
		{
			rv += a[r];
		}
		return rv;
	}
	void add(int i, int d)
	{
		for (; i <= N; i = (i | (i + 1)))
		{
			a[i] += d;
		}
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	string r = s;
	reverse(r.begin(), r.end());
	vector<int> p(n);
	for (int i = 'a'; i <= 'z'; i++)
	{
		vector<int> in1, in2;
		for (int j = 0; j < n; j++)
		{
			if (s[j] == i)
			{
				in1.push_back(j);
			}
			if (r[j] == i)
			{
				in2.push_back(j);
			}
		}
		for (int j = 0; j < in1.size(); j++)
		{
			p[in1[j]] = in2[j];
		}
	}
	fenwick f(n);
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += f.sum(n) - f.sum(p[i]);
		f.add(p[i], 1);
	}
	cout << ans << "\n";
	return 0;
}