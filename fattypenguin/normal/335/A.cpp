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
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
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

char s[2000];
int occurance[2000];

char ans[2000];

int main() {
	cin >> s;
	int n = strlen(s);
	REP(i, n) ++occurance[s[i] - 'a'];

	int len;
	cin >> len;
	for (int occ = 1; occ <= n; ++occ) {
		int needLength = 0;
		REP(j, 26) {
			needLength += (occurance[j] + occ - 1) / occ;
		}

		if (needLength <= len) {
			int m = 0;
			REP(j, 26) {
				int step = (occurance[j] + occ - 1) / occ;
				REP(k, step) {
					ans[m++] = j + 'a';
				}
			}

			while (m < len) {
				ans[m++] = 'a';
			}

			ans[m] = 0;
			cout << occ << endl << ans << endl;
			return 0;
		}
	}

	cout << -1 << endl;
	return 0;
}