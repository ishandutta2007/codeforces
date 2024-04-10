#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	int Sx, Sy; cin >> Sx >> Sy;
	int vup = 0;
	int vdown = 0;
	int vleft = 0;
	int vright = 0;

	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		if (x > Sx) vright++;
		if (x < Sx) vleft++;
		if (y > Sy) vup++;
		if (y < Sy) vdown++;
	}
	int ans = max(max(vup, vdown), max(vleft, vright));
	if (vup == ans) {
		Sy++;
	} else if (vdown == ans) {
		Sy--;
	} else if (vleft == ans) {
		Sx --;
	} else if (vright == ans) {
		Sx ++;
	} else assert(false);
	cout << ans << '\n';
	cout << Sx << ' ' << Sy << '\n';

	return 0;
}