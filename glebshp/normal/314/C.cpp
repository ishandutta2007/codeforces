#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
const double pi = acos(-1.0);
const int size = 1000 * 1000 + 100;
const long long mdl = 1000 * 1000 * 1000 + 7;
const int rms = (1 << 18) - 1;
const int hrms = rms / 2;

int n;
int val[size];
long long ans[size];
long long psum[size];
int lst[size];
long long rsq[rms + 1];

void change(int ps, long long val) {
	ps += hrms + 1;
	rsq[ps] = val;
	while (ps > 1) {
		ps /= 2;
		rsq[ps] = rsq[ps * 2] + rsq[ps * 2 + 1];
		if (rsq[ps] >= mdl)
			rsq[ps] -= mdl;
	}
}

long long rss(int v, int i, int j, int lb, int rb) {
	if (i > rb || j < lb)
		return 0;
	if (lb >= i && rb <= j)
		return rsq[v];
	long long d = rss(v * 2, i, j, lb, (lb + rb) / 2) + rss(v * 2 + 1, i, j, (lb + rb) / 2 + 1, rb);
	if (d >= mdl)
		d -= mdl;
	return d;
}

int main() {
	//freopen("problem_c.in", "r", stdin);
	//freopen("problem_c.out", "w", stdout);
	
	vector <pair <int, int> > vc;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &val[i]);
		vc.pb(mp(val[i], i));
	}
	sort(vc.begin(), vc.end());
	
	long long tot = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			tot = (tot + vc[i].fs) % mdl;
			change(vc[i].sc, vc[i].fs);
			continue;
		}
		if (vc[i].fs > vc[i - 1].fs) {
			long long d = rss(1, 1, vc[i].sc + 1, 1, hrms + 1) + 1;
			d = (d * vc[i].fs) % mdl;
			tot = (tot + d) % mdl;
			change(vc[i].sc, d);
		} else {
			long long d = rss(1, vc[i - 1].sc + 1, vc[i].sc + 1, 1, hrms + 1);
			d = (d * vc[i].fs) % mdl;
			tot = (tot + d) % mdl;
			change(vc[i].sc, d);
		}
	}

	cout << tot << endl;

	return 0;
}