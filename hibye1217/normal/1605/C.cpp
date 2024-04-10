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
const ld pi = 3.141592; // const ld pi = 3.14159265358979323846264338327950288;
const ld tau = 2 * pi;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};



// #define DEBUG

int idx[1000020];
int prf[1000020][2];

inline int f(int i1, int i2, int j){
	if (i1 == 0){ return prf[i2][j]; }
	return prf[i2][j] - prf[i1-1][j];
}

void Main(){
	int t; cin >> t;
	while (t--){
		int sl; cin >> sl;
		string s; cin >> s;
		int cnt = 0;
		prf[0][0] = prf[0][1] = 0;
		for (int i = 0; i < sl; i++){
			if (s[i] == 'a'){ cnt += 1; idx[cnt] = i; }
			if (i != 0){
				prf[i][0] = prf[i-1][0];
				prf[i][1] = prf[i-1][1];
			}
			if (s[i] == 'b'){ prf[i][0] += 1; }
			if (s[i] == 'c'){ prf[i][1] += 1; }
		}
		int ans = 1e9;
		for (int i = 2; i <= cnt; i++){
			int i1 = idx[i-1], i2 = idx[i];
			int bc = f(i1, i2, 0), cc = f(i1, i2, 1);
			if (bc < 2 && cc < 2){ ans = min(ans, i2-i1+1); }
		}
		for (int i = 3; i <= cnt; i++){
			int i1 = idx[i-2], i2 = idx[i];
			int bc = f(i1, i2, 0), cc = f(i1, i2, 1);
			if (bc < 3 && cc < 3){ ans = min(ans, i2-i1+1); }
		}
		if (ans == 1e9){ cout << -1 << endl; }
		else{ cout << ans << endl; }
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