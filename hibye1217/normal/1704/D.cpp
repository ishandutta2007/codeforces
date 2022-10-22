#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 9
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define mkp make_pair
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );
template <typename T> using priority_stack = priority_queue< T, vector<T>, greater<T> >;



void Main(){
	int t; cin >> t; while (t--){
		int n, m; cin >> n >> m;
		vector< vector<ll> > v(n);
		for (vector<ll>& w : v){ w.resize(m); }
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){ cin >> v[i][j]; }
			for (int j = 1; j < m; j++){ v[i][j] += v[i][j-1]; }
			for (int j = 1; j < m; j++){ v[i][j] += v[i][j-1]; }
			//cout << v[i][m-1] << endl;
		}
		ll val = v[0][m-1]; int idx = 0;
		if (val != v[1][m-1] && val != v[2][m-1]){
			idx = 0; val = v[1][m-1];
		}
		else{
			for (int i = 0; i < n; i++){
				if (val != v[i][m-1]){ idx = i; }
			}
		}
		cout << idx+1 << ' ' << val - v[idx][m-1] << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
}