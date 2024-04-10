#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
#define all(v) v.begin(),v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() )
#define bout(x) cout << bitset<sizeof(x)*8>(x) << endl
#define bcnt(x) __builtin_popcount(x)
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

int add[120], sub[120];
int nxt[120];
int ans[120];

void Main(){
	int n; cin >> n;
	for (int i = 1; i <= n; i++){
		cout << "? ";
		for (int j = 1; j <= n; j++){
			if (i == j){ cout << 2 << ' '; }
			else{ cout << 1 << ' '; }
		}
		cout << endl << flush;
		cin >> add[i];
	}
	for (int i = 1; i <= n; i++){
		cout << "? ";
		for (int j = 1; j <= n; j++){
			if (i == j){ cout << 1 << ' '; }
			else{ cout << 2 << ' '; }
		}
		cout << endl << flush;
		cin >> sub[i];
	}
	int ptr = 0;
	for (int i = 1; i <= n; i++){
		if (add[i] != 0 && add[i] != i){
			nxt[i] = add[i];
		}
		if (sub[i] != 0 && sub[i] != i){
			nxt[ sub[i] ] = i;
		}
		if (sub[i] == 0){ ptr = i; }
	}
	for (int i = 1; i <= n; i++){ ans[ptr] = i; ptr = nxt[ptr]; }
	cout << "! ";
	for (int i = 1; i <= n; i++){ cout << ans[i] << ' '; }
	cout << flush;
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