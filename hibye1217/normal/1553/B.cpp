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



void Main(){
	int t; cin >> t;
	while (t--){
		string s1, s2; cin >> s1 >> s2;
		int l1 = s1.size(), l2 = s2.size();
		bool ans = 0;
		for (int i = 0; i <= l2; i++){
			for (int st = 0; st < l1; st++){
				if (s1[st] != s2[0]){ continue; }
				bool flg = 1;
				int ptr = st;
				for (int j = 1; j < l2; j++){
					if (j < i){ ptr += 1; }
					else{ ptr -= 1; }
					if (0 > ptr || ptr >= l1){ flg = 0; break; }
					if (s1[ptr] != s2[j]){ flg = 0; break; }
				}
				if (flg){ ans = 1; }
			}
		}
		if (ans){ cout << "YES" << endl; }
		else{ cout << "NO" << endl; }
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