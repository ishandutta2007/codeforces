#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(VI::iterator i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

VI x;
int first[1000007];
int at[1000007];
int a, b, n;

int father[1000007];
int maxv[1000007];

inline int get(int x) {
	if (father[x] == x) return x;
	return father[x] = get(father[x]);
}

inline void merge(int a, int b) {
	a = get(a);
	b = get(b);
	maxv[a] = max(maxv[a], maxv[b]);
	father[b] = a;
}

int main() {
	cin >> n;
	x.resize(n);
	REP(i, n) {
		scanf("%d", &x[i]);
	}
	cin >> a >> b;
	// n = 100000;
	// x.clear();
	// REP(i, 100000) x.PB(i + 1);
	// a = 1000000000, b = 1000000000 - 1000000;
	SORT(x);
	x.erase(unique(ALL(x)), x.end());
	// int all = 0;
	for (int i = b; i <= a; ++i) first[i - b] = -1;
	TR(it, x) {
		// cout << "it = " << *it << endl;
		for (int i = (b / (*it)) * (*it); i <= a; i += *it) {
			if (i >= b && i % *it == 0) {
				// puts("HERE");
				first[i - b] = max(first[i - b], *it);
				// events[i - b].PB(*it);
				// ++all;
			}
		}
	}
	// cout << "all = " << all << endl;
	for (int i = b; i <= a + 1; ++i) {
		father[i - b] = i - b;
		maxv[i - b] = i;
	}
	FILL(at, 0x3f);
	for (int i = b; i < a; ++i) {
		at[i + 1 - b] = min(at[i + 1 - b], i);
		{
			int v = first[i-b];
			if (v == -1) continue;
			// puts("HERE");
			int x = get(i + 1 - b);
			while (maxv[x] < i + v && maxv[x] <= a) {
				at[maxv[x] - b] = i;
				merge(x, maxv[x] + 1 - b);
				x = get(x);
			}
		}
	}
	// for (int i = b; i <= a; ++i) cout << "i = " << i << " at = " << at[i - b] << endl;
	int steps = 0;
	int x = a;
	while (x != b) {
		++steps;
		x = at[x - b];
	}
	cout << steps << endl;
	return 0;
}