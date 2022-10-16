#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(all(a));
	queue<int> q;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		while (!q.empty() && a[i] - q.front() + 1 > m)
			q.pop();
		if (q.size() < k - 1) q.push(a[i]);
		else ++ans;
	}
	cout << ans << endl;
	return 0;
}