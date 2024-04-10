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

char res[2000000];

int main() {
	int n, k;
	cin >> n >> k;
	if (k > n) {
		puts("-1");
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		res[i] = 'a';
		if (i & 1) ++res[i];
	}

	if (k == 1) {
		if (n == 1) puts("a");
		else puts("-1");
		return 0;
	}

	if (n == k) {
		REP(i, k) {
			cout << (char)(i + 'a');
		}

			cout << endl;
		return 0;
	}

	int need = k - 2;
	int coff = 0;
	for (int i = n - need; i < n; ++i) {
		res[i] = 'c' + coff;
		++coff;
	}

	res[n] = 0;
	cout << res << endl;
	return 0;
}