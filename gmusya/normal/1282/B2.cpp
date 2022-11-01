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
		ans[0] = a[0];
		for (ll i = 1; i < k - 1; i++)
			ans[i] = ans[i - 1] + a[i];
		ans[k - 1] = a[k - 1];
		for (ll i = k; i < n; i++)
			ans[i] = min(ans[i - k], ans[i - 1]) + a[i];
		ll answ = 0;
		for (ll i = 0; i < n; i++)
			if (ans[i] <= p)
				answ = i + 1;
		cout << answ << endl;
	}
	return 0;
}