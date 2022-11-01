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

int a[100007];

int main() {
	int n;
	cin >> n;
	REP(i, n) cin >> a[i];
	sort(a, a + n);
	int ptr = 0;
	while (ptr < n && a[ptr] == 0) ++ptr;
	int ans = 0;
	for (int i = ptr; i < n; ) {
		int j = i;
		while (j < n && a[i] == a[j]) ++j;
		if (j - i > 2) ans = -1000000000;
		if (j - i == 2) ++ans;
		i = j;
	}
	if (ans < 0) ans = -1;
	cout << ans << endl;
	return 0;
}