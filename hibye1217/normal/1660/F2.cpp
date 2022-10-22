#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

const int N = 524288, M = 262144; int fen[524290];
void upd(int pos, int val){
	for (int i = pos; i < N; i += i&-i){ fen[i] += val; }
}
int qry(int pos){
	int res = 0;
	for (int i = pos; i > 0; i -= i&-i){ res += fen[i]; }
	return res;
}

int prf[200020];
void Main(){
	int t; cin >> t;
	while (t--){
		int sl; string s; cin >> sl >> s; s = " " + s;
		prf[0] = 0;
		for (int i = 1; i <= sl; i++){ prf[i] = prf[i-1] + (s[i]=='+' ? 1 : -1); }
		ll ans = 0;
		for (int mod : {0, 1, 2}){
			//cout << "MOD " << mod << ": ";
			for (int i = 0; i <= sl; i++){
				if ((prf[i]%3+3)%3 != mod){ continue; }
				ll res = qry(N-1) - qry(prf[i]+M-1);
				ans += res;
				upd(prf[i]+M, 1);
				//cout << prf[i] << ' ' << flush;
			}
			//cout << endl;
			for (int i = 0; i <= sl; i++){
				if ((prf[i]%3+3)%3 != mod){ continue; }
				upd(prf[i]+M, -1);
			}
		}
		cout << ans << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}