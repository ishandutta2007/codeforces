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

int p[200000];
int n;

int main() {
	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	if (n % 4 == 2 || n % 4 == 3) {
		cout << -1 << endl;
		return 0;
	}
	if (n % 2 == 1) p[n / 2 + 1] = n / 2 + 1;
	int p1 = 1, p2 = n / 2, p3 = (n + 1)/ 2 + 1, p4 = n;
	int l = 1, r = n;
	REP(i, n / 4) {
		p[p1++] = p2;
		p[p2--] = p4;
		p[p3++] = p1 - 1;
		p[p4--] = p3 - 1;
	}

	REP(i, n) cout << p[i+1] << " ";
	return 0;
}