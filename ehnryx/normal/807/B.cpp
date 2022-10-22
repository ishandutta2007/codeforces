#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

bool valid(int p, int points) {
	int i = (points / 50) % 475;
	for (int j = 0; j < 25; j++) {
		i = (i*96 + 42) % 475;
		if (26 + i == p)
			return true;
	}
	return false;
}

int main() {
	int p, points, thresh, hacks;
	cin >> p >> points >> thresh;
	hacks = -1;
	for (int i = points; i >= thresh; i -= 50) {
		if (valid(p, i)) {
			hacks = 0;
			break;
		}
	}
	if (hacks == 0) {
		cout << 0 << endl;
	}
	else {
		hacks = 0;
		for (int i = points+50; ; i += 100) {
			++hacks;
			if (valid(p, i) || valid(p, i+50))
				break;
		}
		cout << hacks << endl;
	}
	return 0;
}