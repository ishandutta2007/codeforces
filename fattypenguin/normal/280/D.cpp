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

struct Node {
	int minv, minvl, minvr;
	int maxv, maxvl, maxvr;
	int minl, minlat;
	int maxl, maxlat;
	int minr, minrat;
	int maxr, maxrat;
	int sum, l, r;
};

// int minv[MAXN * 4], minvl[MAXN * 4], minvr[MAXN * 4];
// int maxv[MAXN * 4], maxvr[MAXN * 4], maxvr[MAXN * 4];
// int minl[MAXN * 4], minlAt[MAXN * 4];
// int minr[MAXN * 4], minrAt[MAXN * 4];
// int maxl[MAXN * 4], maxlAt[MAXN * 4];
// int maxr[MAXN * 4], maxrAt[MAXN * 4];
// int sum[MAXN * 4], l[MAXN * 4], r[MAXN * 4];

bool rev[MAXN * 4];
Node node[MAXN * 4];

int arr[MAXN];

Node merge(const Node &a, const Node &b) {
	Node ret;

	ret.l = a.l;
	ret.r = b.r;
	ret.sum = a.sum + b.sum;

	if (a.minl < a.sum + b.minl) {
		ret.minl = a.minl;
		ret.minlat = a.minlat;
	} else {
		ret.minl = a.sum + b.minl;
		ret.minlat = b.minlat;
	}

	if (a.maxl > a.sum + b.maxl) {
		ret.maxl = a.maxl;
		ret.maxlat = a.maxlat;
	} else {
		ret.maxl = a.sum + b.maxl;
		ret.maxlat = b.maxlat;
	}

	if (b.minr < b.sum + a.minr) {
		ret.minr = b.minr;
		ret.minrat = b.minrat;
	} else {
		ret.minr = b.sum + a.minr;
		ret.minrat = a.minrat;
	}

	if (b.maxr > b.sum + a.maxr) {
		ret.maxr = b.maxr;
		ret.maxrat = b.maxrat;
	} else {
		ret.maxr = b.sum + a.maxr;
		ret.maxrat = a.maxrat;
	}

	if (a.minv < b.minv && a.minv < a.minr + b.minl) {
		ret.minv = a.minv;
		ret.minvl = a.minvl;
		ret.minvr = a.minvr;
	} else if (b.minv < a.minr + b.minl) {
		ret.minv = b.minv;
		ret.minvl = b.minvl;
		ret.minvr = b.minvr;
	} else {
		ret.minv = a.minr + b.minl;
		ret.minvl = a.minrat;
		ret.minvr = b.minlat;
	}

	if (a.maxv > b.maxv && a.maxv > a.maxr + b.maxl) {
		ret.maxv = a.maxv;
		ret.maxvl = a.maxvl;
		ret.maxvr = a.maxvr;
	} else if (b.maxv > a.maxr + b.maxl) {
		ret.maxv = b.maxv;
		ret.maxvl = b.maxvl;
		ret.maxvr = b.maxvr;
	} else {
		ret.maxv = a.maxr + b.maxl;
		ret.maxvl = a.maxrat;
		ret.maxvr = b.maxlat;
	}

	return ret;

}

void build(int left, int right, int x) {
	// cout << "left = " << left << " right = " << right << " x = " << x << endl;
	node[x].l = left;
	node[x].r = right;
	rev[x] = false;
	int mid = (left + right) >> 1;
	if (left < right) {
		build(left, mid, x * 2);
		build(mid + 1, right, x * 2 + 1);
		node[x] = merge(node[x * 2], node[x * 2 + 1]);
		// cout << "left = " << left << " right = " << right << " " << node[x * 2].l << " " << node[x * 2 + 1].r << endl;
	} else {
		node[x].minv = node[x].maxv = node[x].minl = 
		node[x].minr = node[x].maxl = node[x].maxr = arr[left];

		node[x].minvl = node[x].minvr = node[x].maxvl = node[x].maxvr = left;
		node[x].minlat = node[x].minrat = node[x].maxlat = node[x].maxrat = left;

		node[x].sum = arr[left];
	}

	// cout << "left = " << left << " right = " << right << " " << node[x].l << " " << node[x].r << endl;

}

