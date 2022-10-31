#include <bits/stdc++.h>
using namespace std;
#define MAX 1010
#define all(v) v.begin(), v.end()
#define ln '\n'
#define MOD 1000000007
#define INF 210000000000
#define pb push_back
#define abs(x) (((x)>0)?(x):(-(x)))
#define len(x) ((x).second-(x).first)
typedef long long ll;
int h[MAX];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T-- > 0) {
		int N, k;
		cin >> N >> k;
		int i;
		for (i = 1; i <= N; i++) cin >> h[i];
		while (k) {
			for (i = 1; i < N; i++) {
				if (h[i] < h[i + 1]) break;
			}
			if (i == N) break;
			h[i]++;
			k--;
		}
		if (i == N) cout << -1 << ln;
		else cout << i << ln;
	}
	return 0;
}