#include <iostream>
#include <cstdint>
#include <algorithm>
#include <cstdlib>
#include <iomanip>

using namespace std;

inline string int64ToHex(int64_t value) {
	const char convertSet[] = "0123456789abcdef";
	string res = "";
	do {
		res += convertSet[value & 15];
		value >>= 4;
	} while (value);
	reverse(res.begin(), res.end());
	return res;
}

inline int64_t hexToInt64(const string& value) {
	int64_t res = 0;
	for (int i = 0; i < (int)value.size(); i++) {
		res <<= 4;
		if ('0' <= value[i] && value[i] <= '9') {
			res |= value[i] - '0';
		} else if ('a' <= value[i] && value[i] <= 'f') {
			res |= value[i] - 'a' + 10;
		}
	}
	return res;
}

int64_t lessCnt[2][16][16] = {};
int64_t maskCnt[2][16][16] = {};

inline int64_t power(int64_t base, int pow) {
	int64_t res = 1;
	for (int i = 0; i < pow; i++) {
		res *= base;
	}
	return res;
}

inline void calcLessCnt() {
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			lessCnt[true][i][j] = power(j+1, i) - power(j, i);
			lessCnt[false][i][j] = power(j+1, i);
		}
	}
}

inline void calcMaskCnt() {
	for (int i = 1; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			int bitPos = j >> 2;
			if (bitPos >= i) {
				maskCnt[true][i][j] = 0;
				maskCnt[false][i][j] = 0;
			} else {
				int64_t must1 = (int64_t)1 << j;
				for (int k = 0; k <= j; k++) {
					int64_t curBit = k << (4 * bitPos);
					if (curBit & must1) {
						if (k == j) {
							maskCnt[true][i][j] += power(j+1, i-1);
						} else {
							maskCnt[true][i][j] += power(j+1, i-1) - power(j, i-1);
						}
						maskCnt[false][i][j] += power(j+1, i-1);
					}
				}
			}
		}
	}
}

inline int maxBit(int64_t num) {
	int res = 0;
	while (num) {
		res = max(res, (int)(num & 15));
		num >>= 4;
	}
	return res;
}

inline int64_t cnt(const string& prefStr, int mask) {
	int64_t res = 0;
	int64_t pref = hexToInt64(prefStr);
	int startFrom = maxBit(pref);
	for (int i = startFrom; i < 16; i++) {
		int bitPos = i >> 2;
		if (bitPos >= mask) {
			if (pref & ((int64_t)1 << (i - 4 * mask))) {
				res += lessCnt[i != startFrom][mask][i];
			}
		} else {
			res += maskCnt[i != startFrom][mask][i];
		}
	}
	return res;
}

inline int64_t getAns(int64_t rightBound) {
	if (rightBound < 0) {
		return 0;
	}
	string str = int64ToHex(rightBound);
	int len = str.size();	
	int64_t res = 0;
	for (int i = 0; i + 1 < len; i++) {
		for (int j = 1; j < 16; j++) {
			res += cnt(int64ToHex(j), i);
		}
	}
	for (int i = 0; i < len; i++) {
		for (int j = !i; j < 16; j++) {
			char curDigit = int64ToHex(j)[0];
			if (str[i] == curDigit) {
				break;
			}
			res += cnt(str.substr(0, i) + curDigit, len - i - 1);
		}
	}
	res += cnt(str, 0);
	return res;
}

int main() {
	calcLessCnt();
	calcMaskCnt();
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		string l, r; cin >> l >> r;
		cout << getAns(hexToInt64(r)) - getAns(hexToInt64(l)-1) << "\n";
	}
	return 0;
}