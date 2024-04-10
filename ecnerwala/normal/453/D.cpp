#include<bits/stdc++.h>

using namespace std;


typedef long long ll;

typedef vector<ll> vl;

const int MAXM = 25;

int M;
ll T, P;
vl B;

ll choose[MAXM][MAXM];

vl bSum(const vl &A, const vl &B) {
	vl res;
	for(int k = 0; k <= M; k++) {
		ll val = 0;
		for(int i = 0; i <= M; i++) {
			for(int j = 0; j <= M; j++) {
				if(i + j < k) continue;
				int a = i + j - k;
				if(a % 2 != 0) continue;
				a /= 2;
				if(i < a || j < a) continue;
				if(a > M - k) continue;

				ll v = A[i] * B[j] % P;
				v *= choose[k][i - a]; // choose[k][i - a] = choose[k][j - a]
				v %= P;
				v *= choose[M - k][a];
				v %= P;

				val += v;
				if(val >= P) val -= P;
			}
		}
		res.push_back(val);
	}
	return res;
}

vl exp(vl a, ll e) {
	vl r;
	r.push_back(1);
	for(int i = 1; i <= M; i++) r.push_back(0);

	while(e) {
		if(e % 2) r = bSum(r, a);
		e /= 2;
		a = bSum(a, a);
	}

	return r;
}

const int MAXN = (1 << 20) + 200;
int N;
int E[MAXN];

int dp[MAXN][MAXM]; // sum of those with prefix dist exactly i away
int ndp[MAXN][MAXM];

int main() {
	cin >> M >> T >> P;
	for(int i = 0; i <= M; i ++) {
		choose[i][0] = choose[i][i] = 1;
		for(int j = 1; j < i; j++) {
			choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
			if(choose[i][j] >= P) choose[i][j] -= P;
		}
	}

	N = 1 << M;

	for(int i = 0; i < N; i++) {
		cin >> E[i];
		E[i] %= P;
	}

	for(int i = 0; i <= M; i++) {
		ll v;
		cin >> v;
		v %= P;
		B.push_back(v);
	}

	B = exp(B, T);

	//for(int i = 0; i <= M; i++) cerr << B[i] << ' '; cerr << '\n';

	for(int i = 0; i < N; i++) {
		dp[i][0] = E[i];
		for(int j = 1; j <= M; j++) {
			dp[i][j] = 0;
		}
	}

	for(int d = 0; d < M; d++) {
		//i is the index to check
		for(int i = 0; i < N; i++) {
			for(int l = 0; l <= d; l++) {
				ndp[i][l] = dp[i][l];
			}
			ndp[i][d + 1] = 0;
			for(int l = 1; l <= d + 1; l++) {
				ndp[i][l] += dp[i ^ (1 << d)][l - 1];
				if(ndp[i][l] >= P) ndp[i][l] -= P;
			}
		}
		for(int i = 0; i < N; i++) {
			for(int l = 0; l <= d + 1; l++) {
				dp[i][l] = ndp[i][l];
			}
		}
	}

	for(int i = 0; i < N; i++) {
		ll v = 0;
		for(int l = 0; l <= M; l++) {
			v += B[l] * dp[i][l];
			v %= P;
		}
		cout << v << '\n';
	}

	return 0;
}