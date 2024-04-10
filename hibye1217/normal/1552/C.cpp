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

bool chk[220];
pi2 arr[120];

bool f(int i, int j){
	int ai = arr[i].fr, bi = arr[i].sc;
	int aj = arr[j].fr, bj = arr[j].sc;
	pi2 a[4] = {
		{ ai, 1 },
		{ bi, 1 },
		{ aj, 2 },
		{ bj, 2 }
	};
	sort(a, a+4);
	bool flg = 1;
	for (int i = 1; i < 4; i++){
		if (a[i-1].sc == a[i].sc){ flg = 0; }
	}
	return flg;
}

void Main(){
	int t; cin >> t;
	while (t--){
		int n, k; cin >> n >> k;
		for (int i = 1; i <= k; i++){
			int a, b; cin >> a >> b;
			chk[a] = chk[b] = 1;
			arr[i] = {a, b};
		}
		vector<int> v;
		for (int i = 1; i <= 2*n; i++){
			if (!chk[i]){ v.push_back(i); }
		}
		for (int i1 = 0; i1 < n-k; i1++){
			int i2 = i1 + n-k;
			arr[i1+k+1] = { v[i1], v[i2] };
		}
		int ans = 0;
		for (int i = 1; i <= n; i++){
			for (int j = i+1; j <= n; j++){
				if ( f(i, j) ){
					//cout << "POS " <<endl;
					//cout << arr[i].fr << ' ' << arr[i].sc << endl;
					//cout << arr[j].fr << ' ' << arr[j].sc << endl << endl;
					ans += 1;
				}
			}
		}
		cout << ans << endl;
		memset(chk, 0, sizeof(chk));
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