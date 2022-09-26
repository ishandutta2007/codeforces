#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <queue>

using namespace std;

const int MAXN = 200005;

int n,m,d;
int ans;
int belong[MAXN];

pair<int,int> a[MAXN];

priority_queue<pair<int,int> > Q;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> d;
	for (int i = 1;i <= n;i++)
		cin >> a[i].first,a[i].second = i;
	sort(a + 1,a + n + 1);
	int tail = 1;
	for (int i = 1;i <= n;i++)
	{
		while (tail <= n && a[tail].first - d <= a[i].first)
			tail++;
		ans = max(ans,tail - i);
	}
	for (int i = 1;i <= ans;i++)
	{
		belong[a[i].second] = i;
		Q.push(make_pair(-a[i].first,i));
	}
	for (int i = ans + 1;i <= n;i++)
	{
		pair<int,int> t = Q.top();
		Q.pop();
		belong[a[i].second] = t.second;
		t.first = -a[i].first;
		Q.push(t);
	}
	cout << ans << endl;
	for (int i = 1;i <= n;i++)
		cout << belong[i] << ' ';
	cout << endl;
	return 0;
}