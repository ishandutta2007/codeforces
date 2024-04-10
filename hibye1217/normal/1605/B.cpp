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



void Main(){
	int t; cin >> t;
	while (t--){
		int sl; cin >> sl;
		string s; cin >> s;
		int cnt = 0;
		for (int i = 0; i < sl; i++){ if (s[i] == '0'){ cnt += 1; } }
		vector<int> ans;
		for (int i = 0; i < cnt; i++){ if (s[i] == '1'){ ans.push_back(i+1); } }
		for (int i = cnt; i < sl; i++){ if (s[i] == '0'){ ans.push_back(i+1); } }
		if (ans.size() == 0){ cout << 0 << endl; }
		else{
			cout << 1 << endl << ans.size() << ' ';
			for (int idx : ans){ cout << idx << ' '; }
			cout << endl;
		}
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