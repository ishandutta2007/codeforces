#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
using std::sort; using std::min; using std::max;
#include <vector>
using std::vector;
#include <set>
using std::set;
#include <queue>
using std::queue; using std::priority_queue;
#include <utility>
using std::pair;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define pass printf("%s : Line.%d\n", __FUNCTION__, __LINE__);

inline bool chmin(int &a, int b) { return a > b ? a = b, true : false; }
inline bool chmax(int &a, int b) { return a < b ? a = b, true : false; }

const int maxN = 1000000 + 233;
int n, m;
char s[maxN];
int pref[maxN];

int succ[maxN];

void initialize() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	m = 0;
	for(int i = 1; i <= n; ++i) m += (s[i] == 'P');
	pref[0] = 0;
	for(int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + (s[i] == '*');
	succ[n + 1] = maxN;
	s[n + 1] = '\0';
	for(int i = n; i >= 0; --i) {
		if(s[i + 1] == '*') succ[i] = i + 1;
		else succ[i] = succ[i + 1];
	}
}

pii spj() {
	int p = 0;
	for(int i = 1; i <= n; ++i) if(s[i] == 'P') p = i;
	int t1 = maxN, t2 = maxN;
	for(int i = p - 1; i >= 1; --i) if(s[i] == '*') t1 = i;
	for(int i = p + 1; i <= n; ++i) if(s[i] == '*') t2 = i;
	if(pref[n] - pref[p - 1] > pref[p - 1] - pref[0])
		return pii(pref[n] - pref[p - 1], t2 - p);
	else if(pref[n] - pref[p - 1] < pref[p - 1] - pref[0])
		return pii(pref[p - 1] - pref[0], p - t1);
	else return pii(pref[n] - pref[p - 1], std::min(t2 - p, p - t1));
}

vector<int> packs;
int f[maxN];

/*
58
..P.P*.P*.P...PPP...P*....*..*.**......*P.*P.....**P...*P*
*/

int last_pos;

bool check(int range) {
//	printf("check : range = %d\n", range);
	for(int i = 0; i <= m + 5; ++i) f[i] = -1;
	f[0] = 0;
	for(int i = 0; i + 1 < (int)packs.size(); ++i) if(f[i] >= 0) {
		for(int d = 0; d < 2; ++d) {
			int lb = packs[i + 1];
			if(~d & 1) lb = packs[i + 1] - range;
			if(f[i] <= n && succ[f[i]] < lb) continue;
			
			int frb = std::max(f[i], packs[i + 1]);
			if(d & 1) chmax(frb, packs[i + 1] + range);
//			printf("case 1 : i = %d, d = %d, f[%d] -> %d\n", i, d, i + 1, frb);
			chmax(f[i + 1], frb);
		}
		if(i + 2 >= (int)packs.size()) continue;
		for(int d = 0; d < 4; ++d) {
			int lb = packs[i + 1];
			if(~d & 1) lb = packs[i + 1] - range;
			else if(~d & 2) chmin(lb, packs[i + 2] - range);
			if(f[i] <= n && succ[f[i]] < lb) continue;
			
			int mlb = std::max(packs[i + 1], f[i]);
			int mrb = packs[i + 2];
			if(~d & 2) chmin(mrb, packs[i + 2] - range);
			if(mlb <= n && succ[mlb] < mrb) continue;

			int frb = std::max(f[i], packs[i + 2]);
			if(d & 1) chmax(frb, packs[i + 1] + range);
			if(d & 2) chmax(frb, packs[i + 2] + range);
//			printf("case 2 : i = %d, d = %d, f[%d] -> %d\n", i, d, i + 2, frb);
			chmax(f[i + 2], frb);
		}
	}
//	printf("%d %d %d\n", packs[m], succ[packs[m]], f[m]);
//	system("pause");
	return f[m] >= last_pos;
}

pii solve() {
	packs.push_back(0);
	for(int i = 1; i <= n; ++i) if(s[i] == 'P') packs.push_back(i);
	assert(m == (int)packs.size() - 1);
	for(int i = 1; i <= n; ++i) if(s[i] == '*') last_pos = i;
	int L = 0, R = n;
	while(L < R) {
		int M = (L + R) >> 1;
		if(check(M)) R = M;
		else L = M + 1;
	}
	return pii(pref[n], L);
}

int main() {
	initialize();
	pii ans = m == 1 ? spj() : solve();
	printf("%d %d\n", ans.first, ans.second);
	return 0;
}