#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <list>
#include <deque>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define taskname "problem_c"

const double pi = acos(-1.0);
const int size = 100 * 1000 + 100;
const int lim = 300;
const int limsize = size / lim + 1;

int n, m, q;
vector <int> mset[size];
long long val[size];
bool fat[size];
int cross[lim][size];
int fnum[size];
bool used[size];
long long curans[size];
int back[size];
long long md[size];
long long upd[size];

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &val[i]);
	//vector <pair <int, int> > ssize;
	for (int i = 0; i < m; i++) {
		int sz;
		scanf("%d", &sz);
		fat[i] = (sz >= limsize);
		int idx;
		for (int j = 0; j < sz; j++) {
			scanf("%d", &idx);
			idx--;
			mset[i].pb(idx);
		}
		//ssize.pb(mp(sz, i));
		scanf("\n");
	}
	int fcnt = 0;
	for (int i = 0; i < m; i++)
		if (fat[i]) {
			fnum[i] = fcnt;
			back[fcnt] = i;
			fcnt++;
		} else {
			fnum[i] = -1;
		}
	for (int i = 0; i < m; i++)
		if (fat[i]) {
			for (int j = 0; j < n; j++)
				used[j] = false;
			for (int j = 0; j < (int) mset[i].size(); j++)
				used[mset[i][j]] = true;
			int cnt = 0;
			for (int j = 0; j < m; j++) {
				cnt = 0;
				for (int h = 0; h < (int) mset[j].size(); h++)
					cnt += used[mset[j][h]];
				cross[fnum[i]][j] = cnt;
			}
		}
	
	vector <pair <int, long long> > qrs;

	for (int i = 0; i < m; i++) {
		curans[i] = 0;
		for (int j = 0; j < (int) mset[i].size(); j++)
			curans[i] += val[mset[i][j]];
	}

	for (int i = 0; i < q; i++) {
		char tp;
		int num;
		long long vl;
		scanf("%c%d", &tp, &num);
		num--;
		if (tp == '?') {
			scanf("\n");
			long long ans = curans[num];
			if (!fat[num]) {
				for (int j = 0; j < (int) qrs.size(); j++)
					ans += cross[fnum[qrs[j].fs]][num] * qrs[j].sc;
				for (int j = 0; j < (int) mset[num].size(); j++)
					ans += md[mset[num][j]];
			}
			printf("%I64d\n", ans);
		} else {
			scanf("%I64d\n", &vl);
			for (int j = 0; j < fcnt; j++)
				curans[back[j]] += cross[j][num] * vl;
			if (fat[num]) {
				qrs.pb(mp(num, vl));
			} else {
				for (int j = 0; j < (int) mset[num].size(); j++)
					md[mset[num][j]] += vl;
			}
		}
		if ((int) qrs.size() == lim) {
			for (int i = 0; i < m; i++)
				upd[i] = 0;
			for (int i = 0; i < (int) qrs.size(); i++)
				upd[qrs[i].fs] += qrs[i].sc;
			for (int i = 0; i < m; i++)
				for (int j = 0; j < (int) mset[i].size(); j++)
					md[mset[i][j]] += upd[i];
			for (int i = 0; i < n; i++) {
				val[i] += md[i];
				md[i] = 0;
			}
			for (int i = 0; i < m; i++) {
				curans[i] = 0;
				for (int j = 0; j < (int) mset[i].size(); j++)
					curans[i] += val[mset[i][j]];
			}
			qrs.clear();
		}
	}

	return 0;
}