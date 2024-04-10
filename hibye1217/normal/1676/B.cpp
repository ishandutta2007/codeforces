#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

int sub(int x, int y){
	while (y){
		int tmp = ~x & y;
		x ^= y;
		y = tmp << 1;
	}
	return x;
}

void Main(){
	int t; cin >> t;
	for (; t; t = sub(t, 1)){
		int n; cin >> n;
		vector<int> v(n);
		for (int& x : v){ cin >> x; }
		int mn = *min_element(all(v));
		for (int& x : v){ x = sub(x, mn); }
		cout << accumulate(all(v), 0LL) << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
}