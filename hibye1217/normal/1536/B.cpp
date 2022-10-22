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
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using cpl = complex<ld>;
const ld pi = 3.14159265358979323846264338327950288;
const ld tau = 2 * pi;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

#define DEBUG 0

int arr[120];

void Main(){
	int t; cin >> t;
	while (t--){
		int sl; string s;
		cin >> sl >> s;
		for (int i = 0; i < 26; i++){
			string ss = "";
			ss += (char)(i+'a');
			bool chk = 1;
			for (int l = 0; l < sl; l++){
				string str = s.substr(l, 1);
				if (ss == str){ chk = 0; break; }
			}
			if (chk){ cout << ss; goto don; }
		}
		for (int i = 0; i < 26; i++){
			for (int j = 0; j < 26; j++){
				string ss = "";
				ss += (char)(i+'a');
				ss += (char)(j+'a');
				bool chk = 1;
				for (int l = 0; l < sl-1; l++){
					string str = s.substr(l, 2);
					if (ss == str){ chk = 0; break; }
				}
				if (chk){ cout << ss; goto don; }
			}
		}
		for (int i = 0; i < 26; i++){
			for (int j = 0; j < 26; j++){
				for (int k = 0; k < 26; k++){
					string ss = "";
					ss += (char)(i+'a');
					ss += (char)(j+'a');
					ss += (char)(k+'a');
					bool chk = 1;
					for (int l = 0; l < sl-2; l++){
						string str = s.substr(l, 3);
						if (ss == str){ chk = 0; break; }
					}
					if (chk){ cout << ss; goto don; }
				}
			}
		}
		don: cout << endl;
	}
}

int main(){
#if DEBUG == 0
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}