#include <bits/stdc++.h>
using namespace std;
#define MAX 500010
#define all(v) v.begin(), v.end()
#define ln '\n'
#define MOD 10007
#define INF 2100000000
#define abs(x) ((x)>0?(x):-(x))
typedef long long ll;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll C;
	cin >> C;
	while (C-- > 0) {
		int N, K;
		cin >> N >> K;
		if (K < N) {
			if (N%K) cout << 2 << ln;
			else cout << 1 << ln;
		}
		else if (K%N) cout << K / N + 1 << ln;
		else cout << K / N << ln;
	}
	return 0;
}