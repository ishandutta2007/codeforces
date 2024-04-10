#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		int n, m, a;
		cin >> n;
		int prefr = 0, prefb = 0, maxir = 0, maxib = 0;
		REP(i, n) {
			cin >> a;
			prefr += a;
			maxir = max(maxir, prefr);
		}
		cin >> m;
		REP(i, m) {
			cin >> a;
			prefb += a;
			maxib = max(maxib, prefb);
		}
		cout << maxir + maxib << "\n";
	}
	return 0;
}