#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

// #define DEBUG

inline int ask(int x){
	cout << "? " << x << endl << flush;
	int res; cin >> res; return res;
}

bool chk[10020];
int ans[10020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int cnt = 0;
		for (int i = 1; i <= n; i++){
			if (chk[i]){ continue; }
			vector<pi2> v;
			while (1){
				int res = ask(i);
				//cout << res << ' ' << chk[res] << endl;
				if (chk[res]){ break; }
				v.push_back({res, cnt});
				//cout << "C " << cnt << endl;
				cnt += 1; chk[res] = 1;
			}
			cnt += 1;
			int cyc = v.size();
			for (int j = 0; j < cyc; j++){
				v[j].sc %= cyc; if (v[j].sc == 0){ v[j].sc = cyc; }
				//cout << v[j].fr << ' ' << v[j].sc << endl;
			}
			sort(all(v), [](pi2 a, pi2 b){ return a.sc < b.sc; });
			int ptr = i;
			for (int j = 0; j < cyc; j++){
				//cout << v[j].fr << ' ' << v[j].sc << endl;
				int now = v[j].fr;
				ans[ptr] = now; ptr = now;
			}
		}
		cout << "! ";
		for (int i = 1; i <= n; i++){ cout << ans[i] << ' '; }
		cout << endl << flush;
		for (int i = 1; i <= n; i++){
			chk[i] = 0; ans[i] = 0;
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