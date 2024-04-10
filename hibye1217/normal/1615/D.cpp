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

int par[200020], sz[200020], flp[200020];
vector<int> cld[200020];

int fnd(int a){
	if (par[a] == a){ return a; }
	return par[a] = fnd(par[a]);
}

int uni(int a, int b, int c){
	int pa = fnd(a), pb = fnd(b);
	if (pa == pb){
		if ( (flp[a]^flp[b]) != c ){ return -1; }
		return 0;
	}
	if (sz[pa] > sz[pb]){ swap(pa, pb); swap(a, b); }
	bool chk = ( (flp[b]^flp[a]) != c );
	for (int x : cld[pa]){
		cld[pb].push_back(x);
		if (chk){ flp[x] ^= 1; }
	}
	cld[pa].clear();
	sz[pb] += sz[pa];
	par[pa] = pb;
	return 0;
}

typedef pair<pi2, int> pi3;
vector<pi3> qry;

void Main(){
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; i++){
			par[i] = i; flp[i] = 0; sz[i] = 1;
			cld[i].push_back(i);
		}
		for (int i = 1; i < n; i++){
			int x, y, z; cin >> x >> y >> z;
			if (z != -1){
				int a = 0;
				for (int b = 0; b <= 30; b++){
					int bit = 1<<b;
					if (z & bit){ a ^= 1; }
				}
				uni(x, y, a);
				qry.push_back({ {x, y}, z });
			}
			else{
				qry.push_back({ {x, y}, -1 });
			}
		}
		bool flg = 1;
		while (m--){
			int a, b, c; cin >> a >> b >> c;
			int res = uni(a, b, c);
			if (res == -1){ flg = 0; }
		}
		if (!flg){ cout << "NO" << endl; }
		else{
			cout << "YES" << endl;
			for (pi3 q : qry){
				int a = q.fr.fr, b = q.fr.sc;
				int c = q.sc;
				cout << a << ' ' << b << ' ';
				if (c != -1){ cout << c << endl; }
				else{ cout << (flp[a]^flp[b]) << endl; }
			}
		}
		for (int i = 1; i <= n; i++){
			cld[i].clear();
			qry.clear();
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