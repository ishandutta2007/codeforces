#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
#define MAXN 113
#define MOD 1000000007
int N;
LL K;
LL A[MAXN], B[MAXN];
int C[MAXN];

typedef LL** matrix;

matrix zeros(int r, int c) {
	matrix m = new LL*[r];
	for (int i = 0; i < r; i++) {
		m[i] = new LL[c]();
	}
	return m;
}

matrix identity(int r) {
	matrix m = zeros(r, r);
	for (int i = 0; i < r; i++) {
		m[i][i] = 1;
	}
	return m;
}

matrix multiply(matrix a, matrix b, bool del=true) {
	matrix c = zeros(16, 16);
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			for (int k = 0; k < 16; k++) {
				c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}
	if (del) {
		delete[] a;
		delete[] b;
	}
	return c;
}

matrix mpow(matrix m, LL p) {
	matrix A[62];
	A[0] = m;
	for (int i = 0; i < 61; i++) {
		A[i + 1] = multiply(A[i], A[i], false);
	}
	matrix ret = identity(16);
	for (int i = 0; i < 62; i++) {
		if ((1LL<<i) & p) {
			ret = multiply(ret, A[i]);
		}
		else {
			delete[] A[i];
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i] >> C[i];
		if (B[i] >= K) {
			B[i] = K;
		}
	}

	matrix ans = identity(16);
	for (int i = 0; i < N; i++) {
		matrix m = identity(16);
		for (int j = 0; j < 16; j++) {
			if (j) m[j][j-1] = 1;
			if (j < 15) m[j][j+1] = 1;
		}
		for (int j = C[i] + 1; j < 16; j++) {
			for (int k = 0; k < 16; k++) {
				m[j][k] = 0;
			}
		}
		for (int j = 0; j < 16; j++) {
			for (int k = C[i] + 1; k < 16; k++) {
				m[j][k] = 0;
			}
		}
		m = mpow(m, B[i] - A[i]);
		ans = multiply(ans, m);
	}

	cout << ans[0][0] << endl;
	return 0;
}