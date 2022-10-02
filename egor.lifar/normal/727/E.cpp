#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>


using namespace std;


#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define hash hash228
const int Mod = 1000000009;
const int P = 424243;
const int Mod1 = 1000000007;
const int P1 = 10003;


struct hash
{
	int h, h1;
	hash(){}
	hash(int _h, int _h1) {
		h = _h;
		h1 = _h1;
	}
};


hash operator +(hash a, hash b) {
	return hash((a.h + b.h) % Mod, (a.h1 + b.h1) % Mod1);
}


hash operator -(hash a, hash b) {
	return hash((a.h - b.h + Mod) % Mod, (a.h1 - b.h1 + Mod1) % Mod1);
}


hash operator *(hash a, hash b) {
	return hash((1LL * a.h * b.h) % Mod, (1LL * a.h1 * b.h1) % Mod1);
}


bool operator ==(hash a, hash b) {
	return a.h == b.h && a.h1 == b.h1;
}


bool operator <(hash a, hash b) {
	return a.h < b.h || (a.h == b.h && a.h1 < b.h1);
}


int n, k;
hash a[1000001];
hash powers[1000001];
hash b[1000001];
map<hash, vector<int> > c;
int who[1000001];


hash gethash(int l, int r) {
	return a[r] - (l > 0 ? a[l - 1] * powers[r - l + 1]: hash(0, 0));
}


hash getrealhash(int l, int r) {
	if (l <= r) {
		return gethash(l, r);
	}
	return gethash(l, n * k - 1) * powers[r + 1] + gethash(0, r);
}


set<int> ss;


bool ok(int start) {
	ss.clear();
	for (int i = 0; i < n; i++, start = (start + k) % (n * k)) {
		if (who[start] == 0) {
			return 0;
		}
		if (ss.find(who[start]) != ss.end()) {
			return 0;
		}
		ss.insert(who[start]);
	}
	return 1;
}


int main() {
	cin >> n >> k;
	string s;
	cin >> s;
	powers[0] = hash(1, 1);
	for (int i = 1; i <= n * k; i++) {
		powers[i] = powers[i - 1] * hash(P, P1);
	}
	for (int i = 0; i < n * k; i++) {
		a[i] = (i > 0 ? a[i - 1] * powers[1]: hash(0, 0)) + hash(s[i], s[i]);
	}
	for (int i = 0; i < n * k; i++) {
		b[i] = getrealhash(i, (i + k - 1) % (n * k));
		c[b[i]].push_back(i);
		//cout << i << ' ' << (i + k - 1) % (n * k) << endl;
		//cout << b[i].h << endl;
	}
	int g;
	cin >> g;
	for (int i = 0; i < g; i++) {
		hash t = hash(0, 0);
		string gs;
		cin >> gs;
		for (int j = 0; j < sz(gs); j++) {
			t = t * powers[1] + hash(gs[j], gs[j]);
		}
		for (int j = 0; j < sz(c[t]); j++) {
			who[c[t][j]] = i + 1;
		}
		//cout << t.h << endl;
	}
	// for (int i = 0; i < n * k; i++) {
	//  	cout << who[i] << endl;
	// }
	for (int st = 0; st < k; st++) {
		if (ok(st)) {
			cout << "YES" << endl;
			int cur = st;
			for (int i = 0; i < n; i++) {
				printf("%d ", who[cur]);
				cur += k;
				cur %= (n * k);
			}
			printf("\n");
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}