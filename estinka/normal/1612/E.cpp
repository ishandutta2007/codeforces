#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <map>
#include <queue>
typedef long long ll;
using namespace std;

vector<int> best;
int up = 0, dw = 1; // hodnota optimalneho riesenia
void solve(int n, int minp, const vector<int> &k, const vector<int> &m)
{
	map<int, int> ma;
	for (int i = 0; i < n; i++)
	{
		ma[m[i]] += min(minp, k[i]);
	}
	vector<pair<int, int>> v;
	for (pair<int, int> i : ma)
	{
		v.push_back({ i.second, i.first });
	}
	sort(v.begin(), v.end(), greater<pair<int, int> >());
	int sum = 0;
	int bestp = 1, bestsum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i].first;
		int p = i + 1;
		if (p < minp) continue;
		// sum / p > bestsum / bestp
		if (sum * 1ll * bestp > bestsum * 1ll * p)
		{
			bestp = p;
			bestsum = sum;
		}
	}
	// bestsum / bestp > up / dw
	if (bestsum * 1ll * dw > up * 1ll * bestp)
	{
		up = bestsum;
		dw = bestp;
		best.clear();
		for (int i = 0; i < bestp; i++) best.push_back(v[i].second);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> m(n), k(n);
	for (int i = 0; i < n; i++)
	{
		cin >> m[i] >> k[i];
	}
	for (int p = 1; p <= 20; p++)
	{
		solve(n, p, k, m);
	}
	cout << best.size() << "\n";
	for (int i : best) cout << i << " ";
	cout << "\n";
	return 0;
}