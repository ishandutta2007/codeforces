#include<bits/stdc++.h>
using namespace std;

const int MAXV = 4e5;
const int V = 3.1e5;
int pfac[MAXV];
int sqfree[MAXV];
bool has[MAXV];

void precomp() {
	for (int i = 1; i <= V; i++) sqfree[i] = i;
	for (int p = 2; p <= V; p++) {
		if (pfac[p] != 0) continue;
		for (int j = p; j <= V; j += p) {
			pfac[j] = p;
			while (sqfree[j] / p % p == 0) {
				sqfree[j] /= p;
			}
		}
	}
}

int numMul[MAXV];

const int MAXN = 4e5;
int N;
int A[MAXN];

int myCnt[MAXV];
int dp[MAXV];

int go() {
	precomp();
	for (int i = 0; i < N; i++) {
		A[i] = sqfree[A[i]];
	}
	sort(A, A + N);
	N = int(unique(A, A + N) - A);
	assert(N);

	int g = A[0];
	for (int i = 1; i < N; i++) {
		g = __gcd(A[i], g);
	}
	if (g != 1) {
		return -1;
	}

	for (int i = 0; i < N; i++) {
		if (A[i] == 1) return 1;
	}

	for (int i = 0; i < N; i++) {
		has[A[i]] = true;
	}

	for (int v = 1; v <= V; v++) {
		for (int j = v; j <= V; j += v) {
			numMul[v] += has[j];
		}
	}

	int res = N;

	for (int i = 0; i < N; i++) {
		vector<int> pfacs;
		for (int v = A[i]; v > 1; ) {
			int p = pfac[v];
			pfacs.push_back(p);
			v /= p;
			assert(v % p != 0);
		}
		vector<int> facs;
		for (int m = 0; m < (1 << int(pfacs.size())); m++) {
			int fac = 1;
			for (int z = 0; z < int(pfacs.size()); z++) {
				if (m & (1 << z)) {
					fac *= pfacs[z];
				}
			}
			facs.push_back(fac);
		}
		//cerr << "Running " << A[i] << '\n';
		for (int fac : facs) {
			myCnt[fac] = numMul[fac];
		}
		for (int p : pfacs) {
			for (int fac : facs) {
				if (fac % p == 0) {
					myCnt[fac / p] -= myCnt[fac];
				}
			}
		}
		// now myCnt the list of GCD things
		vector<int> vals;
		for (int m = 0; m < int(facs.size()); m++) {
			//cerr << facs[m] << ' ' << myCnt[facs[m]] << '\n';
			assert(myCnt[facs[m]] >= 0);
			if (myCnt[facs[m]]) {
				vals.push_back(m);
			}
			dp[m] = -1;
		}
		//cerr << '\n';
		queue<int> q;
		dp[int(facs.size())-1] = 1;
		q.push(int(facs.size()) - 1);
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			assert(dp[cur] != -1);
			for (int v : vals) {
				int nxt = cur & v;
				if (dp[nxt] != -1) {
					continue;
				}
				dp[nxt] = dp[cur]+1;
				q.push(nxt);
			}
		}
		res = min(res, dp[0]);
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cout << go() << '\n';
	return 0;
}