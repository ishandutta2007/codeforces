#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
//#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<pair<int, int>> cleanup_segs(vector<pair<int, int>> P) {
	vector<pair<int, int>> p;
	rep(i,0,sz(P)) {
		p.emplace_back(P[i].first, -P[i].second);
	}
	sort(all(p));
	vector<pair<int, int>> q;
	q.push_back(make_pair(p[0].first, -p[0].second));
	rep(i,1,sz(P)) {
		if (-p[i].second > q.back().second) {
			q.push_back(make_pair(p[i].first, -p[i].second));
		}
	}
	return q;
}

/*int bruteforce(int n, int m, vector<int> a, vector<pair<int, int>> p) {
	int ans = 1e9;
	rep(l,0,n) {
		rep(r,l,n+1) {
			bool ok = true;
			for (auto it : p) {
				rep(i,it.first,it.second)
				rep(j,i+1,it.second) {
					if (a[i] == a[j] && !(i >= l && i < r) && !(j >= l && j < r)) {
						ok = false;
					}
				}
			}
			if (ok)
				ans = min(ans, r-l);
		}
	}
	return ans;
}*/

void solve() {
	int n, m;
#ifdef DEBUG
	n = (rand()%5)+1;
	m = (rand()%5)+1;
	cerr << endl;
	cerr << endl;
	cerr << n << " " << m << endl;
#else
	cin >> n >> m;
#endif
	vector<int> a(n);
	map<int, vector<int>> M;
	rep(i,0,n) {
#ifdef DEBUG
		a[i] = rand()%10;
		cerr << a[i] << " ";
#else
		cin >> a[i];
#endif
		M[a[i]].push_back(i);
	}
#ifdef DEBUG
	cerr << endl;
#endif
	vector<pair<int, int>> p(m);
	rep(i,0,m) {
#ifdef DEBUG
		p[i].first = (rand()%n)+1;
		p[i].second = (rand()%(n-p[i].first+1))+p[i].first;
		cerr << p[i].first << " " << p[i].second << endl;;
#else
		cin >> p[i].first >> p[i].second;
#endif
		--p[i].first;
	}
	auto q = cleanup_segs(p);
	vector<pair<int, int>> contain_either;
	for (auto it : M) {
		vector<int> v = it.second;
		rep(i,0,sz(v)) {
			auto seg_it = lower_bound(all(q), make_pair(v[i], int(1e9)));
			if (seg_it == q.begin()) {
				continue;
			}
			--seg_it;
			auto rval_it = lower_bound(all(v), seg_it->second);
			int j = rval_it - v.begin() - 1;
			if (j > i) {
				contain_either.emplace_back(v[i], v[j]);
				/*L = min(L, v[i+1]);
				R = max(R, v[j-1]);*/
				if (i+1 < j) {
					contain_either.emplace_back(v[i], v[i+1]);
					contain_either.emplace_back(v[i], v[j-1]);
					contain_either.emplace_back(v[i+1], v[j]);
					contain_either.emplace_back(v[j-1], v[j]);
				}
			}
		}
	}
	if (sz(contain_either) == 0) {
		cout << 0 << endl;
		//assert(bruteforce(n, m, a, p) == 0);
		return;
	}
	sort(all(contain_either));
	set<int> pos;
	for (auto it : contain_either) {
		pos.insert(it.first);
		pos.insert(it.second);
	}
	int j = 0;
	int max_r = 0;
	int min_r = 1e9;
	int max_l = contain_either.back().first;
	int ans = 1e9;
	for (int Pos : pos) {
		while (j < sz(contain_either) && Pos > contain_either[j].first) {
			min_r = min(min_r, contain_either[j].second);
			max_r = max(max_r, contain_either[j].second);
			j++;
		}
		if (Pos > min_r) {
			break;
		}
		int l = Pos;
		int r = max(max_r, max_l);
		ans = min(ans, r-l+1);
	}
	//assert(bruteforce(n, m, a, p) == ans);
	cout << ans << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}