#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
#define all(v) v.begin(),v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );
#define bout(x) cout << bitset<sizeof(x)*8>(x) << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

typedef pair<pii, int> piii;

int N = 262144;
piii seg[524290];
pii range[524290];
vector<piii> v, idx;

void update(int pos, int val){
	pos += N-1;
	seg[pos] = { { max(0,val), min(0,val) }, val };
	pos >>= 1;
	while (pos){
		piii l = seg[pos<<1], r = seg[pos<<1|1];
		int mx = max(l.fr.fr, r.fr.fr + l.sc);
		int mn = min(l.fr.sc, r.fr.sc + l.sc);
		seg[pos] = { { mx, mn }, l.sc + r.sc };
		//cout << "TREE " << pos << ' ' << seg[pos].fr.fr << ' ' << seg[pos].fr.sc << ' ' << seg[pos].sc << endl;
		pos >>= 1;
	}
}

void query(int l, int r){
	l += N-1; r += N-1;
	if (l > r) return;
	while (l <= r){
		if (l & 1){
			idx.push_back({ range[l], l });
			l += 1;
		}
		if (~r & 1){
			idx.push_back({ range[r], r });
			r -= 1;
		}
		if (l > r){ break; }
		l >>= 1; r >>= 1;
	}
}

void Main(){
	range[1] = {1, N};
	for (int i = 2; i < N*2; i++){
		int l = range[i>>1].fr, r = range[i>>1].sc;
		int m = l+r >> 1;
		if (~i & 1){ range[i] = {l, m}; }
		else{ range[i] = {m+1, r}; }
	}
	int t;
	cin >> t;
	while (t--){
		int n, q;
		string s;
		cin >> n >> q >> s;
		for (int i = 1; i <= n; i++){
			update(i, s[i-1] == '+' ? 1 : -1);
		}
		while (q--){
			int l, r;
			cin >> l >> r;
			query(1, l-1); query(r+1, n);
			sort(all(idx));
			for (piii p : idx){
				v.push_back( seg[p.sc] );
			}
			int vl = v.size();
			if (vl == 0){
				cout << 1 << endl;
			}
			else{
				int mx = v[0].fr.fr, mn = v[0].fr.sc;
				for (int i = 1; i < vl; i++){
					v[i].fr.fr += v[i-1].sc;
					v[i].fr.sc += v[i-1].sc;
					v[i].sc += v[i-1].sc;
					mx = max(v[i].fr.fr, mx);
					mn = min(v[i].fr.sc, mn);
				}
				cout << mx - mn + 1 << endl;
			}
			idx.clear(); v.clear();
		}
		memset(seg, 0, sizeof(seg));
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}