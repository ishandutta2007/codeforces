#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

////////////////////////////////////////////////////////////////////////////////
// Suffix array - O(L lg^2 L) construction (TESTED on L.A. 2755)
////////////////////////////////////////////////////////////////////////////////
// get_sarray()[i] = idx of suffix s[i..L-1] in list of sorted suffixes
struct suff_array {
	const int L; string s; int i, skip, lvl;
	vector<vi> P; vector<pair<pii,int>> M;
	suff_array(const string &s) : L(s.size()), s(s), P(1, vi(L, 0)), M(L) {
		for (i = 0; i < L-(L==1); i++) P[0][i] = int(s[i]);
		for (skip = 1, lvl = 1; skip < L; skip *= 2, lvl++) {
			P.push_back(vi(L, 0));
			for (int i = 0; i < L; i++)
				M[i] = {{P[lvl-1][i], i+skip<L ? P[lvl-1][i + skip] : -1000}, i};
			sort(M.begin(), M.end());
			for (int i = 0; i < L; i++)
				P[lvl][M[i].second] = (i > 0 && M[i].first == M[i-1].first) ?
					P[lvl][M[i-1].second] : i;
		}
	}
	const vi& get_sarray() { return P.back(); }
	//returns len of longest common prefix of s[i...L-1] and s[j...L-1], O(lg L)
	int lcp(int i, int j) {
		int len = 0; if (i == j) return L - i;
		for (int k = P.size() - 1; k >= 0 && i < L && j < L; k--)
			if (P[k][i] == P[k][j]) { i += 1 << k; j += 1 << k; len += 1 << k; }
		return len;
	}
};

const int OFFSET = 5e5+2;
const int N = 5e5+4;
const int L = 19;

int rmq[N][L];
void build(int n) {
	for (int j = 1; j < L; j++)
		for (int i = 0; i+(1<<j)-1 < n; i++)
			rmq[i][j] = min(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
}
int query(int l, int r) {
	if (l > r) swap(l, r);
	int j = 31 - __builtin_clz(r-l+1);
	return min(rmq[l][j], rmq[r-(1<<j)+1][j]);
}

int val[2*N];
vector<int> cnt[2*N];

int find_left(int n, const vi& v, int s) {
	int left, right, mid;
	left = 0;
	right = v.size()-1;
	while (left <= right) {
		mid = (left+right)/2;
		if (v[mid] <= s) left = mid+1;
		else right = mid-1;
	}
	if (v[mid] <= s) mid++;
	return mid;
}

int find_right(int n, const vi& v, const vi& u, int s) {
	int left, right, mid;
	left = 0;
	right = u.size()-1;
	while (left <= right) {
		mid = (left+right)/2;
		if (u[mid] < s) left = mid+1;
		else right = mid-1;
	}
	if (u[mid] < s) mid++;

	int goal = u[mid]-1;
	left = 0;
	right = v.size()-1;
	while (left <= right) {
		mid = (left+right)/2;
		if (v[mid] > goal) right = mid-1;
		else left = mid+1;
	}
	if (v[mid] > goal) mid--;
	return mid;
}

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n;
	cin >> n;

	string s;
	cin >> s;

	val[0] = OFFSET;
	cnt[val[0]].push_back(0);
	for (int i=1; i<=n; i++) {
		if (s[i-1] == '(') val[i] = val[i-1] + 1;
		else val[i] = val[i-1] - 1;
		cnt[val[i]].push_back(i);
	}
	for (int i=0; i<N; i++) {
		cnt[i].push_back(INF);
	}

	suff_array sa(s);
	const auto& idx = sa.get_sarray();
	vector<int> reidx(n);
	for (int i=0; i<n; i++) {
	   reidx[idx[i]] = i;
	}

	ll ans = 0;
	set<int> seen;
	for (int i=0; i<n; i++) {
		int minpre = 0;
		auto it = seen.lower_bound(idx[i]);
		if (it != seen.end()) {
			minpre = max(minpre, sa.lcp(i, reidx[*it]));
		}
		if (it != seen.begin()) {
			minpre = max(minpre, sa.lcp(i, reidx[*prev(it)]));
		}
		seen.insert(idx[i]);

		int h = val[i];
		//int left = find_left(n, cnt[h], i+minpre);
		//int right = find_right(n, cnt[h], cnt[h-1], i);
		//cerr << i << ',' << minpre << ": " << left << " " << right << " -> " << right-left+1 << nl;
		//ans += max(0, right-left+1);
		int left = upper_bound(cnt[h].begin(), cnt[h].end(), i+minpre) - cnt[h].begin();
		int value = (*lower_bound(cnt[h-1].begin(), cnt[h-1].end(), i)) - 1;
		int right = upper_bound(cnt[h].begin(), cnt[h].end(), value) - cnt[h].begin();
		//cerr << i << ',' << minpre << ": " << left << " " << right << " -> " << right-left << nl;
		ans += max(0, right-left);
	}

	cout << ans << nl;

	return 0;
}