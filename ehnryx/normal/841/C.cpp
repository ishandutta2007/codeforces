#include <bits/stdc++.h>
using namespace std;

#define debug

#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define ldouble long double
const ll MOD = 1e9+7;
const int INF = 0x7f7f7f7f;
const ll INFLL = 0x7f7f7f7f7f7f7f7f;

#define End return 0; }
#define of ios::sync_with_stdio(0); cin.tie(0);
#define story int main() {
#define The

The story of lame:

	int n, temp;
	cin >> n;
	vector<int> a(n);
	vector<pair<int,int>> b(n);
	vector<int> ans(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		cin >> temp;
		b[i] = pair<int,int>(temp,i);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0; i < n; i++) {
		ans[b[i].second] = a[n-1-i];
	}
	for (int i = 0; i < n; i++) 
		cout << ans[i] << " ";
	cout << endl;

The End