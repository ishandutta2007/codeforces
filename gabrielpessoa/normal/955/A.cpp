#include <bits/stdc++.h>
using namespace std;

int main() {
	cout << fixed << setprecision(4);
	int hh, mm;
	int H, D, C, N;
	cin >> hh >> mm >> H >> D >> C >> N;
	if(hh >= 20) {
		cout << ((H-1)/N + 1) * C * .8 << '\n';
	} else {
		double best = ((H-1)/N + 1) * C;
		double best2 = ((H + (20*60 - hh*60 - mm)*D - 1)/N + 1) * C * .8;
		cout << min(best, best2) << '\n';
	}
}