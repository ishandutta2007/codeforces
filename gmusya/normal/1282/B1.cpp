#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

ll binsearch(vector <ll> &a, ll x) {  
	ll l = 0;             
	ll r = a.size() - 1;           
	while (l != r) {
		ll m = (l + r) / 2;          
		if (a[m] <= x)
			l = m + 1;               
		else
			r = m;                    
	}
	return l;
}

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, p, k;
		cin >> n >> p >> k;
		vector <ll> a(n), ans(n);
		for (ll i = 0; i < n; i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		for (ll i = 0; i < k; i++)
			ans[i] = a[i];
		for (ll i = k; i < n; i++)
			ans[i] = ans[i - k] + a[i];
		if (ans[0] > p)
			cout << "0" << endl;
		else {
			if (ans[n - 1] <= p)
				cout << n << endl;
			else
				cout << binsearch(ans, p) << endl;
		}
	}
	return 0;
}