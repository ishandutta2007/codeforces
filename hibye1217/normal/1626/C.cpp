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

inline ll f(ll x){ return x*(x+1) / 2; }

pl2 arr[120]; pl2 res[120];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){ cin >> arr[i].sc; }
		for (int i = 1; i <= n; i++){ cin >> arr[i].fr; }
		arr[0] = {0, 0}; res[0] = {0, 0};
		for (int i = 1; i <= n; i++){
			for (int j = i-1; j >= 0; j--){
				ll t1 = arr[j].sc, t2 = arr[i].sc; ll td = t2-t1;
				ll h2 = arr[i].fr;
				if (td >= h2){
					res[i] = { res[j].fr+f(h2), h2 };
					break;
				}
				else{
					ll h1 = res[j].sc;
					if (h1+td < h2){ continue; }
					else{
						res[i] = { res[j].fr + f(h1+td)-f(h1), h1+td };
						break;
					}
				}
			}
			//cout << "ANS " << res[i].fr << ' ' << res[i].sc << endl;
		}
		cout << res[n].fr << endl;
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