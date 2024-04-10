#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;

int n;
ll ans[200005];
pair<ll,ll> event[400005];

set<ll> pos;
priority_queue<ll> Q;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> event[i].first >> event[i].second;
		pos.insert(event[i].first);
		pos.insert(event[i].second + 1);
	}
	pos.insert(2e18);
	sort(event + 1,event + n + 1);
	ll last = 0,j = 1;
	for (set<ll>::const_iterator i = pos.begin();i != pos.end();i++)
	{
		ll cur = (*i);
		while (!Q.empty() && -Q.top() <= cur)
		{
			ans[Q.size()] += -Q.top() - last;
			last = -Q.top();
			Q.pop();
		}
		while (j <= n && event[j].first <= cur)
		{
			ans[Q.size()] += event[j].first - last;
			last = event[j].first;
			Q.push(-event[j].second - 1);
			j++;
		}
	}
	for (int i = 1;i <= n;i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}