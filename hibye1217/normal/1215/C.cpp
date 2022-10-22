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

vector<int> v1, v2;
vector<pi2> ans;

void Main(){
	int n; cin >> n;
	string s1, s2; cin >> s1 >> s2;
	for (int i = 0; i < n; i++){
		if (s1[i] == 'a' && s2[i] == 'b'){ v1.push_back(i+1); }
		if (s1[i] == 'b' && s2[i] == 'a'){ v2.push_back(i+1); }
	}
	int l1 = v1.size(), l2 = v2.size();
	if ((l1+l2) % 2 != 0){ cout << -1; return; }
	for (int i = 1; i < l1; i += 2){
		int i1 = v1[i-1], i2 = v1[i];
		ans.push_back({i1, i2});
	}
	for (int i = 1; i < l2; i += 2){
		int i1 = v2[i-1], i2 = v2[i];
		ans.push_back({i1, i2});
	}
	if (l1 & 1){
		int i1 = v1[l1-1], i2 = v2[l2-1];
		ans.push_back({i1, i1});
		ans.push_back({i2, i1});
	}
	cout << ans.size() << endl;
	for (pi2 p : ans){ cout << p.fr << ' ' << p.sc << endl; }
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