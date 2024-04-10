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

const int N = 262144;
int a[200020], b[200020];
pi2 tree[525290];

void upd(int pos, int val){
	pos += N;
	tree[pos].sc += val;
	if (tree[pos].sc != 0){ tree[pos].fr = pos-N; }
	else{ tree[pos].fr = 1e9; }
	pos >>= 1;
	while (pos){
		tree[pos].sc = tree[pos<<1].sc + tree[pos<<1|1].sc;
		tree[pos].fr = min( tree[pos<<1].fr, tree[pos<<1|1].fr );
		pos >>= 1;
	}
}

int qry(int st, int ed){
	st += N; ed += N;
	int res = 1e9;
	while (st <= ed){
		if (st & 1){ res = min(res, tree[st].fr); st += 1; }
		if (~ed & 1){ res = min(res, tree[ed].fr); ed -= 1; }
		if (st > ed){ break; }
		st >>= 1; ed >>= 1;
	}
	return res;
}

void Main(){
	int n; cin >> n;
	for (int i = 1; i <= n; i++){ cin >> a[i]; upd(i-1, 0); }
	for (int i = 1; i <= n; i++){
		cin >> b[i];
		upd(b[i], 1);
	}
	for (int i = 1; i <= n; i++){
		int tar = (n - a[i]) % n;
		int idx = qry(tar, n-1);
		if (idx == 1e9){ idx = qry(0, n-1); }
		cout << (a[i] + idx) % n << ' ';
		upd(idx, -1);
	}
}

int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(2);
	Main();
}