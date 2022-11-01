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

vector<char> digit;
vector<string> res;

char t[3333];
char ss[333];

void go(int depth, int now, int length, int used) {
	if (length - now > (4 - depth) * 3) return;
	if (depth == 4) {
		res.push_back(string(ss, 0, used - 1));
		return;
	}

	int total = 0;
	for (int k = 0; k < 3 && k + now < length; ++k) {
		if (k > 0 && total == 0) break;
		total = total * 10 + t[k + now] - '0';
		if (total > 255) break;
		ss[used + k] = t[k + now];
		ss[used + k + 1] = '.';
		go(depth + 1, now + k + 1, length, used + k + 1 + 1);
	}
}

void check(int length) {
	t[length] = 0;
	//cout << t << endl;
	go(0, 0, length, 0);
}

void dfs(int depth, int mask) {
	//check
	if (mask + 1 == (1 << (int)(digit.size()))) {
		for (int i = 0; i < depth - 1; ++i) {
			t[depth + i] = t[depth - 2 - i];
		}
		check(depth * 2 - 1);
		for (int i = 0; i < depth; ++i) {
			t[depth + i] = t[depth - 1 - i];
		}
		check(depth * 2);
	}
	if (depth == 6) return;
	REP(i, digit.size()) {
		t[depth] = digit[i];
		dfs(depth + 1, mask | (1 << i));
	}
}

int main() {
	int n;
	cin >> n;
	digit.resize(n);
	REP(i, n) {
		int t;
		cin >> t;
		digit[i] = t + '0';
	}
	dfs(0, 0);
	SORT(res);
	res.erase(unique(ALL(res)), res.end());
	cout << res.size() << endl;
	TR(it, res) {
		cout << *it << endl;
	}


	return 0;
}