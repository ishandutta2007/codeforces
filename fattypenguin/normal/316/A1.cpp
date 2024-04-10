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

char s[1000000];

int used[555];
int c[555];

int main() {
	scanf("%s", s);
	int n = strlen(s);
	int unknown = 0, diffChars = 0;;
	REP(i, n) {
		if (s[i] == '?') ++unknown;
		else if (isdigit(s[i])) {
			++c[s[i] - '0'];
		} else {
			if (!used[s[i]]) {
				++diffChars;
				used[s[i]] = 1;
			}
		}
	}

	if (s[0] == '0') {
		puts("0");
		return 0;
	}

	long long base = 1;

	if (s[0] == '?') {
		base = 9;
		--unknown;
	}

	if (isupper(s[0])) {
		base = 9;
		REP(i, diffChars - 1) base *= 9 - i;
	} else {
		REP(i, diffChars) base *= 10 - i;
	}
	cout << base;
	REP(i, unknown) cout << "0";
	cout << endl;
	return 0;
}