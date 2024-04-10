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

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	set<int> A;	
	rep(i,0,n) {
		cin >> a[i];
		A.insert(a[i]);
	}
	int mex = 0;
	int missing = 0;
	rep(i,0,n) {
		if (A.count(i)) {
		} else {
			if (missing == k) {
				mex = i;
				break;
			} else {
				A.insert(i);
				a.push_back(i);
			}
			++missing;
		}
		mex = i+1;
	}
	map<int, int> M;	
	rep(i,0,n) {
		if (a[i] >= mex) {
			M[a[i]]++;
		}
	}
	vector<pair<int, int>> p;
	for (auto it : M) {
		p.emplace_back(it.second, it.first);
	}
	sort(all(p));
	int diff=0;
	int remove_left=k;
	for (auto it : p) {
		if (it.first <= remove_left) {
			remove_left -= it.first;
			A.erase(it.second);
		}
	}
	int ans = sz(A) - mex;
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