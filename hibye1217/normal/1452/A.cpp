#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define endl '\n'
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

void Main(){
	int t;
	cin >> t;
	while (t--){
		ll x, y;
		cin >> x >> y;
		cout << 2*max(x,y) - (x!=y) << endl;
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