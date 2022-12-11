#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
  
using namespace std;
  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define XX first
#define YY second
#define db long double
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
  
const ll P1 = 353251;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

/*
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
void * operator new ( size_t n ) {
    char *res = mem + mpos;
    mpos += n;
    return (void *)res;
}
void operator delete ( void * ) { }
*/

int n;
int a[1007];
vector<int> color[8];
int dp[1001][257];
int ge[1001][8];
int now;
bool was[8];

int calc(int v, int mask) {
	if (mask == ((1 << 8) - 1))
		return 0;
	//cout << v << ' ' << mask << endl;
	if (n == v) {
		if (mask == ((1 << 8) - 1))
			return 0;
		else
			return -1;
	}
	if (dp[v][mask] != -INF)
		return dp[v][mask];
	int ans = -1;

	for (int c = 0; c < 8; c++)
		if (!((mask >> c) & 1)) {
			int s = ge[v][c];
			int uk1 = -1, uk2 = -1;
			if (s != -1 && s + now - 1 < color[c].size())
				uk1 = color[c][s + now - 1];
			if (s != -1 && s + now < color[c].size())
				uk2 = color[c][s + now];
			if (now == 0)
				uk1 = v;
			if (uk1 != -1 && calc(uk1 + 1, mask + (1 << c)) != -1)
				ans = max(ans, now + calc(uk1 + 1, mask + (1 << c)));
			if (uk2 != -1 && calc(uk2 + 1, mask + (1 << c)) != -1)
				ans = max(ans, now + 1 + calc(uk2 + 1, mask + (1 << c)));
		}

	dp[v][mask] = ans;
	return ans;
}

int can(int len) {
	if (len == 0) {
		int ans = 0;
		memset(was, 0, sizeof(was));
		for (int i = 0; i < n; i++)
			if (!was[a[i]])
				ans++, was[a[i]] = 1;
		return ans;
	}
	now = len;
	for (int i = 0; i < 1001; i++)
		for (int j = 0; j < 257; j++)
			dp[i][j] = -INF;
	int ans = calc(0, 0);
	if (ans == -1)
		return 0;
	else {
		return ans;
	}
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//mt19937 rnd(time(NULL));
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("just.in", "r", stdin);
		//freopen("just.out","w", stdout);
	}
	for (int i = 0; i < 1001; i++)
		for (int j = 0; j < 8; j++)
			ge[i][j] = -1;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]), a[i]--;

	for (int i = 0; i < n; i++)
		color[a[i]].pub(i);

	for (int c = 0; c < 8; c++) {
		int uk = color[c].size();
		for (int i = n - 1; i >= 0; i--) {
			if (a[i] == c)
				uk--;
			if (uk != color[c].size())
				ge[i][c] = uk;
		}
	}
	int l = 0, r = n + 1;
	while (l + 1 < r) {
		int m = (l + r) / 2;
		if (can(m))
			l = m;
		else
			r = m;
	}
	cout << can(l);
}