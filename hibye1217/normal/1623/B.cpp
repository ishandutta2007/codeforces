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

vector<pi2> v;
typedef pair<pi2, int> pi3;
pi3 ans[1020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){
			int l, r; cin >> l >> r;
			v.push_back({l, r});
		}
		sort(all(v), [](pi2 a, pi2 b){
			return a.sc-a.fr > b.sc-b.fr;
		});
		for (int i = 0; i < n; i++){
			ans[i].fr = v[i];
			int l = v[i].fr, r = v[i].sc;
			for (int j = i-1; j >= 0; j--){
				int l2 = v[j].fr, r2 = v[j].sc;
				if (l == l2){ ans[j].sc = r+1; }
				if (r == r2){ ans[j].sc = l-1; }
				if (l == l2 || r == r2){ break; }
			}
		}
		for (int i = 0; i < n; i++){
			int l = ans[i].fr.fr, r = ans[i].fr.sc;
			int x = ans[i].sc;
			cout << l << ' ' << r << ' ';
			if (l == r){ cout << l << endl; }
			else{ cout << x << endl; }
		}
		if (t){ cout << endl; }
		v.clear(); for (int i = 0; i < n; i++){ ans[i] = { {0, 0}, 0 }; }
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