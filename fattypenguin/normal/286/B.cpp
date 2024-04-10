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

int a[4222222];
int first[4222222];
int next[4222222];
int v[4222222];
int lastEdge[4222222];

int main() {

	int n;
	cin >> n;
	FILL(first, -1);
	for (int i = 1; i <= n; ++i) {
		first[i] = i;
		next[i] = -1;
		v[i] = i;
		lastEdge[i] = i;
	}

	for (int i = 2; i <= n; ++i) {
		int maxi = 2 * n + 2;
		//(p - k) % i == 1
		//p % i == 1 + k;
		int k = i - 2;
		int mod = (1 + k) % i;
		int last = mod;
		while (last + i <= 2 * n) last += i;

		int lastDelta = n % i;

		for (; last >= 1; last -= i) {
			if (first[last] == -1) continue;
			int delta = i;
			if (last > n + k - n % i) delta = lastDelta;
			if (first[last + delta] == -1) {
				first[last + delta] = first[last];
				lastEdge[last + delta] = lastEdge[last];
				first[last] = -1;
				continue;
			} else {
				next[lastEdge[last + delta]] = first[last];
				lastEdge[last + delta] = lastEdge[last];
				first[last] = -1;
			}
		}
	}

	for (int i = 1; i <= 2 * n + 2; ++i) {
		for (int p = first[i]; p != -1; p = next[p]) {
			// cout << "i = " << i << " p = " << p << " v[i] = " << v[p] << endl;
			a[i - n + 1] = v[p];
		}
	}

	for (int i = 1; i <= n; ++i) cout << a[i] << " ";
	return 0;
}