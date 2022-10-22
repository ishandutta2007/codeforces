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

const ll mod = 998244353;
typedef pair<pi2, int> pi3;

map<int, int> cvt, tvc; set<int> cs; int cc = 0;
pi3 arr[200020];
int por[400030];
ll tim[200020];

const int N = 524288;
ll seg[1048580];

void upd(int pos, ll val){
	for (int i = pos; i < N; i += i&-i){ seg[i] += val; }
}

ll qry(int pos){
	ll res = 0;
	for (int i = pos; i > 0; i -= i&-i){ res += seg[i]; res %= mod; }
	return res;
}

ll qry(int st, int ed){
	return qry(ed) - qry(st-1);
}

void Main(){
	int n; cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> arr[i].fr.sc >> arr[i].fr.fr >> arr[i].sc;
		cs.insert(arr[i].fr.sc); cs.insert(arr[i].fr.fr);
	}
	cs.insert(0); cs.insert( arr[n].fr.sc+1 );
	for (int x : cs){
		cvt[x] = cc;
		tvc[cc] = x;
		cc += 1;
	}
	for (int i = 1; i <= n; i++){
		arr[i].fr.fr = cvt[ arr[i].fr.fr ];
		arr[i].fr.sc = cvt[ arr[i].fr.sc ]; por[ arr[i].fr.sc ] = i;
	}
	for (int i = 1; i <= n; i++){
		int st = arr[i].fr.fr, ed = arr[i].fr.sc;
		int now = st;
		tim[i] = qry(st, ed)+mod + tvc[ed]+mod - tvc[st]; tim[i] %= mod;
		upd(ed, tim[i]);
	}
	ll ans = 0; int ptr = 0;
	while (ptr != cc-1){
		ans += tvc[ptr+1] - tvc[ptr]; ptr += 1;
		if (por[ptr]){
			int p = por[ptr];
			if (arr[p].sc == 0){ arr[p].sc = 1; }
			else{ ans += tim[p]; }
		}
		ans %= mod;
	}
	cout << ans;
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