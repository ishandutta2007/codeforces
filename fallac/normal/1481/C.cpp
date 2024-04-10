#include <bits/stdc++.h>
using namespace std;
#define MAX 101010
#define all(v) v.begin(), v.end()
#define ln '\n'
#define MOD 1000000007
#define INF 210000000000
#define pb push_back
#define abs(x) (((x)>0)?(x):(-(x)))
#define len(x) ((x).second-(x).first)
#define yy "YES"
#define nn "NO"
typedef long long ll;
int A[MAX], B[MAX], C[MAX], ans[MAX], rev[MAX];
vector<int> diff[MAX];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T-- > 0) {
		int N, M;
		cin >> N >> M;
		int i;
		for (i = 0; i <= N; i++) diff[i].clear();
		for (i = 0; i <= N; i++) rev[i] = 0;
		for (i = 1; i <= N; i++) cin >> A[i];
		for (i = 1; i <= N; i++) cin >> B[i];
		for (i = 1; i <= M; i++) cin >> C[i];
		for (i = 1; i <= N; i++) {
			if (A[i] != B[i]) diff[B[i]].pb(i);
			else rev[A[i]] = i;
		}
		int prev = 0;
		bool c = true;
		if (diff[C[M]].empty()) {
			if (rev[C[M]]) ans[M] = prev = rev[C[M]];
			else c = false;
		}
		else ans[M] = prev = diff[C[M]][diff[C[M]].size() - 1], diff[C[M]].pop_back();
		for (i = M - 1; i >= 1; i--) {
			if (diff[C[i]].empty()) ans[i] = prev;
			else ans[i] = diff[C[i]][diff[C[i]].size() - 1], diff[C[i]].pop_back();
		}
		for (i = 1; i <= N; i++) c = !c ? false : diff[i].empty();
		if (c) {
			cout << yy << ln;
			for (i = 1; i <= M; i++) cout << ans[i] << ln;
		}
		else cout << nn << ln;
	}
	return 0;
}