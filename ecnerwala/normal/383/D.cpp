#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAXN = 2e3;
const int MAXA = 2e3;
const int MAXS = 2e4;

int N;
int A[MAXN];

ll dp[MAXS], nxt[MAXS];

ll go() {
	ll res = 0;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	int sum = 0;
	for(int i = 0; i < N; i++) {
		int v = A[i];
		memset(nxt, 0, sizeof(nxt));
		for(int s = 0; s <= sum; s++) {
			nxt[s + v] += dp[s];
			nxt[s + v] %= MOD;
			nxt[abs(s - v)] += dp[s];
			nxt[abs(s - v)] %= MOD;
		}

		res += nxt[0];
		res %= MOD;

		sum += v;

		memcpy(dp, nxt, sizeof(dp));
		dp[0] ++;
	}
	return res;
}

int main() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cout << go() << '\n';
}