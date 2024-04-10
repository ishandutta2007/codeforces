#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/3)
#define MAXN 100000
#define MAXFLOGN 16

typedef long long lint;

using namespace std;

typedef unsigned long long hasht;

const int maxhashsize = MAXN;
const hasht base = 33;
const char hashstartchar = 'a';

hasht basepow[maxhashsize+1];
void calc_basepow() {
	basepow[0] = 1;
	for (int i = 1; i <= maxhashsize; i++) basepow[i] = basepow[i-1] * base;
}

struct hashstr {
	string s;
	vector<hasht> h;

	int value(char c) {return (c-hashstartchar)+1;}
	int size() {return s.size();}

	void calc_hash() {
		h.resize(s.size()+1);
		h[0] = 0;
		for (int i = 0; i < (int)s.size(); i++) h[i+1] = h[i] + basepow[i] * value(s[i]);
	}
};

int hash_lcp(hashstr &hs1, hashstr &hs2, int off1 = 0, int off2 = 0) {
	int l = 0, r = min(hs1.size() - off1, hs2.size() - off2);
	while (l < r) {
		int m = (l+r+1)/2;
		if ((hs1.h[off1+m] - hs1.h[off1]) * basepow[off2] == (hs2.h[off2+m] - hs2.h[off2]) * basepow[off1])
			l = m;
		else
			r = m-1;
	}

	return l;
}

int hash_cmp(hashstr &hs1, hashstr &hs2, int off1 = 0, int off2 = 0) {
	int l = hash_lcp(hs1, hs2, off1, off2);
	if (l < hs1.size() - off1 && l < hs2.size() - off2)
		return hs1.s[off1+l] - hs2.s[off2+l];
	return (hs1.size() - off1) - (hs2.size() - off2);
}

int one_diff_pos(hashstr &hs1, hashstr &hs2, int size, int off1 = 0, int off2 = 0) {
	if (size > min(hs1.size() - off1, hs2.size() - off2)) return -1;
	int l = hash_lcp(hs1, hs2, off1, off2);
	if (l >= size) return -1;
	if (l + 1 + hash_lcp(hs1, hs2, off1+l+1, off2+l+1) < size) return -1;
	return l;
}

lint delta[26][MAXN+1];
bool isgray[MAXFLOGN+1][MAXN];
int lmask[MAXFLOGN+1][MAXN];

int main(int argc, char ** argv)
{
	calc_basepow();

	int n;
	hashstr t;

	cin >> t.s;
	n = t.size();

	t.calc_hash();

	memset(delta, 0, sizeof(delta));

	for (int i = 0; i < n; i++) {
		isgray[1][i] = true;
		lmask[1][i] = 1<<(t.s[i]-'a');
		for (int c = 0; c < 26; c++) {
			delta[c][0] += 1;
			delta[c][n] -= 1;
		}
	}

	for (int d = 2; (1<<d)-1 <= n; d++) {
		const lint size = (1<<d)-1;
		const lint subsize = (1<<(d-1))-1;

		for (int i = 0; i < n; i++) {
			if (i + size <= n) {
				bool ig0 = isgray[d-1][i];
				int m0 = lmask[d-1][i];

				int mid = i + subsize;
				int midc = t.s[mid]-'a';

				bool ig1 = isgray[d-1][mid+1];
				int m1 = lmask[d-1][mid+1];

				const int sublcp = hash_lcp(t, t, i, mid+1);

				isgray[d][i] = ig0 && ig1 && sublcp >= subsize && !(m0 & (1<<midc));

				if (isgray[d][i])
					lmask[d][i] = m0 | (1<<midc);

				int diff = one_diff_pos(t, t, subsize, i, mid+1);

				if (diff != -1) {
					if (ig0 && !(m0 & (1<<midc))) {
						delta[t.s[i+diff]-'a'][mid+1+diff] += size*size;
						delta[t.s[i+diff]-'a'][mid+1+diff+1] -= size*size;
					}
					if (ig1 && !(m1 & (1<<midc))) {
						delta[t.s[mid+1+diff]-'a'][i+diff] += size*size;
						delta[t.s[mid+1+diff]-'a'][i+diff+1] -= size*size;
					}
				}

				if (ig0 && ig1 && sublcp >= subsize) {
					for (int c = 0; c < 26; c++)
						if (!(m0 & (1<<c))) {
							delta[c][mid] += size*size;
							delta[c][mid+1] -= size*size;
						}
				}

				if (isgray[d][i]) {
					for (int c = 0; c < 26; c++) {
						delta[c][0] += size*size;
						delta[c][i] -= size*size;
						
						delta[c][i+size] += size*size;
						delta[c][n] -= size*size;
					}					
				}
			} else {
				isgray[d][i] = false;
			}
		}
	}

	lint result = 0; 

	for (int c = 0; c < 26; c++) {
		lint acc = 0;
		for (int i = 0; i < n; i++) {
			acc += delta[c][i];
			result = max(result, acc);
		}
	}

	cout << result << endl;

	return 0;
}