#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 1000013
int N;
int A[MAXN], B[MAXN];
string op[MAXN];
bool val[MAXN];
int ans[MAXN];

bool apply(bool a, bool b, string op) {
	if (op[0] == 'A')
		return a & b;
	else if (op[0] == 'O')
		return a | b;
	else if (op[0] == 'X')
		return a ^ b;
	else if (op[0] == 'N')
		return !a;
	else
		throw domain_error("wtf?");
}

int dfs(int n) {
	if (op[n] == "IN")
		return val[n] = A[n];
	int a = dfs(A[n]);
	int b;
	if (B[n] != -1) {
		b = dfs(B[n]);
	}
	return val[n] = apply(a, b, op[n]);
}

void go(int n, bool d=1) {
	char c = op[n][0];
	if (c == 'I') {
		ans[n] = d;
	}
	if (c == 'N') {
		go(A[n], d);
	}
	if (c == 'X') {
		go(A[n], d);
		go(B[n], d);
	}
	if (c == 'A') {
		go(A[n], d && val[B[n]]);
		go(B[n], d && val[A[n]]);
	}
	if (c == 'O') {
		go(A[n], d && !val[B[n]]);
		go(B[n], d && !val[A[n]]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	memset(B, -1, sizeof B);
	for (int i = 0; i < N; i++) {
		cin >> op[i] >> A[i];
		if (op[i] != "IN") {
			--A[i];
			if (op[i] != "NOT") {
				cin >> B[i];
				--B[i];
			}
		}
	}

	dfs(0);

	memset(ans, -1, sizeof ans);
	go(0);

	for (int i = 0; i < N; i++) {
		if (~ans[i])
			cout << (val[0] ^ ans[i]);
	}

	cout << endl;
	return 0;
}