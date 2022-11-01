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

char s[1000000];

int dp[2605][2605];
bool mem[2605][2605];

int dfs(int l, int r) {

	if (mem[l][r]) {
		return dp[l][r];
	}

	if (l > r) {
		return 0;
	}

	if (l == r) {
		return 1;
	}

	int &res = dp[l][r];

	res = -0x3f3f3f3f;
	mem[l][r] = true;

	res = max(dfs(l + 1, r), dfs(l, r - 1));
	if (s[l] == s[r]) {
		res = max(res, dfs(l + 1, r - 1) + 2);
	}

	return res;
}

string findResult(int l, int r) {
	if (dfs(l, r) == 0) return "";
	if (l > r) return "";
	if (l == r) {
		string ret = "";
		ret += s[l];
		return ret;
	}

	int ans = dfs(l, r);
	if (dfs(l + 1, r) == ans) {
		return findResult(l + 1, r);
	}

	if (dfs(l, r - 1) == ans) {
		return findResult(l, r - 1);
	}

	assert(s[l] == s[r]);
	string ret = "";
	ret += s[l];
	ret += findResult(l + 1, r - 1);
	ret += s[r];

	return ret;
}

int main() {
	scanf("%s", s);
	int length = strlen(s);
	if (length > 2600) {
		for (char c = 'a'; c <= 'z'; ++c) {
			int num = 0;
			REP(i, length) {
				if (s[i] == c) {
					++num;
				}
			}
			if (num >= 100) {
				REP(k, 100) cout << c;
				cout << endl;
				return 0;
			}
		}
	}

	int ans = dfs(0, length - 1);
	string result = findResult(0, length - 1);
	if (ans <= 100) {
		cout << result << endl;
		return 0;
	}

	int mid = (ans + 1) / 2;
	string right = "", left = "";
	for (int k = 0; k + mid < ans && k < 50; ++k) {
		left += result[k];
		string tmp = "";
		tmp += result[k];
		right = tmp + right;
	}

	cout << left + right << endl;
	return 0;
}