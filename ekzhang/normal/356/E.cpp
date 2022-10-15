#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;

#define MAXN 100013
#define MOD 1000000007
int N;
string ss;
int s[MAXN];
LL hsh[MAXN];
LL ppow[MAXN];
int ct[MAXN][26];
int A[MAXN];
LL B[MAXN];
LL total;

inline LL h(int i, int j) {
	// polynomial hash from i (inclusive) to j (exclusive)
	return (1LL * MOD * MOD + hsh[j] - hsh[i] * ppow[j - i]) % MOD;
}

inline int has(int i, int j, int c) {
	// substring from i (inclusive) to j (exclusive) contains c how many times?
	return ct[j][c] - ct[i][c];
}

LL dfs(int i, int part, LL phash, int z) {
	int half = (part + 1) / 2;
	if (i < 0 || i >= N || i < part || N - 1 - i < part) {
		return 0;
	}
	if (z == 0) {
		if (has(i - part, i, s[i])) {
			return 0;
		}
		if (h(i - part, i) != phash) {
			return 0;
		}
		if (A[i - half] < part) {
			return 0;
		}
	}
	else {
		if (has(i + 1, i + 1 + part, s[i])) {
			return 0;
		}
		if (h(i + 1, i + 1 + part) != phash) {
			return 0;
		}
		if (A[i + half] < part) {
			return 0;
		}
	}
	LL ret = 1LL * (2 * part + 1) * (2 * part + 1);
	LL phash2 = (phash + s[i] * ppow[part] + phash * ppow[part + 1]) % MOD;
	ret += dfs(i - part - 1, 2 * part + 1, phash2, 0);
	ret += dfs(i + part + 1, 2 * part + 1, phash2, 1);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> ss;
	N = ss.size();

	for (int i = 0; i < N; i++) {
		s[i] = ss[i] - 'a';
	}

	ppow[0] = 1;
	for (int i = 0; i < N; i++) {
		// string polynomial hash on prefixes; 37 is prime and bigger than 26
		hsh[i + 1] = (hsh[i] * 37) + s[i];
		hsh[i + 1] %= MOD;
		ppow[i + 1] = (ppow[i] * 37) % MOD;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 26; j++) {
			ct[i + 1][j] = ct[i][j];
		}
		ct[i + 1][s[i]]++;
	}

	total = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0;; j++) {
			int part = (1<<j) - 1;
			int half = (part + 1) / 2;
			if (i < part || N - 1 - i < part) {
				break;
			}
			if (has(i - part, i + part + 1, s[i]) > 1) {
				break;
			}
			if (h(i - part, i) != h(i + 1, i + part + 1)) {
				break;
			}
			if (A[i - half] < part) {
				break;
			}
			A[i] = 2 * part + 1;
			total += (1LL * A[i] * A[i]);
			B[i - A[i] / 2] += (1LL * A[i] * A[i]);
			B[i + A[i] / 2 + 1] -= (1LL * A[i] * A[i]);
		}
	}
	for (int i = 1; i < N; i++) {
		B[i] += B[i - 1];
	}

	LL ans = total;
	for (int i = 0; i < N; i++) {
		for (int c = 0; c < 26; c++) {
			// change character i to equal c
			LL cur = total - B[i];
			int before = s[i];
			s[i] = c;
			for (int j = 0;; j++) {
				int part = (1<<j) - 1;
				LL result = dfs(i, part, h(i - part, i), 1);
				cur += result;
				if (!result) break;
			}
			s[i] = before;
			ans = max(ans, cur);
		}
	}

	cout << ans << endl;
	return 0;
}