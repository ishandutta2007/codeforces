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

int n, k;

int res = 0;

int arr[100];
bool vis[100];
bool can[100];

bool go(int x) {
	if (vis[x]) return can[x];
	if (x == 0) return true;
	vis[x] = true;
	can[x] = false;
	if (go(arr[x])) can[x] = true;
	return can[x];
}

void dfs(int depth) {
	if (depth == k) {
		//if (arr[0] == 0) return;
		REP(i, k) vis[i] = can[i] = false;
		bool good = true;
		REP(i, k) {
			if (!go(i)) {
				good = false;
				break;
			}
		}
		if (good) ++res;

		return;
	}

	REP(i, k) {
		arr[depth] = i;
		dfs(depth + 1);
	}
}

int main() {
	cin >> n >> k;
	dfs(0);
	long long ans = res;
	for (int i = 0; i < n - k; ++i) {
		ans = ans * (n - k) % 1000000007;
	}

	cout << ans << endl;
	return 0;
}