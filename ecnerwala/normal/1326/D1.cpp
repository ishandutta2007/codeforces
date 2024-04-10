#include<bits/stdc++.h>
using namespace std;

// https://github.com/kth-competitive-programming/kactl/blob/master/content/strings/Manacher.h
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
array<vi, 2> manacher(const string& s) {
	int n = sz(s);
	array<vi,2> p = {vi(n+1), vi(n)};
	rep(z,0,2) for (int i=0,l=0,r=0; i < n; i++) {
		int t = r-i+!z;
		if (i<r) p[z][i] = min(t, p[z][l+t]);
		int L = i-p[z][i], R = i+p[z][i]-!z;
		while (L>=1 && R+1<n && s[L-1] == s[R+1])
			p[z][i]++, L--, R++;
		if (R>r) l=L, r=R;
	}
	return p;
}

string solveMid(string S) {
	if (S.empty()) return "";

	int N = int(S.size());

	int ans = 0;
	auto man = manacher(S);
	for (int k = 0; k <= 2 * N; k++) {
		int len = man[k%2][k/2]*2+k%2;
		if (len >= k || len >= 2*N-k) {
			ans = max(ans, len);
		}
	}
	for (int k = 0; k <= 2 * N; k++) {
		int len = man[k%2][k/2]*2+k%2;
		if (len == ans) {
			if (len >= k) {
				return string(S.begin(), S.begin() + len);
			} else if (len >= 2*N-k) {
				return string(S.end() - len, S.end());
			}
		}
	}
	assert(ans == 0);
	return "";
}

string solve(string S) {
	int i = 0, j = int(S.size())-1;
	while (i < j && S[i] == S[j]) i++, j--;
	return string(S.begin(), S.begin() + i) + solveMid(string(S.begin() + i, S.begin() + j+1)) + string(S.begin() + j+1, S.end());
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--) {
		string S; cin >> S;
		string ans = solve(S);
		cout << ans << '\n';
	}

	return 0;
}