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

const int MAXN = 100007;

int n, l[MAXN], r[MAXN];

const int INSERT_EVENT = 0;
const int QUERY_EVENT = 1;

struct Event {
	int at;
	int type, idx;

	Event(int at, int type, int idx) : at(at), type(type), idx(idx) {
	}

	bool operator < (const Event &o) const {
		return at < o.at;
	}
};

int startPointLeft[MAXN], breakPointLeft[MAXN];
int startPointRight[MAXN], breakPointRight[MAXN];

int BIT1[MAXN * 4];
int BIT2[MAXN * 4];

void add(int x, int y, int BIT[]) {
	++x;
	while (x <= 4 * n) {
		BIT[x] += y;
		x += x & -x;
	}
}

int sum(int x, int BIT[]) {
	++x;
	int ret = 0;
	while (x) {
		ret += BIT[x];
		x -= x & -x;
	}

	return ret;
}

int main() {
	cin >> n;
	REP(i, n) {
		scanf("%d%d", &l[i], &r[i]);
		if (l[i] > r[i]) swap(l[i], r[i]);
		--l[i], --r[i];
	}

	CLEAR(BIT1);
	CLEAR(BIT2);

	vector<Event> events;
	REP(i, n) {
		events.PB(Event(l[i], QUERY_EVENT, i));
		events.PB(Event(r[i], INSERT_EVENT, i));
		add(l[i], 1, BIT1);
		add(r[i], 1, BIT2);
		// cout << "l[i] = " << l[i] << " r[i] = " << r[i] << endl;
	}

	SORT(events);

	TR(e, events) {
		int i = e->idx;
		if (e->type == INSERT_EVENT) {
		} else {
			add(l[i], -1, BIT1);
			add(r[i], -1, BIT2);

			startPointRight[e->idx] = sum(r[i], BIT1) - sum(l[i], BIT1);
			breakPointRight[e->idx] = sum(r[i], BIT2) - sum(l[i], BIT2);

			add(r[i], 1, BIT1);
			add(l[i], 1, BIT2);
		}
	}

	CLEAR(BIT1);
	CLEAR(BIT2);

	events.clear();
	REP(i, n) {
		events.PB(Event(r[i], QUERY_EVENT, i));
		events.PB(Event(l[i], INSERT_EVENT, i));
		add(r[i] + n * 2, 1, BIT2);
		add(l[i] + n * 2, 1, BIT1);
	}

	SORT(events);
	reverse(ALL(events));

	TR(e, events) {
		int i = e->idx;
		if (e->type == INSERT_EVENT) {
		} else {
			add(l[i] + n * 2, -1, BIT1);
			add(r[i] + n * 2, -1, BIT2);

			startPointLeft[e->idx] = sum(r[i] + n * 2, BIT1) - sum(l[i] + n * 2, BIT1);
			startPointLeft[e->idx] = sum(4 * n - 1, BIT1) - startPointLeft[e->idx];
			breakPointLeft[e->idx] = sum(r[i] + n * 2, BIT2) - sum(l[i] + n * 2, BIT2);
			breakPointLeft[e->idx] = sum(4 * n - 1, BIT2) - breakPointLeft[e->idx];

			add(r[i] + n * 2, 1, BIT1);
			add(l[i] + n * 2, 1, BIT2);
		}
	}

	long long notCross = 0, cross = 0;
	REP(i, n) {
		notCross += breakPointLeft[i] * (long long)breakPointRight[i];
		cross += (startPointRight[i] - breakPointRight[i]) * (long long)breakPointLeft[i];
		cross += (startPointLeft[i] - breakPointLeft[i]) * (long long)breakPointRight[i];
	}

	assert(cross % 2 == 0);

	cout << n * (n - 1ll) * (n - 2ll) / 6 - notCross - cross / 2 << endl;

	return 0;
}