#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef unsigned long long int ll;

ll gcd(ll a, ll b) {
	if(!b) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector <ll> a(n);
	ll b;
	ll tr_gcd;
	REP(i, n) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	REP(i, n) {
		if(i == 1) tr_gcd = a[i] - a[i - 1];
		else if(i) tr_gcd = gcd(tr_gcd, a[i] - a[i - 1]);
	}
	REP(i, m) {
		cin >> b;
		if(n == 1) cout << a[0] + b << " ";
		else cout << gcd(a[0] + b, tr_gcd) << " ";
	}
	cout << "\n";
	return 0;
}