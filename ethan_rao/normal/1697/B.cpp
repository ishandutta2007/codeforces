#include "bits/stdc++.h"
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
const int N = 1e6 + 10;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, i;
	cin >> n >> m;
	vector<int> a(n);
	vector<ll> s(n + 1);
	for (int &x : a)
		cin >> x;
	sort(all(a));
	reverse(all(a));
	for (i = 0; i < n; i++)
		s[i + 1] = s[i] + a[i];
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		cout << s[x] - s[x - y] << '\n';
	}
}