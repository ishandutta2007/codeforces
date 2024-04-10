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

inline sgn(int x){ if (x > 0){ return 1; } if (x < 0){ return -1; } return 0; }

pi2 arr[200020], prf[200020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){
			int x; cin >> x; arr[i] = { abs(x), sgn(x) };
		}
		prf[0] = {0, 1};
		for (int i = 1; i <= n; i++){
			prf[i] = prf[i-1];
			if (arr[i].fr == 0){ prf[i] = {0, 1}; }
			if (arr[i].fr == 2){ prf[i].fr += 1; }
			if (arr[i].sc == -1){ prf[i].sc *= -1; }
		}
		int st = 1;
		int mx = 0, l = n, r = 0;
		while (st <= n){
			if (arr[st].fr == 0){ st += 1; continue; }
			int ed = st;
			while (ed <= n){
				if (arr[ed].fr != 0){ ed += 1; } else{ break; }
			}
			for (int i = st; i < ed; i++){
				if (prf[i].sc == -1){ continue; }
				if (prf[i].fr > mx){ mx = prf[i].fr; l = st-1; r = n-i; }
			}
			for (int p = st; p < ed; p++){
				if (prf[p].sc != -1){ continue; }
				for (int i = p; i < ed; i++){
					if (prf[i].sc != -1){ continue; }
					if (prf[i].fr - prf[p].fr > mx){ mx = prf[i].fr - prf[p].fr; l = p; r = n-i; }
				}
				break;
			}
			st = ed;
		}
		cout << l << ' ' << r << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}