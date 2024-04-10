#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <iomanip>
typedef long long ll;
using namespace std;

const int maxn = 5e5 + 5;
vector<int> a(maxn);
set<pair<int, int> > pos;
void apply(int i, int j, int k)
{
	pos.erase({ a[i], i });
	pos.erase({ a[j], j });
	pos.erase({ a[k], k });
	pos.insert({ a[i], j });
	pos.insert({ a[j], k });
	pos.insert({ a[k], i });
	int ai = a[i], aj = a[j], ak = a[k];
	a[i] = ak;
	a[j] = ai;
	a[k] = aj;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		pos.clear();
		int n;
		cin >> n;
		set<int> s;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			s.insert(a[i]);
			pos.insert({ a[i], i });
		}
		if (s.size() < n)
		{
			cout << "YES\n";
			continue;
		}
		for (int i = 0; i < n - 2; i++)
		{
			int mini = pos.begin()->second;
			if (mini > i + 1)
			{
				apply(i, i + 1, mini);
			}
			else if (mini == i + 1)
			{
				apply(i, i + 1, i + 2);
				apply(i, i + 1, i + 2);
			}
			pos.erase(pos.begin());
		}
		bool ok = true;
		for (int i = 1; i < n; i++)
		{
			if (a[i - 1] > a[i])
			{
				ok = false;
				break;
			}
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
	return 0;
}