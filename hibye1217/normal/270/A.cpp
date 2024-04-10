#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 9
using namespace std;
#define all(v) v.begin(),v.end()
using ll = long long;
#define fr first
#define sc second
using pi2 = pair<int, int>;

const int N = 1000000;
bool chk[370];

void Main(){
	for (ll i = 3; i <= N; i++){
		ll val = 180*i - 360;
		if (val % i != 0){ continue; }
		chk[val/i] = 1;
	}
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		cout << (chk[n] ? "YES" : "NO") << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}