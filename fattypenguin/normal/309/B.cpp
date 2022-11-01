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

char buffer[5000007];
string words[1000007];
int length[1000007];
int sum[1000007];
int n, r, c;
int next[1000007];

int go[1000007][20];

int main() {
	cin >> n >> r >> c;
	REP(i, n) {
		scanf("%s", buffer);
		words[i] = string(buffer);
		length[i] = words[i].size();
		sum[i + 1] = sum[i] + length[i];
	}

	int right = 0;
	REP(i, n) {
		right = max(right, i);
		while (right < n) {
			int nextLength = sum[right + 1] - sum[i] + right - i;
			if (nextLength <= c) {
				++right;
			} else {
				break;
			}
		}

		next[i] = right;
	}

	next[n] = n;
	REP(i, n + 1) go[i][0] = next[i];
	for (int j = 1; j < 20; ++j) {
		REP(i, n + 1) {
			go[i][j] = go[go[i][j - 1]][j - 1];
		}
	}

	int ans = 0, at = 0;
	REP(i, n) {
		int right = i;
		for (int j = 0; j < 20; ++j) {
			if (r & (1 << j)) {
				right = go[right][j];
			}
		}

		if (right - i > ans) {
			ans = right - i;
			at = i;
		}
	}

	for (int i = at; i < n && r; --r) {
		if (length[i] > c) break;
		int rest = c;
		bool first = true;
		while (i < n && rest >= length[i]) {
			if (!first) printf(" ");
			printf("%s", words[i].c_str());
			rest -= length[i] + 1;
			++i;
			first = false;
		}
		puts("");
	}
	return 0;
}