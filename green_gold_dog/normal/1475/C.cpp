#include <bits/stdc++.h>
#define ll int64_t
#define elif else if
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, d, x, y;
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++) {
	ll summ = 0, summ2;
	cin >> m >> d >> n;
	vector<pair<ll, ll>> arr(n, {0,0});
	vector<ll> am(m, 0), ad(d, 0);
	for (ll i = 0; i < n; i++) {
	    cin >> x;
	    x--;
	    am[x]++;
	    arr[i].first = x;
	}
	for (ll i = 0; i < n; i++) {
	    cin >> y;
	    y--;
	    ad[y]++;
	    arr[i].second = y;
	}
	for (ll i = 0; i < n; i++) {
	    summ2 = n - ad[arr[i].second] - am[arr[i].first] + 1;
	    summ += summ2;
	}
	cout << summ/2 << endl;
    }
}