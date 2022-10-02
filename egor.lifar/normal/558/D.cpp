#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <unordered_map>


using namespace std;


int h, q;
vector<pair<long long, long long> > good, bad;


int main() {
	cin >> h >> q;
	for (int i = 0; i < q; i++) {
		int ur, ans;
		long long l, r;
		scanf("%d %I64d %I64d %d", &ur, &l, &r, &ans);
		for (int j = ur + 1; j <= h; j++) {
			l *= 2LL;
			r *= 2LL;
			r += 1LL;
		}
		if (ans == 1) {
			good.push_back(make_pair(l, r));
		} else {
			bad.push_back(make_pair(l, r));
		}
	}
	long long L = (1LL << (h - 1LL)), R = (1LL << h) - 1LL;
	for (int i = 0; i < (int)good.size(); i++) {
		L = max(L, good[i].first);
		R = min(R, good[i].second);
	}
	if (L > R) {
		cout << "Game cheated!" << endl;
//		cout << "opa" << endl;
		return 0;
	}
	sort(bad.begin(), bad.end());
	long long l = L;
	bool badd = false;
	long long ans = 0;
	int t = 0;
	bad.push_back(make_pair((1LL << h), (1LL << h)));
//	cout << L << ' ' << R << endl;
	for (int i = 0; i < (int)bad.size(); i++) {
		if (bad[i].first > l) {
			long long gg = min(R + 1LL, bad[i].first);
			if (gg - l >= 2LL) {
				badd = true;
				break;
			}
			if (gg - l == 1LL) {
				ans = l;
				t++;
				if (t >= 2) {
					badd = true;
					break;
				}
			}
		}
		l = max(l, bad[i].second + 1LL);
		if (l > R) {
			break;
		}
	}
	if (badd) {
		cout << "Data not sufficient!" << endl;
		return 0;
	}
	if (ans != 0LL) {
		cout << ans << endl;
	} else {
		cout << "Game cheated!" << endl;
	}
    return 0;
}