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

char s[2000000], t[2000000];

int main() {
	int n;
	cin >> n;
	n *= 2;
	scanf("%s%s", s, t);
	int a, b, c;
	a = b = c = 0;
	REP(i, n) {
		if ('1' == s[i] && s[i] == t[i]) {
			++c;
		} else if ('1' == s[i]) {
			++a;
		} else if ('1' == t[i]) {
			++b;
			// cout << "1";
		}
	}
	if (c % 2 == 1) ++a;
	if (a + 1 == b || a == b) {
		cout << "Draw\n";
	} else if (a >= b) {
		cout << "First\n";
	} else cout << "Second\n";
	return 0;
}