#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
typedef long long ll;
using namespace std;

const int N = 2e5 + 128;
class events
{
public:
	int time, id; bool query;
};
bool cmp(events a, events b) { return a.time == b.time ? a.query < b.query : a.time < b.time; }
vector<int> a(N), b(N);
int n;
ll c1() // a1 [b2 b1] a2
{
	vector<events> v;
	for (int i = 0; i < n; i++)
	{
		if (a[i] <= b[i]) v.push_back({ a[i], i, false });
		if (b[i] <= a[i]) v.push_back({ b[i], i, true });
	}
	sort(v.begin(), v.end(), cmp);
	ll ans = 0;
	set<int> maxi;
	for (int i = 0; i < v.size(); i++)
	{
		if (!v[i].query) maxi.insert(b[v[i].id]);
		else
		{
			auto it = maxi.upper_bound(a[v[i].id]);
			if (it == maxi.begin()) continue;
			it--;
			ans = max(ans, (ll)*it - b[v[i].id]);
		}
	}
	return ans;
}
ll c2() // b1 [a1 b1] a2
{
	vector<events> v;
	for (int i = 0; i < n; i++)
	{
		if (a[i] <= b[i]) v.push_back({ a[i], i, true });
		if (b[i] <= a[i]) v.push_back({ b[i], i, false });
	} 
	sort(v.begin(), v.end(), cmp);
	int maxi = 0; ll ans = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (!v[i].query) maxi = max(maxi, a[v[i].id]);
		else if (maxi >= b[v[i].id]) 
			ans = max(ans, (ll)(b[v[i].id] - a[v[i].id]));
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	ll ans = 0;
	for (int i = 0; i < n; i++) ans += abs(a[i] - b[i]);
	ll sub = max(c1(), c2());
	swap(a, b);
	sub = max({ sub, c1(), c2() });
	cout << ans - sub * 2 << "\n";
	return 0;
}