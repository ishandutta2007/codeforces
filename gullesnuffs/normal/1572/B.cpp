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

void perform_move(vector<bool>& a, vector<int>& b, int i) {
	b.push_back(i+1);
	int x = a[i] ^ a[i+1] ^ a[i+2];
	a[i] = x;
	a[i+1] = x;
	a[i+2] = x;
	/*for (int x : a)
		cerr << x;
	cerr << endl;*/
}

int get_sum(vector<bool>& a, int i) {
	return a[i] + a[i+1] + a[i+2];
}

void solve(vector<bool> a) {
	vector<int> b;
	int sum = 0;
	int n = sz(a);
	rep(i,0,n)
		sum += a[i];
	if (sum%2) {
		cout << "NO" << endl;
		return;
	}
	bool is_ok = false;
	if (n%2)
		is_ok = true;
	else if (!a[0])
		is_ok = true;
	else if (!a[n-1])
		is_ok = true;
	else {
		rep(i,0,n-1) {
			if (i%2 == 1 && a[i] != a[i+1])
				is_ok = true;
		}
	}
	if (!is_ok) {
		cout << "NO" << endl;
		return;
	}

	if (a[0]) {
		rep(i,0,n-1) {
			if (i%2 == 0)
				continue;
			if (a[i] != a[i+1]) {
				rrep(j,i,0) {
					if (j%2 == 0 && get_sum(a, j)%2 != a[j]) {
						perform_move(a, b, j);
					}
				}
				break;
			}
		}
	}
	int last_one = 0;
	rep(i,0,n)
		if (a[i])
			last_one = i;
	assert(!a[0]);
	rep(i,1,n-2) {
		if (a[i]) {
			if (get_sum(a, i) == 2) {
				perform_move(a, b, i);
				continue;
			}
			if (get_sum(a, i-1) == 2) {
				perform_move(a, b, i-1);
				continue;
			}
			rrep(j,n-2,i) {
				if (get_sum(a, j) == 1) {
					if (get_sum(a, j) == 1 && j+2 > last_one)
						continue;
					perform_move(a, b, j);
				}
			}
			if (get_sum(a, i-1) == 2)
				perform_move(a, b, i-1);
			if (get_sum(a, i) == 2)
				perform_move(a, b, i);
			assert(!a[i]);
		}
	}
	rep(i,0,n-2)
		if (get_sum(a, i) == 2)
			perform_move(a, b, i);


	/*int last_one = 0;
	rep(i,0,n)
		if (a[i])
			last_one = i;
	if (a[0] == 1 && (a[1]+a[2] == 1)) {
		perform_move(a, b, 0);
	}
	if (a[n-1] == 1 && (a[n-2]+a[n-3] == 1))
		perform_move(a, b, n-3);
	rep(i,0,n-1) {
		if (i%2 == 1 && a[i] != a[i+1]) {
			rrep(j,i,1) {
				if (j%2 == 0 && get_sum(a, j)%2 != a[j] && a[j] != a[j^1]) {
					perform_move(a, b, j);
				}
			}
			break;
		}
	}
	rep(i,0,n-2) {
		if (get_sum(a, i) == 2)
			perform_move(a, b, i);
	}
	rep(i,0,n-2) {
		if (get_sum(a, i) == 1 && a[i])
			perform_move(a, b, i);
	}
	rrep(i,n-2,0) {
		if (get_sum(a, i) == 2)
			perform_move(a, b, i);
	}
	rep(i,0,n-2) {
		if (get_sum(a, i) == 2)
			perform_move(a, b, i);
	}*/
	/*rep(i,0,n-2) {
		string s;
		rep(j,0,3) {
			s.push_back('0' + a[i+j]);
		}
		if (a[i] + a[i+1] + a[i+2] != 2)
			continue;
		if (!a[i+1] && i%2)
			continue;
		int x = a[i] ^ a[i+1] ^ a[i+2];
		a[i] = x;
		a[i+1] = x;
		a[i+2] = x;
		b.push_back(i+1);
	}*/
	/*rep(i,0,n-2) {
		string s;
		rep(j,0,3) {
			s.push_back('0' + a[i+j]);
		}
		if (a[i] + a[i+1] + a[i+2] != 1)
			continue;
		if (!a[i])
			continue;
		if (last_one <= i+1)
			continue;
		int x = a[i] ^ a[i+1] ^ a[i+2];
		a[i] = x;
		a[i+1] = x;
		a[i+2] = x;
		b.push_back(i+1);
	}
	rrep(i,n-2,0) {
		string s;
		rep(j,0,3) {
			s.push_back('0' + a[i+j]);
		}
		int x = a[i] ^ a[i+1] ^ a[i+2];
		if (a[i] + a[i+1] + a[i+2] != 2)
			continue;
		a[i] = x;
		a[i+1] = x;
		a[i+2] = x;
		b.push_back(i+1);
	}
	rep(i,0,n-2) {
		string s;
		rep(j,0,3) {
			s.push_back('0' + a[i+j]);
		}
		if (a[i] + a[i+1] + a[i+2] != 2)
			continue;
		int x = a[i] ^ a[i+1] ^ a[i+2];
		a[i] = x;
		a[i+1] = x;
		a[i+2] = x;
		b.push_back(i+1);
	}*/
	assert(sz(b) <= n);
	cout << "YES" << endl;
	cout << sz(b) << endl;
	if (sz(b) > 0) {
		for (int x : b)
			cout << x << " ";
		cout << endl;
	}
	rep(i,0,n) {
		assert(!a[i]);
	}
}

void solve() {
	int n;
	cin >> n;
	vector<bool> a(n);
	rep(i,0,n) {
		int x;
		cin >> x;
		a[i] = x;
	}
	solve(a);
}

int main() {
	/*rep(n,3,20) {
		rep(i,0,(1<<n)) {
			vector<bool> b(n);
			rep(j,0,n)
				b[j] = (i&(1<<j)) != 0;*/
			/*for (int x : b)
				cerr << x;
			cerr << endl;*/
			/*solve(b);
		}
	}*/
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}