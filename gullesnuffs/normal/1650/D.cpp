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
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,0,n) {
		cin >> a[i];
		--a[i];
	}
	vector<int> ans;
	rrep(i,n,0) {
		int cur_pos = -1;
		rep(j,0,i+1) {
			if (a[j] == i) {
				cur_pos = j;
				break;
			}
		}
		assert(cur_pos != -1);
		int shifts = (cur_pos+1)%(i+1);
		vector<int> b = a;
		rep(j,0,i+1) {
			b[j] = a[(j+shifts)%(i+1)];
		}
		a = b;
		ans.push_back(shifts);
	}
	reverse(all(ans));
	for (int x : ans)
		cout << x << " ";
	cout << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}