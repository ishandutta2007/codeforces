#include <iostream>
#include <algorithm>

using namespace std;

int n,S,ans,V;
int a[100005];
long long cost[100005];

long long check(int x)
{
	for (int i = 1;i <= n;i++)
		cost[i] = a[i] + 1ll * i * x;
	sort(cost + 1,cost + n + 1);
	long long ret = 0;
	for (int i = 1;i <= x;i++)
		ret += cost[i];
	return ret;
}

void search(int l,int r)
{
	if (l > r)
		return;
	int mid = (l + r) >> 1;
	long long tot = check(mid);
	if (tot <= S)
	{
		ans = mid;
		V = tot;
		search(mid + 1,r);
	}
	else
		search(l,mid - 1);
}

int main ()
{
	ios::sync_with_stdio(false);
	cin >> n >> S;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	search(0,n);
	cout << ans << " " << V << endl;
	return 0;
}