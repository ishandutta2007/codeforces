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

const int MAXN = 200007;

bool cover[MAXN * 4];
int tag[MAXN * 4];

void push_down(int x) {
	if (cover[x]) {
		cover[x * 2] = cover[x * 2 + 1] = true;
		tag[x * 2] = tag[x * 2 + 1] = tag[x];
		cover[x] = false;
	}
}

void insert(int left, int right, int l, int r, int x, int id) {
	if (l <= left && r >= right) {
		cover[x] = true;
		tag[x] = id;
		return;
	}

	push_down(x);
	int mid = (left + right) >> 1;
	if (l <= mid) insert(left, mid, l, r, x * 2, id);
	if (r > mid) insert(mid + 1, right, l, r, x * 2 + 1, id);


}

int get(int left, int right, int aim, int x) {
	if (left == right) return tag[x];

	push_down(x);
	int mid = (left + right) >> 1;
	if (aim <= mid) return get(left, mid, aim, x * 2);
	return get(mid + 1, right, aim, x * 2 + 1);
}

int from[MAXN], beg[MAXN];
int a[MAXN], b[MAXN], n, m;

int main() {
	FILL(tag, -1);
	cin >> n >> m;
	REP(i, n) scanf("%d", &a[i]);
	REP(i, n) scanf("%d", &b[i]);
	REP(i, m) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int x, y, k;
			scanf("%d%d%d", &x, &y, &k);
			--x; --y;
			insert(0, n - 1, y, y + k - 1, 1, i);
			from[i] = x;
			beg[i] = y;
		} else {
			int x;
			scanf("%d", &x);
			--x;
			int z = get(0, n - 1, x, 1);
			int ans = 0;
			if (z == -1) ans = b[x];
			else {
				ans = a[from[z] + x - beg[z]];
			}
			cout << ans << endl;
		}
	}
	return 0;
}