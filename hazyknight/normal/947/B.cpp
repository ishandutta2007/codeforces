#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

int n,now;

long long v[100005];
long long t[100005];
long long sum[100005];

struct S
{
	long long V;
	long long day;
	bool operator < (const S &p)const
	{
		return V - (sum[now - 1] - sum[day - 1]) > p.V - (sum[now - 1] - sum[p.day - 1]);
	}
};

priority_queue<S> Q;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> v[i];
	for (int i = 1;i <= n;i++)
		cin >> t[i],sum[i] = sum[i - 1] + t[i];
	for (int i = 1;i <= n;i++)
	{
		long long ans = 0;
		now = i;
		Q.push((S){v[i],i});
		while (!Q.empty() && Q.top().V - (sum[now - 1] - sum[Q.top().day - 1]) <= t[i])
			ans += Q.top().V - (sum[now - 1] - sum[Q.top().day - 1]),Q.pop();
		ans += Q.size() * t[i];
		cout << ans << ' ';
	}
	cout << endl;
	return 0;
}