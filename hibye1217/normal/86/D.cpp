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
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using cpl = complex<ld>;
const ld pi = 3.14159265358979323846264338327950288;
const ld tau = 2 * pi;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

// #define DEBUG
typedef pair<int, pii> piii;

int sq;
int arr[200020];
int cnt[1000020];
piii qry[200020];
ll ans[200020];

inline void f(ll& res, int idx, int val){
	if (val == 1){
		res += (2LL*cnt[idx] + 1) * idx;
		cnt[idx] += 1;
	}
	if (val == -1){
		res += (-2LL*cnt[idx] + 1) * idx;
		cnt[idx] -= 1;
	}
}

void Main(){
	int n, q; cin >> n >> q; sq = sqrt(n);
	for (int i = 1; i <= n; i++){ cin >> arr[i]; }
	for (int i = 1; i <= q; i++){
		cin >> qry[i].sc.fr >> qry[i].sc.sc;
		qry[i].fr = i;
	}
	sort(qry+1, qry+q+1, [](piii a, piii b){
		int sa = a.sc.fr / sq, sb = b.sc.fr / sq;
		if (sa != sb){ return sa < sb; }
		return a.sc.sc < b.sc.sc;
	});
	int st = 1, ed = 1; cnt[ arr[1] ] += 1;
	ll res = arr[1];
	for (int i = 1; i <= q; i++){
		int idx = qry[i].fr;
		int pst = qry[i].sc.fr, ped = qry[i].sc.sc;
		for (int p = pst; p < st; p++){ f(res, arr[p], 1); }
		for (int p = st; p < pst; p++){ f(res, arr[p], -1); }
		for (int p = ed+1; p <= ped; p++){ f(res, arr[p], 1); }
		for (int p = ped+1; p <= ed; p++){ f(res, arr[p], -1); }
		st = pst; ed = ped;
		ans[idx] = res;
	}
	for (int i = 1; i <= q; i++){
		cout << ans[i] << endl;
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