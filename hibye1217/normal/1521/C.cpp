#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
#define all(v) v.begin(),v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() )
#define bout(x) cout << bitset<sizeof(x)*8>(x) << endl
#define bitout(x,y) cout << bitset<y>(x) << endl
#define mkp(a,b) make_pair(a,b)
#define gcd(a,b) __gcd(a,b)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using cpl = complex<ld>;
const ld pi = 3.14159265358979323846264338327950288;
const ld tau = 2 * pi;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

//#define DEBUG

int ans[10020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int one = 0;
		for (int i = 2; i <= n; i += 2){
			int i1 = i-1, i2 = i;
			cout << "? " << 2 << ' ' << i1 << ' ' << i2 << ' ' << 1 << endl << flush;
			int res; cin >> res;
			if (res == 1){ one = i1; break; }
			if (res == 2){
				cout << "? " << 2 << ' ' << i2 << ' ' << i1 << ' ' << 1 << endl << flush;
				int res2; cin >> res;
				if (res == 1){ one = i2; break; }
			}
		}
		if (one == 0){ one = n; }
		ans[one] = 1;
		for (int i = 1; i <= n; i++){
			if (i == one){ continue; }
			cout << "? " << 1 << ' ' << one << ' ' << i << ' ' << n-1 << endl << flush;
			cin >> ans[i];
		}
		cout << "!";
		for (int i = 1; i <= n; i++){
			cout << ' ' << ans[i];
		}
		cout << endl << flush;
	}
}

int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}