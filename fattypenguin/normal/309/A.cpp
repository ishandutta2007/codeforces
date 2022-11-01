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

int pos[3000006];

int main() {
	int n, l, t;
	cin >> n >> l >> t;
	REP(i, n) scanf("%d", &pos[i]);
	t *= 2;
	int r = t / l;
	int x = t % l;
	REP(i, n) pos[i + n] = pos[i] + l;

	double ans = r * (double)n * (n - 1.0) / 4.0;
	int ptr = 0;
	for (int i = n; i < 2 * n; ++i) {
		while (ptr < i && pos[i] - pos[ptr] > x) ++ptr;
		int length = i - ptr;
		ans += length / 4.0;
	}

	printf("%.10f\n", ans);

	return 0;
}