#include<bits/stdc++.h>

/**
 * manacher(S): return the maximum palindromic substring of S centered at each point
 *
 * Input: string (or vector) of length N (no restrictions on character-set)
 * Output: vector res of length 2*N+1
 *   For any 0 <= i <= 2*N:
 *   * i % 2 == res[i] % 2
 *   * the half-open substring S[(i-res[i])/2, (i+res[i])/2) is a palindrome of length res[i]
 *   * For odd palindromes, take odd i, and vice versa
 */
/*
template <typename V> std::vector<int> manacher(const V& S) {
	int N = int(S.size());
	std::vector<int> res(2*N+1, 0);
	for (int i = 1, j = -1, r = 0; i < 2*N; i++, j--) {
		if (i > r) {
			r = i+1, res[i] = 1;
		} else {
			res[i] = res[j];
		}
		if (i+res[i] >= r) {
			int b = r>>1, a = i-b;
			while (a > 0 && b < N && S[a-1] == S[b]) {
				a--, b++;
			}
			res[i] = b-a, j = i, r = b<<1;
		}
	}
	return res;
}
*/

template <typename V> std::vector<int> manacher_odd(const V& S) {
	int N = int(S.size());
	std::vector<int> res(N);
	for (int i = 1, j = -1, r = 0; i < N; i++, j--) {
		if (i > r) {
			r = i, res[i] = 0;
		} else {
			res[i] = res[j];
		}
		if (i+res[i] >= r) {
			int b = r, a = 2*i-r;
			while (a-1 >= 0 && b+1 < N && S[a-1] == S[b+1]) {
				a--, b++;
			}
			res[i] = b-i, j = i, r = b;
		}
	}
	return res;
}
template <typename V> std::vector<int> manacher(const V& S) {
	int N = int(S.size());
	std::vector<char> S2(2*N+1);
	for (int i = 0; i < N; i++) S2[2*i+1] = S[i];
	return manacher_odd(S2);
}

using namespace std;

// https://github.com/kth-competitive-programming/kactl/blob/master/content/strings/Manacher.h
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
array<vi, 2> kactl_manacher(const string& s) {
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

vector<int> test_manacher(string s) {
	auto v = manacher(s);
	auto m = kactl_manacher(s);
	for (int k = 0; k <= 2 * int(s.size()); k++) {
		assert(m[k%2][k/2] * 2 + k%2 == v[k]);
	}
	return v;
}

string solveMid(string S) {
	if (S.empty()) return "";

	int N = int(S.size());

	int ans = 0;
	auto man = test_manacher(S);
	for (int k = 0; k <= 2 * N; k++) {
		int len = man[k];
		if (len >= k || len >= 2*N-k) {
			ans = max(ans, len);
		}
	}
	for (int k = 0; k <= 2 * N; k++) {
		int len = man[k];
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
	test_manacher(S);
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