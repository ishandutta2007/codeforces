#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void swap_columns(vector<vector<int>>& A, int j1, int j2) {
	rep(i,0,sz(A)) {
		swap(A[i][j1], A[i][j2]);
	}
}

bool check_ok(const vector<vector<int>>& A) {
	rep(i,0,sz(A)) {
		rep(j,0,sz(A[i])-1) {
			if (A[i][j] > A[i][j+1])
				return false;
		}
	}
	return true;
}

void solve() {
	int n, m;
	cin >> n >> m;
	set<int> bad_positions;
	set<int> swap_with;
	vector<vector<int>> A;
	rep(i,0,n) {
		vector<int> a(m);
		rep(j,0,m) {
			cin >> a[j];
		}
		A.push_back(a);
		rep(j,0,m-1) {
			if (a[j] > a[j+1]) {
				bad_positions.insert(j);
				bad_positions.insert(j+1);
				int k = j+1;
				while (k < m && a[k] == a[j+1]) {
					++k;
				}
				if (sz(swap_with) < 4) {
					swap_with.insert(k-1);
				}
				k = j;
				while (k >= 0 && a[k] == a[j]) {
					--k;
				}
				if (sz(swap_with) < 4) {
					swap_with.insert(k+1);
				}
			}
		}
	}
	if (sz(bad_positions) == 0) {
		cout << "1 1" << endl;
		return;
	}
	if (sz(bad_positions) >= 6) {
		cout << "-1" << endl;
		return;
	}
	for (int s : swap_with) {
		bad_positions.insert(s);
	}
	for (int b1 : bad_positions)
		for (int b2 : bad_positions) {
			swap_columns(A, b1, b2);
			if (check_ok(A)) {
				cout << b1+1 << " " << b2+1 << endl;
				return;
			}
			swap_columns(A, b1, b2);
		}
	cout << "-1" << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}