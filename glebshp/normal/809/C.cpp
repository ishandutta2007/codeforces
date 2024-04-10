#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const long long mdl = 1000 * 1000 * 1000 + 7;
const int size = 100;
const int bits = 30;

map <pair <int, int>, int > sum[bits];
map <pair <int, pair <int, int> >, int> ans[bits];
map <pair <int, pair <int, int> >, int> cnt[bits];

int getcount(int b, int x, int y, int k) {
	if (x < 0 || y < 0 || k == 0)
		return 0;
	if (x > y)
		return getcount(b, y, x, k);

	auto it = cnt[b].find(mp(k, mp(x, y)));
	if (it != cnt[b].end())
		return it->sc;

	if (b == 0) {
		int ansv = 0;
		for (int i = 0; i <= x; i++)
			for (int j = 0; j <= y; j++) {
				int d = (i ^ j) + 1;
				if (d <= k)
					ansv++;
			}				
		cnt[b][mp(k, mp(x, y))] = ansv;

		return ansv;
	}

	int ansv = 0;
	int len = (1 << b);
	if ((k >> b) & 1) {
		int h = min(x, len - 1) + 1;
		int w = min(y, len - 1) + 1;
		ansv = (h * 1ll * w) % mdl;

		h = max(0, x - len + 1);
		w = max(0, y - len + 1);
		ansv = (ansv + h * 1ll * w) % mdl;

		ansv += getcount(b - 1, min(x, len - 1), y - len, k - len);
		if (ansv >= mdl)
			ansv -= mdl;

		ansv += getcount(b - 1, x - len, min(y, len - 1), k - len);
		if (ansv >= mdl)
			ansv -= mdl;
	} else {
		ansv = getcount(b - 1, min(x, len - 1), min(y, len - 1), k);
		ansv += getcount(b - 1, x - len, y - len, k);
		if (ansv >= mdl)
			ansv -= mdl;
	}

	cnt[b][mp(k, mp(x, y))] = ansv;

//	cerr << "count " << b << ' ' << k << ' ' << x << ' ' << y << ' ' << ansv << endl;

	return ansv;
}


int getsum(int b, int x, int y) {
	if (x < 0 || y < 0)
		return 0;
	if (x > y)
		return getsum(b, y, x);

	auto it = sum[b].find(mp(x, y));
	if (it != sum[b].end())
		return it->sc;	
		
	int ansv = 0;
	if (b == 0) {
		for (int i = 0; i <= x; i++)
			for (int j = 0; j <= y; j++)
				ansv += (i ^ j) + 1;
	} else {
		int len = (1 << b);
		ansv = getsum(b - 1, min(x, len - 1), min(y, len - 1));
		ansv += getsum(b - 1, x - len, y - len);
		if (ansv >= mdl)
			ansv -= mdl;

		ansv += getsum(b - 1, min(x, len - 1), y - len);
		if (ansv >= mdl)
			ansv -= mdl;

		ansv += getsum(b - 1, x - len, min(y, len - 1));
		if (ansv >= mdl)
			ansv -= mdl;

		int w = max(0, x - len + 1);
		int h = min(y, len - 1) + 1;
		ansv = (ansv + ((w * 1ll * h) % mdl) * 1ll * len) % mdl;

		w = min(x, len - 1) + 1;
		h = max(0, y - len + 1);
		ansv = (ansv + ((w * 1ll * h) % mdl) * 1ll * len) % mdl;
	}

	sum[b][mp(x, y)] = ansv;

//	cerr << "sum " << b << ' ' << x << ' ' << y << ' ' << ansv << endl;
	
	return ansv;
}

int getans(int b, int x, int y, int k) {
	if (x < 0 || y < 0 || k == 0)
		return 0;
	if (x > y)
		return getans(b, y, x, k);

	auto it = ans[b].find(mp(k, mp(x, y)));
	if (it != ans[b].end())
		return it->sc;

	if (b == 0) {
		int ansv = 0;
		for (int i = 0; i <= x; i++)
			for (int j = 0; j <= y; j++) {
				int d = (i ^ j) + 1;
				if (d <= k)
					ansv += d;
			}				
		ans[b][mp(k, mp(x, y))] = ansv;

		return ansv;
	}

	int ansv = 0;
	int len = (1 << b);
	if ((k >> b) & 1) {
		ansv = getsum(b - 1, min(x, len - 1), min(y, len - 1));
		ansv += getsum(b - 1, x - len, y - len);
		if (ansv >= mdl)
			ansv -= mdl;

		ansv += getans(b - 1, min(x, len - 1), y - len, k - len);
		if (ansv >= mdl)
			ansv -= mdl;
		int h = getcount(b - 1, min(x, len - 1), y - len, k - len);
		ansv = (ansv + h * 1ll * len) % mdl;

		ansv += getans(b - 1, x - len, min(y, len - 1), k - len);
		if (ansv >= mdl)
			ansv -= mdl;
		h = getcount(b - 1, x - len, min(y, len - 1), k - len);
		ansv = (ansv + h * 1ll * len) % mdl;	
	} else {
		ansv = getans(b - 1, min(x, len - 1), min(y, len - 1), k);
		ansv += getans(b - 1, x - len, y - len, k);
		if (ansv >= mdl)
			ansv -= mdl;
	}

	ans[b][mp(k, mp(x, y))] = ansv;

//	cerr << "ans " << b << ' ' << k << ' ' << x << ' ' << y << ' ' << ansv << endl;

	return ansv;
}

int main () {
/*	
	freopen("input.txt", "w", stdout);
	printf("10000\n");
	for (int i = 0; i < 10 * 1000; i++) {
		printf("%d %d %d\n", 900 * 1000 * 1000, 1000 * 1000 * 1000 - i, 1000 * 1000 * 1000 - 9999 + i);
	}

	return 0;
*/
	
	int q;

//    freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

	scanf("%d", &q);
	for (int t = 0; t < q; t++) {
		int l, r, u, d, k;
		scanf("%d%d%d%d%d", &l, &u, &r, &d, &k);
		l--, r--, u--, d--;
		//k--;

		long long ans;
		if (k >= (1ll << bits) - 1) {
			ans = (0ll + getsum(bits - 1, r, d) - getsum(bits - 1, l - 1, d) - getsum(bits - 1, r, u - 1) + getsum(bits - 1, l - 1, u - 1));
		} else {
			ans = 0ll + getans(bits - 1, r, d, k) - getans(bits - 1, l - 1, d, k) - getans(bits - 1, r, u - 1, k) + getans(bits - 1, l - 1, u - 1, k);
		}
		//ans += (0ll + getcount(bits - 1, r, d, k) - getcount(bits - 1, l - 1, d, k) - getcount(bits - 1, r, u - 1, k) + getcount(bits - 1, l - 1, u - 1, k));
		
		printf("%d\n", int((ans + mdl + mdl) % mdl));
	//	cerr << t << endl;
	}

    return 0;
}