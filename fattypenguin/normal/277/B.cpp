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

int main() {
	int n, m;
	cin >> n >> m;
	if (m == 3) {
		if (n == 3) {
			printf("0 0\n3 0\n0 3\n");
			return 0;
		}
		if (n == 4) {

			printf("0 0\n100 0\n0 100\n20 20\n");
			return 0;
		}
		cout << -1 << endl;
		return 0;
	}

	double angle = 2 * acos(-1.0) / m;
	const double per = angle;
	angle = 0;
	for (int i = 0; i < m; ++i) {
		int x = (int)(99999999 * cos(angle));
		int y = (int)(99999999 * sin(angle));

		cout << x << " " << y << endl;

		angle += per;
	}

	angle = 0.01;
	for (int i = 0; i < n - m; ++i) {
		int x = (int)(12368 * cos(angle))+5;
		int y = (int)(12368 * sin(angle));

		cout << x << " " << y << endl;

		angle += per;

	}
	return 0;
}