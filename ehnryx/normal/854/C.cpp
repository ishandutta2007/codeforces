#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define DEBUG
//#define USE_MAGIC_IO

#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define ldouble long double
#define nl '\n'
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	map<int, set<int>> flights;
	int n, k;
	cin >> n >> k;
	int a[n], b[n], ans[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
		flights[a[i]].insert(i);
	}
	for (int i = n+k-1; i >= k; i--) {
		auto curr = flights.begin();
		//cerr << "curr: " << curr->first;
		if (i < n && a[i] && a[i] != curr->first) {
			//cerr << "forced" << nl;
			ans[i] = i+1;
			//cerr << " " << a[i] << " removed " << nl;
			if (flights[a[i]].size() == 1) 
				flights.erase(a[i]);
			else
				flights[a[i]].erase(*flights[a[i]].rbegin());
		}
		else if (curr->second.size() == 1) {
			//cerr << "remove unique" << nl;
			ans[*curr->second.rbegin()] = i+1;
			a[*curr->second.rbegin()] = 0;
			flights.erase(curr);
		}
		else {
			//cerr << "multiple" << nl;
			ans[*curr->second.rbegin()] = i+1;
			a[*curr->second.rbegin()] = 0;
			curr->second.erase(*curr->second.rbegin());
		}
	}
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += 1LL * (ans[i] - (i+1))*b[i];
	}
	cout << sum << nl;
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << nl;

	return 0;
}