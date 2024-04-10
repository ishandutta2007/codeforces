#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
#define all(v) v.begin(),v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() )
#define bout(x) cout << bitset<sizeof(x)*8>(x) << endl
#define mkp(a,b) make_pair(a,b)
#define gcd(a,b) __gcd(a,b)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using cpl = complex<ld>;
const ld pi = 3.14159265358979323846264338327950288;
const ld tau = 2 * pi;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

// #define DEBUG

vector<int> ans;

void psh(int a, int b, int x, int y){
	int n = x+y;
	int aa = min(a, x), bb = min(b, y);
	int d = abs(a-x);
	while (0 <= aa && 0 <= bb){
		ans.push_back(d); ans.push_back(n-d);
		aa -= 1; bb -= 1; d += 2;
	}
}

void Main(){
	int t; cin >> t;
	while (t--){
		int x, y; cin >> x >> y;
		int n = x+y; int a = n/2; int b = n-a;
		psh(a, b, x, y); psh(a, b, y, x);
		psh(b, a, x, y); psh(b, a, y, x);
		unq(ans); cout << ans.size() << endl;
		for (int x : ans){ cout << x << ' '; } cout << endl;
		ans.clear();
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