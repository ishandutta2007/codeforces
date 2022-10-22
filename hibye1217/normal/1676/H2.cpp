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

int arr[200020];
int N = 1; int seg[524290];

void upd(int pos, int val){ pos += N-1;
	seg[pos] += val; //cout << "SEGMENT " << pos << ' ' << seg[pos] << endl;
	pos >>= 1;
	pst: if (pos){
		seg[pos] = seg[pos<<1] + seg[pos<<1|1];
		//cout << "SEGMENT " << pos << ' ' << seg[pos] << endl;
		pos >>= 1; goto pst;
	}
}
int qry(int st, int ed){ st += N-1; ed += N-1;
	int res = 0;
	qst: if (st <= ed){
		//cout << "QUERY1 " << st << "~" << ed << " / " << res << endl;
		if (st & 1){ res += seg[st]; st += 1; }
		if (~ed & 1){ res += seg[ed]; ed -= 1; }
		//cout << "QUERY2 " << st << "~" << ed << " / " << res << endl;
		if (st > ed){ goto qed; }
		st >>= 1; ed >>= 1; goto qst;
	}
	qed: return res;
}

void Main(){
	int t; cin >> t;
	tst: if (t > 0){
		int n; cin >> n;
		int i = 1; ast: if (i <= n){ cin >> arr[i]; i++; goto ast; }
		N = 1; nst: if (N < n){ N <<= 1; goto nst; }
		i = 1; sst: if (i < N+N){ seg[i] = 0; i++; goto sst; }
		ll ans = 0;
		i = 1; ist: if (i <= n){
			//cout << "RANGE " << arr[i] << " ~ " << N << endl;
			ll res = qry(arr[i], N); ans += res;
			//cout << "RESULT " << i << ' ' << res << endl;
			upd(arr[i], 1); i++; goto ist;
		}
		cout << ans << endl;
		t--; goto tst;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
}