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

int b, d;
string s, t;

ll nex[222][100];

ll nextChar[222][26];

ll go(int times) {
	ll ret = 0;
	for (int i = 30; i >= 0; --i) {
		if (times & (1 << i)) {
			ret += nex[ret % (ll)s.size()][i];
		}
	}

	return ret;
}

int main() {
	cin >> b >> d >> s >> t;
	REP(i, s.size()) {
		REP(j, 26) {
			int dis = 0;
			while (dis < s.size() && s[(i + dis) % s.size()] != j + 'a') ++dis;
			if (dis >= s.size()) {
				nextChar[i][j] = -1;
			} else {
				nextChar[i][j] = dis;
			}
			// printf("next[%d,%c] = %d\n", i, j+'a', dis);
		}
	}

	REP(i, s.size()) {
		int ch = 0;
		REP(j, t.size()) {
			if (nextChar[(i + ch) % s.size()][t[j] - 'a'] == -1) {
				ch = -1;
				break;
			}
			ch += nextChar[(i + ch) % s.size()][t[j] - 'a'];
			++ch;
		}
		nex[i][0] = ch;
		// cout << "next[i] = " << nex[i][0] << endl;
	}

	for (int i = 1; i < 33; ++i) {
		REP(j, s.size()) {
			if (nex[j][i - 1] != -1) {
				nex[j][i] = nex[j][i - 1] + nex[(j + nex[j][i - 1]) % (int)s.size()][i - 1];
			}
		}
	}

	if (nex[0][0] == -1) {
		puts("0");
		return 0;
	}

	int low = 0, high = (ll)s.size() * b / (ll)t.size();
	while (low < high) {
		int mid = ((low + high) >> 1) + 1;
		if (go(mid) <= (ll)s.size() * (ll)b) {
			low = mid;
		} else {
			high = mid - 1;
		}
	}
	// cout << "s.size() = " << s.size() << endl;
	// cout << "high = " << high << " " << go(high) << endl;

	cout << high / d << endl;
	return 0;
}