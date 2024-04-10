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
const int size = 200 * 1000;

long long cur[size];
long long ncur[size];

int n, m;
long long d;
vector <pair <long long, int> > hv;

void recalc(long long step) {
	if (step == 0)
		return;
	for (int i = 0; i < n; i++)
		ncur[i] = cur[i];
	hv.clear();
	int p = 0;
	for (int i = 0; i < n; i++) {
		while (!hv.empty() && hv.back().fs <= cur[i])
			hv.pop_back();
		hv.pb(mp(cur[i], i));
		p = min(p, (int) hv.size() - 1);
		while (p < (int) hv.size() && abs(hv[p].sc - i) > step)
			p++;
		ncur[i] = max(ncur[i], hv[p].fs);
	}

	hv.clear();
	for (int i = n - 1; i >= 0; i--) {
		while (!hv.empty() && hv.back().fs <= cur[i])
			hv.pop_back();
		hv.pb(mp(cur[i], i));
		p = min(p, (int) hv.size() - 1);
		while (p < (int) hv.size() && abs(hv[p].sc - i) > step)
			p++;
		ncur[i] = max(ncur[i], hv[p].fs);
	}

	for (int i = 0; i < n; i++)
		cur[i] = ncur[i];
}

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d%d%I64d", &n, &m, &d);
	vector <pair <long long, pair <long long, long long> > > events;
	int a, b, t;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &t);
		a--;
		events.pb(mp(t, mp(a, b)));
	}

	sort(events.begin(), events.end());
	for (int i = 0; i < n; i++) {
		cur[i] = 0;
	}
	long long lst = 0;

	for (int i = 0; i < (int) events.size(); i++) {
		recalc((events[i].fs - lst) * 1ll * d);
		for (int j = 0; j < n; j++)
			cur[j] += events[i].sc.sc - abs(events[i].sc.fs - j);
		lst = events[i].fs;
	}

	long long mx = cur[0];
	for (int i = 0; i < n; i++)
		mx = max(mx, cur[i]);

	cout << mx << endl;

	return 0;
}