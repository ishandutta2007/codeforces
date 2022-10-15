#include <bits/stdc++.h>
using namespace std;

#define error(arg...){vector<string>_v=split(#arg,',');err(_v.begin(),arg);}
vector<string> split(const string& s,char c){vector<string> v;stringstream ss(s);
string x;while(getline(ss,x,c))v.push_back(move(x));return v;}
void err(vector<string>::iterator it){}template<typename T,typename...Args>
void err(vector<string>::iterator it,T a, Args... args){cerr<<it->
substr((*it)[0]==' ',it->length())<<" = "<<a<<'\n';err(++it, args...);}

typedef long long LL;
const double PI = 4 * atan(1);

#define MOD 1000000007
#define MAXN 313
int N;
int A[MAXN];
int group[MAXN], numgroups;
LL dp[MAXN][MAXN];
LL nckm[MAXN][MAXN];
int ct[MAXN];

bool isSquare(LL x) {
	LL d = sqrt(x);
	while (d * d < x) ++d;
	while (d * d > x) --d;
	return d * d == x;
}

LL mpow(LL x, LL p) {
	if (p == 0) return 1;
	LL res = mpow(x, p / 2);
	res = (res * res) % MOD;
	if (p % 2) res = (res * x) % MOD;
	return res;
}

LL modinv(LL x) {
	return mpow(x, MOD - 2);
}

LL nck(LL n, LL k) {
	if (n < 0 || k < 0 || k > n) return 0;
	if (~nckm[n][k]) return nckm[n][k];
	LL ans = 1;
	nckm[n][0] = 1;
	for (int i = 1; i <= n; i++) {
		ans = (ans * (n - i + 1)) % MOD;
		ans = (ans * modinv(i)) % MOD;
		nckm[n][i] = ans;
	}
	return nckm[n][k];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	memset(nckm, -1, sizeof nckm);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		group[i] = -1;
		for (int j = 0; j < i; j++) {
			LL x = A[j];
			x *= A[i];
			if (isSquare(x)) {
				group[i] = group[j];
				break;
			}
		}
		if (group[i] == -1) {
			group[i] = numgroups++;
		}
		ct[group[i]]++;
	}

	dp[0][0] = 1;
	int len = 0;
	for (int i = 0; i < numgroups; i++) {
		// error(ct[i]);
		LL fac = 1;
		for (int x = 1; x <= ct[i]; x++) {
			fac = (fac * x) % MOD;
		}
		for (int j = 0; j < len + ct[i]; j++) {
			for (int m = 0; m < ct[i]; m++) {
				for (int k = 0; k <= len; k++) {
					LL amt = dp[i][k];
					amt = (amt * nck(k, m + k - j)) % MOD;
					amt = (amt * nck(ct[i] - 1, m)) % MOD;
					amt = (amt * nck(len + 1 - k, ct[i] - 2 * m - k + j)) % MOD;
					amt = (amt * fac) % MOD;
					dp[i + 1][j] = (dp[i + 1][j] + amt) % MOD;
				}
			}
		}
		len += ct[i];
	}

	cout << dp[numgroups][0] << endl;
	return 0;
}