#include <bits/stdc++.h>
//#define DEBUG
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<pair<vi, vi>, int> cache;

int rec(vector<int> a, vector<int> c) {
	auto key = make_pair(a, c);
	if (cache.count(key))
		return cache[key];
	int n = sz(a);
	int ret = 0;
	rep(i,0,n)
		ret += c[i];
	rep(i,0,n)
	rep(j,i+1,n)
	rep(k,j+1,n) {
		if (a[i] == a[k] && c[i] == 0 && c[j] == 0 && c[k] == 0) {
			auto new_c = c;
			new_c[j] = 1;
			ret = max(ret, rec(a, new_c));
		}
	}
	cache[key] = ret;
	return ret;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
#ifdef DEBUG
	while (true) {
#endif
	int n;
#ifdef DEBUG
	n = (rand()%10)+3;
	cerr << endl << n << endl;
#else
	cin >> n;
#endif
	vector<int> a(n);
	vector<vector<int>> b(n+2);
	rep(i,0,n) {
#ifdef DEBUG
		a[i] = rand()%(n+1);
		cerr << a[i] << " ";
#else
		cin >> a[i];
#endif
		b[a[i]].push_back(i);
	}
#ifdef DEBUG
	cerr << endl;
	int bruteforce = rec(a, vector<int>(n));
#endif
	a.push_back(n+1);
	b[n+1].push_back(n);
	++n;
	int l = -2, r = -1;
	int old_r = -1;
	int ans = 0;
	int in_cur = 0;
	int to_add = 0;
	vector<int> dp(n+1);
	set<int> S;
	map<int, int> M;
	set<int> T;
	int max_dp = 0;
	int k = 0;
	rep(i,0,n) {
		int new_r = b[a[i]].back();
		if (i > r) {
			//ans += max(0, in_cur-1);
			//ans += max(0, r-l-1);
			/*if (old_r < r) {
				to_add -= 1;
			}*/
			to_add += r-l-1;
			to_add += max_dp;
			ans += max(to_add, 0);
			l = i;
			r = new_r;
			T.insert(l);
			S.insert(r);
			M[r]=k++;
			old_r = r;
			to_add = 0;
			max_dp = 0;
			//ans += r-l-1;
		}
		if (new_r > r) {
			to_add--;
			auto it = S.lower_bound(i);
			dp[new_r] = dp[*it]+(k-M[*it]-1);
			max_dp = max(max_dp, dp[new_r]);
			T.insert(i);
			S.insert(new_r);
			M[new_r]=k++;
			//ans += new_r-r-1;
			//--ans;
			r = new_r;
			/*if (old_r < i) {
				to_add -= 2;
				old_r = r;
			}*/
		}
	}
	cout << ans << endl;
#ifdef DEBUG
	cerr << bruteforce << endl;
	assert(ans == bruteforce);
}
#endif
}