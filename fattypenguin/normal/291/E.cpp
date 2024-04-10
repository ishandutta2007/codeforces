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

string s[300007];
vector<int> edge[300007];
string res;

int pi[300007];

string next() {
	static char s[300007];
	scanf("%s", s);
	return string(s);
}

int ans;

void dfs(int x, int pos) {
	string &str = s[x];
	for (int i = 0; i < str.size(); ++i) {
		while (pos != -1 && res[pos + 1] != str[i]) {
			pos = pi[pos];
		}

		if (res[pos + 1] == str[i]) ++pos;

		if (pos + 1 == res.size()) {
			++ans;
			pos = pi[pos];
		}
	}

	TR(it, edge[x]) {
		dfs(*it, pos);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int p;
		scanf("%d", &p);
		--p;
		edge[p].PB(i);
		s[i] = next();
	}
	res = next();
	pi[0] = -1;
	for (int i = 1; i < res.size(); ++i) {
		int pre = pi[i - 1];
		while (pre != -1 && res[pre + 1] != res[i]) {
			pre = pi[pre];
		}

		pi[i] = pre;
		if (res[pre + 1] == res[i]) {
			++pi[i];
		}
	}

	ans = 0;
	dfs(0, -1);
	cout << ans << endl;
	return 0;
}