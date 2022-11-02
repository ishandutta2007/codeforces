#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <iomanip>
#include <string>
using std::string;
#include <algorithm>
#include <set>
using std::set; using std::multiset;
#include <map>
using std::map;
#include <bitset>
using std::bitset;

int readint() {
	int a = 0, po = 1; char c = getchar();
	while(isspace(c)) c = getchar();
	if(c == '-') po = -1, c = getchar();
	while(isdigit(c)) a = a*10 + c - '0', c = getchar();
	return a * po;
}

const int maxN = 100000 + 233;
const int maxA = 1000000000;
const char first[] = "Kevin";
const char second[] = "Nicky";
int n, k, a[maxN];

int mex(int a) {
	return a == 0 ? 1 : 0;
}
int mex(int a, int b) {
	if(a && b) return 0;
	if(a != 1 && b != 1) return 1;
	return 2;
}

const int LIMIT = 7;
const int table_odd[] = {0, 1, 0, 1, 2, 0, 2, 0, 1};
const int table_even[] = {0, 1, 2, 0, 1, 0, 1, 0, 1};

int SG(int x) {
	if(x <= LIMIT) return (k & 1) ? table_odd[x] : table_even[x];
	if(k & 1) {
		if(x & 1) return 0;
		else {
			return mex(0, SG(x / 2));
		}
	} else {
		if(x & 1) return 0;
		else return 1;
	}
}

/*
18 24
238 239 299 488 128 293 173 232 127 248 378 247 2983 1298 4329 388 1277 3
*/

int f[maxN];
void solve() {
	f[0] = 0; f[1] = 1;
	for(int i = 2; i < maxN; ++i) {
        if(i & 1) f[i] = mex(f[i - 1]);
        else f[i] = mex(f[i - 1], ((k & 1) ? f[i / 2] : 0));
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) ans ^= f[a[i]];
    printf("%s\n", ans ? first : second);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n >> k;
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		ans ^= SG(a[i]);
	}
	printf("%s\n", ans ? first : second);
//	solve();
//	for(int i = 1; i <= n; ++i) printf("%d ", SG(a[i])); printf("\n");
//	for(int i = 1; i <= n; ++i) printf("%d ", f[a[i]]); printf("\n");
	return 0;
}