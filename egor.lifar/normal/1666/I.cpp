#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using str = string;
using pi = pair<int, int>;
#define mp make_pair
#define f first
#define s second
#define tcT template<class T
tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vpi = V<pi>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

#define each(a, x) for(auto& a: x)

const int MOD = 1e9+7;
const db PI = acos((db)-1);
mt19937 rng(0);

tcT> bool ckmin(T& a, const T& b){
	return b < a ? a = b, 1 : 0;
}
tcT> bool ckmax(T& a, const T& b){
	return a < b ? a = b, 1 : 0;
}



int r[2], c[2];
bool test = false;
int cnt = 0;
map<pair<int, int>, int> resdig;


int querySCAN(int i, int j) {
	cnt++;
	assert(cnt <= 7);
	cout << "SCAN" << ' ' << i << ' ' << j << endl;
	if (test) {
		int sum = 0;
		for (int k = 0; k < 2; k++) {
			sum += abs(r[k] - i) + abs(c[k] - j);
		}
		return sum;
	}
	int sum;
	cin >> sum;
	return sum;
}


int sumdig = 0;


int queryDIG(int i, int j) {
	if (resdig.find(mp(i, j)) != resdig.end()) {
		return resdig[mp(i, j)];
	}
	cnt++;
	assert(cnt <= 7);
	cout << "DIG" << ' ' << i << ' ' << j << endl;
	if (test) {
		for (int k = 0; k < 2; k++) {
			if (r[k] == i && c[k] == j) {
				resdig[mp(i, j)] = 1;
				sumdig += 1;
				return 1;
			}
		}
		resdig[mp(i, j)] = 0;
		return 0;
	}
	int res;
	cin >> res;
	resdig[mp(i, j)] = res;
	sumdig += res;
	return res;
}


int getSCAN(int i, int j, const pair<pair<int, int>, pair<int, int> >  &kek) {
	return abs(i - kek.first.first) + abs(i - kek.second.first) + abs(j - kek.first.second) + abs(j - kek.second.second);
}


int getDIG(int i, int j, const pair<pair<int, int>, pair<int, int> >  &kek) {
	return mp(i, j) == kek.first || mp(i, j) == kek.second;
}


void solve() {
	sumdig = 0;
	resdig.clear();
	int n, m;
	cin >> n >> m;
	// n = 13, m = 15;
	// r[0] = rand() % n + 1, c[0] = rand() % m + 1;
	// r[1] = rand() % n + 1, c[1] = rand() % m + 1;
	// while (r[1] == r[0] && c[1] == c[0]) {
	// 	r[1] = rand() % n + 1, c[1] = rand() % m + 1;
	// }
	cnt = 0;
	int f = querySCAN(1, 1);
	int f1 = querySCAN(n, 1);
	vector<pair<pair<int, int>, pair<int, int> > > st;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= n; k++) {
				for (int h = 1; h <= m; h++) {
					if (mp(i, j) < mp(k, h)) {
						auto z = mp(mp(i, j), mp(k, h));
						if (getSCAN(1, 1, z) == f && getSCAN(n, 1, z) == f1) {
							st.pb(mp(mp(i, j), mp(k, h)));
						}
					}
				}
			}
		}
	}	
	while (sz(st) > 1) {
		int opt = 1e9;
		int pi, pj;
		int ch;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int cnt[70];
				memset(cnt, 0, sizeof(cnt));
				for (auto z: st) {
					cnt[getSCAN(i, j, z)]++;
				}
				int res = 0;
				for (int t = 0; t < 70; t++) {
					ckmax(res, cnt[t]);
				}	
				if (res < opt) {
					opt = res;
					pi = i;
					pj = j;
					ch = 0;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int cnt[70];
				memset(cnt, 0, sizeof(cnt));
				for (auto z: st) {
					cnt[getDIG(i, j, z)]++;
				}
				int res = 0;
				for (int t = 0; t < 70; t++) {
					ckmax(res, cnt[t]);
				}	
				if (res < opt) {
					opt = res;
					pi = i;
					pj = j;
					ch = 1;
				}
			}
		}
		if (ch == 0) {
			int f = querySCAN(pi, pj);
			vector<pair<pair<int, int>, pair<int, int> > > nst;
			for (auto z: st) {
				if (getSCAN(pi, pj, z) == f) {
					nst.pb(z);
				}
			}
			st = nst;
		} else {
			int f = queryDIG(pi, pj);
			vector<pair<pair<int, int>, pair<int, int> > > nst;
			for (auto z: st) {
				if (getDIG(pi, pj, z) == f) {
					nst.pb(z);
				}
			}
			st = nst;
		}
	}
	queryDIG(st[0].first.first, st[0].first.second);
	queryDIG(st[0].second.first, st[0].second.second);
	assert(sumdig == 2);
} 

int main(){
	int t = 100000;
	cin >> t;
	while (t--) {
	//	cerr << t << ' ' << "OK" << endl;
		solve();
	}
}