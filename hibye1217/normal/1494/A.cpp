#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
#define all(v) v.begin(),v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );
#define bout(x) cout << bitset<sizeof(x)*8>(x) << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef pair<ld, ld> pld;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {-1, 1, 0, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

void Main(){
	int t;
	cin >> t;
	while (t--){
		string s;
		cin >> s;
		int sl = s.size();
		if (s[0] == s[sl-1]){ cout << "NO" << endl; continue; }
		char op = s[0], cl = s[sl-1];
		int opc = 0, clc = 0, otc = 0;
		for (int i = 0; i < sl; i++){
			if (s[i] == op){ s[i] = '('; opc += 1; }
			else if (s[i] == cl){ s[i] = ')'; clc += 1; }
			else{ otc += 1; }
		}
		char ot;
		if (opc+otc == clc){ ot = '('; }
		else if (clc+otc == opc){ ot = ')'; }
		else{ cout << "NO" << endl; continue; }
		for (int i = 0; i < sl; i++){
			if (s[i] != '(' && s[i] != ')'){ s[i] = ot; }
		}
		int chk = 0;
		bool ans = 1;
		for (int i = 0; i < sl; i++){
			if (s[i] == '('){ chk += 1; }
			else{ chk -= 1; }
			ans &= chk >= 0;
		}
		ans &= chk == 0;
		cout << (ans ? "YES" : "NO") << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}