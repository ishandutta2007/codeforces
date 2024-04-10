#include <bits/stdc++.h>
#define eb emplace_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
using namespace std;
typedef long long ll;
int atoi(char c) {
	if('a' <= c && c <= 'z') return c-'a';
	if('A' <= c && c <= 'Z') return c-'A'+26;
	return (c&15) + 52;
}

const int MOD = 998244353;
const int K = 62;

unordered_set<string> MP;
int B[62][62][62];
int A[11][62][62];

int N, Ans;

void solve(int l) {
	for(int a = 0; a < K; a++) for(int b = a; b < K; b++) for(int c = b; c < K; c++) {
		int r = 0;
		for(int d = 0; d < K; d++) {
			r += ll(A[l][a][d]) * A[l][b][d] % MOD * A[l][c][d] % MOD;
			if(MOD <= r) r -= MOD;
		}
		B[a][b][c] = B[a][c][b] = B[b][a][c] = B[b][c][a] = B[c][a][b] = B[c][b][a] = r;
	}
	for(int a = 0; a < K; a++) for(int b = a; b < K; b++) for(int c = b; c < K; c++) for(int d = c; d < K; d++) {
		int t = ll(B[a][b][c]) * B[a][b][d] % MOD * B[a][c][d] % MOD * B[b][c][d] % MOD;
		if(a == d);
		else if(a == c || b == d) t = (ll(t)<<2) % MOD;
		else if(a == b && c == d) t = ll(t)*6 % MOD;
		else if(a == b || b == c || c == d) t = ll(t)*12 % MOD;
		else t = ll(t)*24 % MOD;
		Ans += t;
		if(MOD <= Ans) Ans -= MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for(string s; N--;) {
		cin >> s;
		MP.insert(s);
		reverse(allv(s));
		MP.insert(s);
	}
	for(auto &v : MP) A[sz(v)][atoi(v[0])][atoi(v.back())]++;
	for(int i = 3; i < 11; i++) solve(i);
	cout << Ans << endl;
	return 0;
}