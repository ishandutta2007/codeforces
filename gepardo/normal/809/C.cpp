#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int modulo = (int)1e9 + 7;

inline int64_t progression(int l, int r) {
	if (l > r) {
		return 0;
	}
	return ((int64_t)(r - l + 1) * (l + r) / 2) % modulo; 
}

inline int64_t getMaskAns(int head1, int head2, int len1, int len2, int k) {
	if (len1 < len2) {
		swap(len1, len2);
		swap(head1, head2);
	}
	head2 = head2 & ~((1 << len1) - 1);
	int minMask = head1 ^ head2;
	int maxMask = minMask + (1 << len1) - 1;
	k = min(k, maxMask);
	int64_t res = (((int64_t)1 << len2) * progression(minMask+1, k+1)) % modulo;
	return res;
}

inline vector< pair<int, int> > toMasks(int val) {
	vector< pair<int, int> > ans;
	for (int i = 30; i >= 0; i--) {
		if ((val >> i) & 1) {
			int msk = val & ~((1 << (i+1)) - 1);
			int len = i;
			ans.emplace_back(msk, len);
		}
	}
	ans.emplace_back(val, 0);
	return ans;
}

inline int64_t getAns(int x, int y, int k) {
	if (x < 0 || y < 0) {
		return 0;
	}
	int64_t ans = 0;
	for (pair<int, int> pX: toMasks(x)) {
		for (pair<int, int> pY: toMasks(y)) {
			ans += getMaskAns(pX.first, pY.first, pX.second, pY.second, k);
			ans %= modulo;
		}
	}
	return ans;
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2, k; cin >> x1 >> y1 >> x2 >> y2 >> k;
		x1--; y1--; x2--; y2--; k--;
		int64_t theAns = getAns(x2, y2, k) - getAns(x1-1, y2, k) - getAns(x2, y1-1, k) + getAns(x1-1, y1-1, k);
		while (theAns < 0) {
			theAns += modulo;
		}
		theAns %= modulo;
		cout << theAns << endl;
	}
	return 0;
}