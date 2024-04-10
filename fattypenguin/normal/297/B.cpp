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
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
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

MII a, b;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	REP(i, n) {
		int x;
		scanf("%d", &x);
		++a[x];
	}
	REP(i, m) {
		int x;
		scanf("%d", &x);
		++b[x];
	}

	VI x, y;

	TR(it, a) {
		int v = it->first;
		int delta = 0;
		if (b.find(v) != b.end()) delta = b[v];
		if (delta < it->second) {
			delta = it->second - delta;
			REP(i, delta) x.PB(it->first);
		}
	}

	TR(it, b) {
		int v = it->first;
		int delta = 0;
		if (a.find(v) != a.end()) delta = a[v];
		if (delta < it->second) {
			delta = it->second - delta;
			REP(i, delta) y.PB(it->first);
		}
	}

	VI &a = x, &b = y;

	bool win = false;
	if (a.size() > b.size()) {
		win = true;
	} else if (a.size()){
		SORT(a); SORT(b);
		if (a.back() > b.back()) {
			win = true;
		} else {
			int ptr = (int)b.size() - 1;
			int delta = 0;
			for (int i = (int)a.size() - 1; i >= 0; --i) {
				++delta;
				while (ptr >= 0 && b[ptr] >= a[i]) {
					--ptr;
					--delta;
				}

				if (delta > 0) {
					win = true;
					break;
				}
			}
		}
	}

	if (win) cout << "YES" << endl; else cout << "NO" << endl;
	return 0;
}