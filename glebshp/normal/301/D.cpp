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
const int size = 200 * 1000 + 100;
const int rms = (1 << 19) - 1;
const int hrms = rms / 2;
const int mayneed = 50 * 1000 * 1000;
const int magic = 30;

//vector <int> rmq[rms + 1];

int n, m;
int num[size];
int wheren[size];
//int mymem[mayneed];
//int rmqst[rms + 1];
//int rmqfn[rms + 1];
int memptr;

vector <int> ques[size];
vector <pair <int, int> > qq[size];
int rsq[rms + 1];
int ans[size];

int rss(int v, int i, int j, int lb, int rb) {
	if (lb >= i && rb <= j) {
		return rsq[v];
	}
	if (rb < i || lb > j)
		return 0;
	return rss(v * 2, i, j, lb, (lb + rb) / 2) + rss(v * 2 + 1, i, j, (lb + rb) / 2 + 1, rb);
}

void incr(int ps) {
	ps += hrms + 1;
	rsq[ps]++;
	while (ps > 1) {
		ps /= 2;
		rsq[ps] = rsq[ps * 2] + rsq[ps * 2 + 1];
	}
}

int main() {
	double cur = clock();
	/*
	freopen("problem_d.in", "w", stdout);
	printf("200000 200000\n");
	for (int i = 0; i < 200000; i++)
		printf("%d ", i + 1);
	printf("\n");
	for (int i = 0; i < 200000; i++) {
		int d1 = rand();
		int d2 = rand();
		printf("%d %d\n", min(d1, d2), max(d1, d2));
	}
	return 0;
	*/
	//freopen("problem_d.in", "r", stdin);
	//freopen("problem_d.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		wheren[num[i]] = i;
	}
	vector <int> h;
	for (int i = 0; i < n; i++) {
		int j;
		h.clear();
		for (j = 1; j * j < num[i]; j++)
			if (num[i] % j == 0) {
				h.pb(wheren[j]);
				h.pb(wheren[num[i] / j]);
			}
		if (j * j == num[i])
			h.pb(wheren[j]);
		sort(h.begin(), h.end());
		for (int j = 0; j < int(h.size()); j++)
			ques[max(i, h[j])].pb(min(i, h[j]));
	}
	//cout << (clock() - cur) / CLOCKS_PER_SEC << endl;
	
	int lb, rb;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &lb, &rb);
		lb--, rb--;
		qq[rb].pb(mp(lb, i));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < int(ques[i].size()); j++)
			incr(ques[i][j]);
		for (int j = 0; j < int(qq[i].size()); j++)
			ans[qq[i][j].sc] = rss(1, qq[i][j].fs + 1, i + 1, 1, hrms + 1);
	}

	for (int i = 0; i < m; i++)
		printf("%d\n", ans[i]);

	return 0;
}