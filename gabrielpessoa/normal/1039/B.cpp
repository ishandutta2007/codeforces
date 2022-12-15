#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(ll n, int k, ll l, ll r) {
	//cout << n << ' ' << k << ' ' << l << ' ' << r << endl
	if(r - l + 1 <= 100ll) {
		int x = rand() % (r-l+1);
		cout << l + x << ' ' << l + x << endl;
		string s;
		cin >> s;
		if(s == "Bad") exit(0);
		if(s == "Yes") return;
		else solve(n, k, max(l-k, 1ll), min(r+k, n)); 
	} else {
		ll m = (r+l)/2;
		cout << l << ' ' << m << endl;
		string s;
		cin >> s;
		if(s == "Bad") exit(0);
		if(s == "Yes") solve(n, k, max(l-k, 1ll), min(n, m+k));
		else solve(n, k, max(1ll, m+1-k), min(n, r+k));
	}
}


int main() {
	srand(time(NULL));
	//cout << "oi " << endl;
	ll n; int k;
	cin >> n >> k;
	solve(n, k, 1, n);
}