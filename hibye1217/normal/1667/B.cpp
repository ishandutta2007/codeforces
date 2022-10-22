#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );
typedef pair<ll, pl2> pl3;

ll prf[500020];
map<ll, int> cvt; set<ll> cs; int cc = 0;
int N = 0; const ll INF = 1e18; pl3 seg[1048580];
// DP DP-j DP+j

void upd(int idx, ll val, int j){ int pos = idx + N-1;
	seg[pos].fr = max(seg[pos].fr, val);
	seg[pos].sc.fr = max(seg[pos].sc.fr, val - j);
	seg[pos].sc.sc = max(seg[pos].sc.sc, val + j);
	pos >>= 1;
	while (pos){
		seg[pos].fr = max(seg[pos<<1].fr, seg[pos<<1|1].fr);
		seg[pos].sc.fr = max(seg[pos<<1].sc.fr, seg[pos<<1|1].sc.fr);
		seg[pos].sc.sc = max(seg[pos<<1].sc.sc, seg[pos<<1|1].sc.sc);
		pos >>= 1;
	}
}
pl3 qry(int st, int ed){ st += N-1; ed += N-1;
	pl3 res = { -INF, {-INF, -INF} };
	while (st <= ed){
		if (st & 1){
			res.fr = max(res.fr, seg[st].fr);
			res.sc.fr = max(res.sc.fr, seg[st].sc.fr);
			res.sc.sc = max(res.sc.sc, seg[st].sc.sc);
			st += 1;
		}
		if (~ed & 1){
			res.fr = max(res.fr, seg[ed].fr);
			res.sc.fr = max(res.sc.fr, seg[ed].sc.fr);
			res.sc.sc = max(res.sc.sc, seg[ed].sc.sc);
			ed -= 1;
		}
		if (st > ed){ break; }
		st >>= 1; ed >>= 1;
	}
	return res;
}

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		cs.insert(0);
		prf[0] = 0;
		for (int i = 1; i <= n; i++){
			ll x; cin >> x; prf[i] = prf[i-1] + x;
			cs.insert(prf[i]);
		}
		for (ll x : cs){ cc += 1; cvt[x] = cc; }
		for (int i = 0; i <= n; i++){ prf[i] = cvt[ prf[i] ]; }
		//cout << "ARR "; for (int i = 0; i <= n; i++){ cout << prf[i] << ' '; } cout << endl;
		N = 1; while (N <= n){ N <<= 1; }
		//cout << "SegSize " << N << endl;
		for (int i = 1; i < N+N; i++){ seg[i] = { -INF, {-INF, -INF} }; }
		upd(prf[0], 0, 0);
		for (int i = 1; i <= n; i++){
			ll idx = prf[i];
			ll res = max({ qry(1, idx-1).sc.fr + i, qry(idx, idx).fr, qry(idx+1, N).sc.sc - i });
			//cout << "I " << i << " = " << qry(1, idx-1).sc.fr + i << ' ' << qry(idx, idx).fr << ' ' << qry(idx+1, N).sc.sc - i << endl;
			if (i == n){ cout << res << endl; }
			upd(idx, res, i);
		}
		//cout << flush;
		cvt.clear(); cs.clear(); cc = 0;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}