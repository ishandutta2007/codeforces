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

int arr[50020][6];

inline int f(int i1, int i2){
	int cnt = 0;
	for (int j = 1; j <= 5; j++){
		if (arr[i1][j] < arr[i2][j]){ cnt += 1; }
	}
	return cnt;
}

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= 5; j++){ cin >> arr[i][j]; }
		}
		int ptr = 1;
		queue<int> q;
		for (int i = 1; i <= n; i++){ q.push(i); }
		int cnt = 0;
		while (!q.empty()){
			int now = q.front(); q.pop();
			if ( f(ptr, now) < 3 ){ ptr = now; cnt = 0; }
			else{ q.push(now); cnt += 1; }
			if (cnt >= q.size()+2){ break; }
		}
		bool chk = 1;
		for (int i = 1; i <= n; i++){
			if (ptr == i){ continue; }
			if ( f(ptr, i) < 3 ){ chk = 0; }
		}
		if (chk){ cout << ptr << endl; }
		else{ cout << -1 << endl; }
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