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
	int T;
	cin >> T;
	while (T-- > 0) {
		int N;
		cin >> N;
		int i;
		int p = 0, a;
		int cnt = 1;
		int ans = 0;
		for (i = 1; i <= N; i++) {
			cin >> a;
			if (a == p) cnt++;
			else {
				p = a;
				ans = max(cnt, ans);
				cnt = 1;
			}
		}
		ans = max(cnt, ans);
		cout << ans << ln;
	}
	return 0;
}