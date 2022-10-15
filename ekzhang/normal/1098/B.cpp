#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 300013
int N, M;
string S[MAXN];
string ST[MAXN];

int ans = MAXN;
vector<int> inv;
int anstyp = -1;
bool ansneg;

string alpha = "ACGT";
string c2[] = {"AC", "AG", "AT", "CG", "CT", "GT"};
string cc2[] = {"GT", "CT", "CG", "AT", "AG", "AC"};

void solve(string* A, int typ, bool neg) {
	vector<int> curinv(N);
	int curans = 0;
	for (int i = 0; i < N; i++) {
		string p = (i % 2 ? cc2[typ] : c2[typ]);
		int a = 0, b = 0;
		for (int j = 0; j < M; j++) {
			if (A[i][j] != p[j % 2])
				++a;
			if (A[i][j] != p[1 - j % 2])
				++b;
		}
		curinv[i] = (b < a);
		curans += min(a, b);
	}
	if (curans < ans) {
		ans = curans;
		inv = curinv;
		anstyp = typ;
		ansneg = neg;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> S[i];

	for (int i = 0; i < M; i++) {
		ST[i] = string(N, ' ');
		for (int j = 0; j < N; j++)
			ST[i][j] = S[j][i];
	}

	for (int typ = 0; typ < 6; typ++) {
		solve(S, typ, 0);
	}

	swap(N, M);
	for (int typ = 0; typ < 6; typ++) {
		solve(ST, typ, 1);
	}
	swap(N, M);

	if (ansneg) {
		swap(N, M);
		swap(S, ST);
	}

	// do
	assert(anstyp != -1);
	for (int i = 0; i < N; i++) {
		string p = (i % 2 ? cc2[anstyp] : c2[anstyp]);
		if (inv[i])
			swap(p[0], p[1]);
		for (int j = 0; j < M; j++) {
			S[i][j] = p[j % 2];
		}
	}

	if (ansneg) {
		for (int j = 0; j < M; j++) {
			for (int i = 0; i < N; i++) {
				cout << S[i][j];
			}
			cout << '\n';
		}
	}
	else {
		for (int i = 0; i < N; i++)
			cout << S[i] << '\n';
	}

	cout.flush();
	return 0;
}