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

vector<int> v[100020];
vector<pi2> ans;

void Main(){
	ll n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		int d; cin >> d;
		v[d].push_back(i);
	}
	if (v[0].size() != 1){ cout << -1; return; }
	for (int i = 1; i <= n; i++){
		int l1 = v[i-1].size(), l2 = v[i].size();
		if (i == 1){
			if (l1*k < l2){ cout << -1; return; }
			for (int j = 0; j < l2; j++){
				ans.push_back({v[i-1][j/k], v[i][j]});
			}
		}
		else{
			if (l1*(k-1) < l2){ cout << -1; return; }
			for (int j = 0; j < l2; j++){
				ans.push_back({v[i-1][j/(k-1)], v[i][j]});
			}
		}
	}
	cout << ans.size() << endl;
	for (pi2 p : ans){
		cout << p.fr << ' ' << p.sc << endl;
	}
}

int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(15);
	Main();
}