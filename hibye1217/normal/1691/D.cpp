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
typedef pair<pl2, pl2> pl4;

const ll INF = 1e18;
ll arr[262150]; ll prf[262150];
int N;

pl2 seg2[524290];
pl2 qry2(int st, int ed){ st += N; ed += N;
	pl2 res = {-INF, 0};
	while (st <= ed){
		if (st & 1){ res = max(res, seg2[st]); st += 1; }
		if (~ed & 1){ res = max(res, seg2[ed]); ed -= 1; }
		if (st > ed){ break; }
		st >>= 1; ed >>= 1;
	}
	return res;
}

pl4 seg[524290];
pl4 qry(int st, int ed){ st += N; ed += N;
	pl4 res = { {INF, 0}, {-INF, 0} };
	while (st <= ed){
		if (st & 1){
			res.fr = min(res.fr, seg[st].fr);
			res.sc = max(res.sc, seg[st].sc);
			st += 1;
		}
		if (~ed & 1){
			res.fr = min(res.fr, seg[ed].fr);
			res.sc = max(res.sc, seg[ed].sc);
			ed -= 1;
		}
		if (st > ed){ break; }
		st >>= 1; ed >>= 1;
	}
	return res;
}

bool ans = 1;
void dnc(int st, int ed){
	if (st >= ed || !ans){ return; }
	pl2 p = qry2(st, ed); ll val = p.fr; int mid = p.sc;
	//cout << "DNC " << st << ' ' << ed << "   " << mid << ' ' << val << endl;
	if (val <= 0){ return; }
	dnc(st, mid-1); dnc(mid+1, ed);
	pl4 p1 = qry(st-1, mid-1), p2 = qry(mid, ed);
	ll x1 = p1.fr.fr, x2 = p2.sc.fr;
	if (x2-x1 > val){ ans = 0; }
}

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		for (int i = 1; i <= n; i++){ prf[i] = prf[i-1] + arr[i]; }
		N = 1; while (N <= n){ N <<= 1; }
		for (int i = N+N-1; i >= 1; i--){
			if (N <= i){ int idx = i-N;
				seg[i] = { { prf[idx], idx }, { prf[idx], idx } };
				seg2[i] = { arr[idx], idx };
			}
			else{
				seg[i].fr = min(seg[i<<1].fr, seg[i<<1|1].fr);
				seg[i].sc = max(seg[i<<1].sc, seg[i<<1|1].sc);
				seg2[i] = max(seg2[i<<1], seg2[i<<1|1]);
			}
		}
		ans = 1; dnc(1, n); cout << (ans ? "YES" : "NO") << endl;
		for (int i = 1; i <= n; i++){ prf[i] = 0; }
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
}