void myNegate(int x) {
	swap(node[x].minv, node[x].maxv);
	swap(node[x].minvl, node[x].maxvl);
	swap(node[x].minvr, node[x].maxvr);
	swap(node[x].minl, node[x].maxl);
	swap(node[x].minlat, node[x].maxlat);
	swap(node[x].minr, node[x].maxr);
	swap(node[x].minrat, node[x].maxrat);

	node[x].minv = -node[x].minv;
	node[x].maxv = -node[x].maxv;
	node[x].minl = -node[x].minl;
	node[x].minr = -node[x].minr;
	node[x].maxl = -node[x].maxl;
	node[x].maxr = -node[x].maxr;
	node[x].sum = -node[x].sum;
}

void pushDown(int x) {
	if (!rev[x]) return;
	rev[x * 2] = !rev[x * 2];
	myNegate(x * 2);
	rev[x * 2 + 1] = !rev[x * 2 + 1];
	myNegate(x * 2 + 1);
	rev[x] = false;
}

Node getMin(int left, int right, int l, int r, int x) {
	if (l <= left && r >= right) {
		return node[x];
	}

	int mid = (left + right) >> 1;
	pushDown(x);
	if (l <= mid && r <= mid) {
		return getMin(left, mid, l, r, x * 2);
	} else if (l > mid && r > mid) {
		return getMin(mid + 1, right, l, r, x * 2 + 1);
	} else {
		Node u = getMin(left, mid, l, r, x * 2);
		return merge(u, getMin(mid + 1, right, l, r, x * 2 + 1));
	}
}

void myNegate(int left, int right, int l, int r, int x) {
	if (l <= left && r >= right) {
		rev[x] = !rev[x];
		myNegate(x);

		return;
	}

	int mid = (left + right) >> 1;
	pushDown(x);
	if (l <= mid) myNegate(left, mid, l, r, x * 2);
	if (r > mid) myNegate(mid + 1, right, l, r, x * 2 + 1);
	node[x] = merge(node[x * 2], node[x * 2 + 1]);
}

void modify(int left, int right, int pos, int x, int val) {
	//cout << "INFO: " << left << " " << right << " " << pos << " " << x << " " << val << endl;
	if (left == right) {
		node[x].minv = node[x].maxv = node[x].minl = 
		node[x].minr = node[x].maxl = node[x].maxr = node[x].sum = val;
		return;
	}

	int mid = (left + right) >> 1;
	pushDown(x);
	if (pos <= mid) {
		modify(left, mid, pos, x * 2, val);
	} else {
		modify(mid + 1, right, pos, x * 2 + 1, val);
	}

	node[x] = merge(node[x * 2], node[x * 2 + 1]);

}

int main() {
	int n;
	cin >> n;
	REP(i, n) scanf("%d", &arr[i]);
	build(0, n - 1, 1);
	//cout << node[1].l << " " << node[1].r << endl;
	//cout << node[1].minv << " " << node[1].maxv << endl;
	int q;
	cin >> q;
	while (q--) {
		int kind;
		scanf("%d", &kind);
		if (kind == 0) {
			int i, val;
			scanf("%d%d", &i, &val);
			--i;
			modify(0, n - 1, i, 1, val);
			continue;
		}

		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		--l; --r;

		vector< pair<int, int> > segment;
		int val = 0;
		for (int i = 0; i < k; ++i) {
			Node res = getMin(0, n - 1, l, r, 1);
			// cerr << "res.maxv = " << res.maxv << endl;
			if (res.maxv <= 0) break;
			val += res.maxv;
			segment.PB(MP(res.maxvl, res.maxvr));
			myNegate(0, n - 1, res.maxvl, res.maxvr, 1);
		}

		printf("%d\n", val);
		for (int i = (int)segment.size() - 1; i >= 0; --i) {
			myNegate(0, n - 1, segment[i].first, segment[i].second, 1);
		}
	}
	return 0;
}