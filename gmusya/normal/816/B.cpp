#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

const int MAXN = 200000 + 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, q;
	cin >> n >> k >> q;
	vector <int> s(MAXN), ss(MAXN), ans(MAXN);
	while (n--) {
		int l, r;
		cin >> l >> r;
		s[l]++;
		s[r + 1]--;
	}
	for (int i = 1; i < MAXN; i++)
		ss[i] = ss[i - 1] + s[i];
	for (int i = 1; i < MAXN; i++)
		ans[i] = ans[i - 1] + (ss[i] >= k);
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << ans[r] - ans[l - 1] << endl;
	}
	return 0;
}