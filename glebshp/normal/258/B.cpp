#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
const double pi = acos(-1.0);
const int smsize = 20;
const long long mdl = 1000 * 1000 * 1000 + 7;

long long cnt[smsize][smsize];
long long pw[smsize];
long long tot[smsize];

long long m;

long long rec(long long lans, int p, int hsum) {
	if (p == 6)
		return lans;

	long long tans = 0;

	for (int i = 0; i < hsum; i++) {
		if (tot[i] > 0) {
			tot[i]--;

			tans = (tans + rec(lans * (tot[i] + 1) % mdl, p + 1, hsum - i)) % mdl;

			tot[i]++;
		}
	}

	return tans;
}

int main() {
	//freopen("problem_b.in", "r", stdin);
	//freopen("problem_b.out", "w", stdout);
	
	cin >> m;

	if (m == 7) {
		cout << 0 << endl;

		return 0;
	}

	pw[0] = 1;
	for (int i = 1; i < smsize; i++)
		pw[i] = (pw[i - 1] * 10);

	cnt[0][0] = 1;
	for (int i = 1; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			cnt[i][j] = 0;
			cnt[i][j] = (cnt[i][j] + cnt[i - 1][j] * 8) % mdl;
			if (j > 0)
				cnt[i][j] = (cnt[i][j] + cnt[i - 1][j - 1] * 2) % mdl;
		}
	}

	for (int i = 0; i < 12; i++) {
		long long h = m;
		int tp = i;

		for (int j = 12; j >= 0; j--) {
			int c = 0;
			while (h >= pw[j]) {
				if (c != 4 && c != 7)
					tot[i] += cnt[j][tp];
				else
					if (tp > 0)
						tot[i] += cnt[j][tp - 1];
				c++;
				
				h -= pw[j];
			}

			if (c == 4 || c == 7)
				if (tp == 0)
					break;
				else
					tp--;
		}

		tot[i] %= mdl;
	}

	tot[0]--;
	long long h = m;
	int c = 0;
	while (h > 0) {
		c += (h % 10 == 4 || h % 10 == 7);
		h /= 10;
	}
	tot[c]++;

	long long ans = 0;

	for (int i = 1; i < 12; i++) {
		long long lans = tot[i];

		ans = (ans + rec(lans, 0, i)) % mdl;
	}

	cout << ans << endl;


	return 0;
}