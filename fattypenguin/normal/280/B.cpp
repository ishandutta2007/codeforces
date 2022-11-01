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

int a[200000];

struct Node {
	int ch[2];
	int size;
	Node() {
		ch[0] = ch[1] = 0;
		size = 0;
	}
} tree[100007 * 32];

int last;

void add(int num, int w) {
	int root = 1;
	for (int i = 30; i >= 0; --i) {
		tree[root].size += w;
		int t = (num & (1 << i)) ? 1 : 0;
		if (tree[root].ch[t] == 0) {
			tree[root].ch[t] = last;
			tree[last++] = Node();
		}

		root = tree[root].ch[t];
	}

	tree[root].size += w;
}

int solve(int a[], int n) {
	last = 2;
	tree[0].ch[0] = tree[0].ch[1] = tree[0].size = 0;
	tree[1].ch[0] = tree[1].ch[1] = tree[0].size = 0;
	stack<int> s;
	s.push(a[0]);
	add(a[0], 1);
	int ret = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i] > s.top()) {
			int res = 0;
			while (s.size() && a[i] > s.top()) {
				res = max(res, a[i]^s.top());
				s.pop();
			}

			ret = max(ret, res);
		}

		s.push(a[i]);
		add(a[i], 1);
	}

	return ret;
}

int main() {
	int n;
	cin >> n;
	REP(i, n) scanf("%d", &a[i]);	
	int res = solve(a, n);
	reverse(a, a + n);
	res = max(res, solve(a, n));
	cout << res << endl;
	return 0;
}