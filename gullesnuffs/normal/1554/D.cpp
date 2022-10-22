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

void check(string s) {
	cerr << sz(s) << " " << s << endl;
	map<string, int> cnt;
	rep(i,0,sz(s)) {
	string t;
	rep(j,i,sz(s)) {
		assert(s[j] <= 'z');
		t.push_back(s[j]);
		cnt[t]++;
	}
	}
	for (auto it : cnt) {
		if(it.second%2 != 1) {
			cerr << it.first << " " << it.second << endl;
			assert(0);
		}
	}
}

string rec(int n, char c) {
	//cerr << "rec " << n << " " << c << endl;
	char d = c+1;
	string C;
	C.push_back(c);
	string D;
	D.push_back(d);
	if (n%3 == 0 && n >= 9) {
		string S = rec((n-6)/3, c+2);
		return S + C + C + S + D + C + D + D + S;
	}
	if (n%3 == 1 && n >= 13) {
		string S = rec((n-10)/3, c+2);
		return S + C + C + C + S + D + D + C + C + D + D + D + S;
	}
	if (n%3 == 2 && n >= 5) {
		string S = rec((n-2)/3, c+2);
		return S + C + S + D + S;
	}
	string E;
	E.push_back(c+2);
	string F;
	F.push_back(c+3);
	if (n == 10) {
		return C + C + C + D + C + C + E + D + F + D;
	}
	if (n == 7) {
		return C + C + C + D + C + C + E;
	}
	if (n == 6) {
		return C + C + C + D + C + C;
	}
	string ret;
	while (sz(ret) < n) {
		ret.push_back(c++);
	}
	return ret;
}

void solve() {
	int n;
	cin >> n;
	cout << rec(n, 'a') << endl;

}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	/*rep(n,1,10000) {
		string res = rec(n, 'a');
		assert(sz(res) == n);
		check(rec(n, 'a'));
	}*/
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}