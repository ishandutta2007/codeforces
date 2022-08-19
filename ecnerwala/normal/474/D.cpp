#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

const int MAXN = 2e5;
const int N = 1e5 + 20;
int cnt[MAXN];
int pref[MAXN];

int T;
int K;
int main() {
	cin >> T >> K;
	cnt[0] = 1;
	pref[0] = cnt[0];
	for(int i = 1; i <= N; i++) {
		cnt[i] = cnt[i - 1];
		if(i >= K) cnt[i] += cnt[i - K];
		if(cnt[i] >= MOD) cnt[i] -= MOD;
		pref[i] = pref[i - 1] + cnt[i];
		if(pref[i] >= MOD) pref[i] -= MOD;
	}
	for(int i = 0; i < T; i++) {
		int a, b; cin >> a >> b;
		int res  = pref[b] - pref[a - 1];
		if(res < 0) res += MOD;
		cout << res << '\n';
	}
	return 0;
}