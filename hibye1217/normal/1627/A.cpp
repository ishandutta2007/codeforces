#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );
#define bnt(x) __builtin_popcount(x)



// #define DEBUG

string mp[60];

void Main(){
	int t; cin >> t;
	while (t--){
		int n, m, r, c; cin >> n >> m >> r >> c;
		r -= 1; c -= 1;
		for (int i = 0; i < n; i++){ cin >> mp[i]; }
		bool chk=0, flg=0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (mp[i][j] == 'W'){ continue; }
				chk = 1;
				if (r==i || c==j){ flg = 1; }
			}
		}
		if (mp[r][c] == 'B'){ cout << 0; }
		else if (!chk){ cout << -1; }
		else if (flg){ cout << 1; }
		else{ cout << 2; }
		cout << endl;
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