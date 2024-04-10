#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
#include <vector>
using std::vector;
#include <map>
using std::map;
#include <set>
using std::set;
#include <queue>
using std::queue; using std::priority_queue;
#include <utility>
using std::pair;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
#define pass printf("%s : Line.%d\n", __FUNCTION__, __LINE__);

inline int readint() {
	int a = 0, po = 1; char c = getchar();
	while(isspace(c)) c = getchar();
	if(c == '-') po = -1, c = getchar();
	while(isdigit(c)) a = a*10 + c - '0', c = getchar();
	return a * po;
}
inline LL readLL() {
	LL a = 0, po = 1; char c = getchar();
	while(isspace(c)) c = getchar();
	if(c == '-') po = -1, c = getchar();
	while(isdigit(c)) a = a*10 + c - '0', c = getchar();
	return a * po;
}
bool chmin(int &a, int b) { return a > b ? a = b, true : false; }
bool chmax(int &a, int b) { return a < b ? a = b, true : false; }
bool chmin(LL &a, LL b) { return a > b ? a = b, true : false; }
bool chmax(LL &a, LL b) { return a < b ? a = b, true : false; }

const int maxN = 1000000 + 233;
const int maxA = 1000000 + 233;
int n, a[maxN], c[maxA], f[maxA];

int main() {
	n = readint();
	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= n; ++i) c[readint()]++;
	int ans = 0;
	for(int i = 1; i < maxA; ++i) if(c[i]) {
		chmax(ans, f[i] += c[i]);
		for(int j = i + i; j < maxA; j += i)
			chmax(f[j], f[i]);
	}
	cout << ans << endl;
	return 0;
}