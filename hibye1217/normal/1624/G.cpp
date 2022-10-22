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

typedef pair<pi2, int> pi3;

// #define DEBUG

vector<pi3> edg;
int par[200020];

int fnd(int a){
	if (par[a] == a){ return a; }
	return par[a] = fnd(par[a]);
}

void uni(int a, int b){
	int pa = fnd(a), pb = fnd(b);
	if (pa == pb){ return; }
	par[pa] = pb;
}

void Main(){
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		for (int i = 1; i <= m; i++){
			int a, b, c; cin >> a >> b >> c;
			edg.push_back({ {a, b}, c });
		}
		int ans = (1<<31) - 1;
		for (int b = 30; b >= 0; b--){
			int bit = 1<<b;
			ans ^= bit;
			for (int i = 1; i <= n; i++){ par[i] = i; }
			for (pi3 p : edg){
				int a = p.fr.fr, b = p.fr.sc;
				int c = p.sc;
				if ( (c&ans) != c ){ continue; }
				uni(a, b);
			}
			int res = fnd(1); bool flg = 1;
			for (int i = 1; i <= n; i++){
				if ( fnd(i) != res ){ flg = 0; }
			}
			if (!flg){ ans ^= bit; }
		}
		cout << ans << endl; edg.clear();
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