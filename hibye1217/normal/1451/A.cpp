#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define endl '\n'
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

ll f(ll x){
	for (ll i = 2; i*i <= x; i++){
		if (x % i == 0) return i;
	}
	return x;
}

void Main(){
	int t;
	cin >> t;
	while (t--){
		ll n;
		cin >> n;
		if (n == 1) cout << 0;
		else if (n == 2) cout << 1;
		else if (n == 3) cout << 2;
		else if (n % 2 == 0) cout << 2;
		else cout << 3;
		cout << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(15);
	Main();
}