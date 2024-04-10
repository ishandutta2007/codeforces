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
#define taskname "problem_e"

const double pi = acos(-1.0);
const int size = 3000;
const int smsize = 3000 / 32 + 1;

unsigned int ways[size][smsize];
int n;
int x[size], y[size];

inline int sqr(int x) {
	return x * x;
}

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d", &n);
	int m = (n + 31) / 32;
	for (int i = 0; i < n; i++)
		scanf("%d%d", &x[i], &y[i]);
	vector <pair <int, pair <int, int> > > alle;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			alle.pb(mp(sqr(x[i] - x[j]) + sqr(y[i] - y[j]), mp(i, j)));
	sort(alle.rbegin(), alle.rend());

	cout.precision(20);

	for (int i = 0; i < (int) alle.size(); i++) {
		int f = alle[i].sc.fs;
		int s = alle[i].sc.sc;
		for (int j = 0; j < m; j++)
			if (ways[f][j] & ways[s][j]) {
				cout << sqrt(alle[i].fs * 1.0) / 2.0 << endl;
				return 0;
			}
		ways[f][s / 32] ^= (1 << (s & 31));
		ways[s][f / 32] ^= (1 << (f & 31));
	}

	return 0;
}