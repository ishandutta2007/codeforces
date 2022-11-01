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

int sg1[200], sg2[200], sg3[200], sg4[200];
bool seen[55555];

void print(int x) {
	if (x) {
		cout << "WIN" << endl;
	} else {
		cout << "LOSE" << endl;
	}
}

int main() {
	sg1[1] = 1;
	sg1[2] = 0;

	sg2[1] = 1;
	sg2[2] = 2;

	sg3[1] = 1;
	sg3[2] = 0;

	sg4[1] = 0;
	sg4[2] = 1;

	for (int i = 3; i <= 100; ++i) {
		CLEAR(seen);
		seen[sg2[i - 1]] = 1;
		for (int j = 1; i - 1 - j > 0; ++j) {
			seen[sg2[j] ^ sg2[i - 1 - j]] = 1;
		}
		for (int j = 0; ; ++j) {
			if (!seen[j]) {
				sg1[i] = j;	
				break;
			}
		}

		CLEAR(seen);
		seen[sg2[i - 1]] = 1;
		seen[sg3[i - 1]] = 1;
		seen[sg4[i - 1]] = 1;
		for (int j = 1; i - 1 - j > 0; ++j) {
			seen[sg4[j] ^ sg2[i - 1 - j]] = 1;
			seen[sg3[j] ^ sg2[i - 1 - j]] = 1;
		}
		for (int j = 0; ; ++j) {
			if (!seen[j]) {
				sg2[i] = j;
				break;
			}
		}

		CLEAR(seen);
		seen[sg3[i - 1]] = 1;
		for (int j = 1; i - 1 - j > 0; ++j) {
			seen[sg3[j] ^ sg3[i - 1 - j]] = 1;
			seen[sg4[j] ^ sg4[i - 1 - j]] = 1;
		}
		for (int j = 0; ; ++j) {
			if (!seen[j]) {
				sg3[i] = j;
				break;
			}
		}

		CLEAR(seen);
		seen[sg4[i - 1]] = 1;
		for (int j = 1; i - 1 - j > 0; ++j) {
			seen[sg3[j] ^ sg4[i - 1 - j]] = 1;
		}
		for (int j = 0; ; ++j) {
			if (!seen[j]) {
				sg4[i] = j;
				break;
			}
		}
	}

	int n, k;
	vector<PII> res;
	cin >> n >> k;
	REP(i, k) {
		int x, y;
		cin >> x >> y;
		res.PB(MP(x, y));
	}

	SORT(res);
	if (!res.size()) {
		print(sg1[n]);
		return 0;
	}

	int ans = 0;
	ans = sg2[res[0].first - 1] ^ sg2[n - res.back().first];
	for (int i = 0; i + 1 < res.size(); ++i) {
		int delta = res[i + 1].first - res[i].first - 1;
		if (res[i].second == res[i + 1].second) {
			ans ^= sg3[delta];
		} else {
			ans ^= sg4[delta];
		}
	}

	print(ans);
	return 0;
}