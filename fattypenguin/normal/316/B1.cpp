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

int front[2222];
int dp[2222];
int vis[2222];

int degree[2222];
int n, m;

int go(int x) {
	int t = 0;
	while (x != -1) {
		++t;
		vis[x] = 1;
		x = front[x];
		if (vis[x]) return 0;
	}

	return t;
}

int main() {
	cin >> n >> m;
	--m;
	REP(i, n) {
		cin >> front[i];
		--front[i];
		if (front[i] != -1) ++degree[front[i]];
	}
	int now = go(m);
	vector<int> s;
	REP(i, n) {
		if (!vis[i] && degree[i] == 0) {
			s.PB(go(i));
		}
	}

	dp[0] = 1;
	TR(it, s) {
		for (int i = n; i >= *it; --i) {
			if (dp[i - *it]) dp[i] = 1;
		}
	}

	VI ans;
	REP(i, n + 1) {
		if (dp[i]) {
			ans.PB(i + now);
		}
	}

	SORT(ans);
	REP(i, ans.size()) {
		// if (i) printf(" ");
		cout << ans[i] << endl;;
	}
	// cout << endl;
	return 0;
}