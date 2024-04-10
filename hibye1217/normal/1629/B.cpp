#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

pi2 arr[1020];

void Main(){
	int t; cin >> t;
	while (t--){
		ll l, r, k; cin >> l >> r >> k;
		if (l==r){
			if (l==1){ cout << "NO" << endl; }
			else{ cout << "YES" << endl; }
			continue;
		}
		ll n = r-l + 1;
		ll c1 = r/2 - (l-1)/2, c2 = r/3 - (l-1)/3;
		if (max(c1,c2) >= n-k){ cout << "YES" << endl; }
		else{ cout << "NO" << endl; }
	}
}

//#define DEBUG
int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}