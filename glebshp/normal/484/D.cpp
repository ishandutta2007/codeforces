#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <list>
#include <deque>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define taskname "task_d"

const double pi = acos(-1.0);
const int rms = (1 << 21) - 1;
const int hrms = rms / 2;
const int size = 2000 * 1000 + 10;
const int inf = 1000 * 1000 * 1000 + 10;

long long rmq[rms + 1];
long long rmqc[rms + 1];
int val[size];
int n;

void change(int v, int i, int j, int lb, int rb, long long d) {
	if (lb > j || rb < i)
		return;
	if (lb >= i && rb <= j) {
		rmqc[v] += d;
		rmq[v] += d;
		return;
	}
	change(v * 2, i, j, lb, (lb + rb) / 2, d);
	change(v * 2 + 1, i, j, (lb + rb) / 2 + 1, rb, d);

	rmq[v] = max(rmq[v * 2], rmq[v * 2 + 1]) + rmqc[v];
}

long long rss(int v, int i, int j, int lb, int rb) {
	if (lb > j || rb < i)
		return 0ll;
	if (lb >= i && rb <= j) {
		return rmq[v];
	}

	return max(rss(v * 2, i, j, lb, (lb + rb) / 2), rss(v * 2 + 1, i, j, (lb + rb) / 2 + 1, rb)) + rmqc[v];
}

int main() {
/*	
	freopen("input.txt", "w", stdout);
	int n = 1000 * 1000;
	cout << n << endl;
	for (int i = 0; i < n; i++)
		cout << rand() * 1ll * rand() % (1000 * 1000 * 1000) << ' ';
	return 0;
*/	
//	assert(freopen("input.txt", "r", stdin));
//	assert(freopen("output.txt", "w", stdout));
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &val[i]);
	}

	vector <pair <int, int> > mxvec;
	vector <pair <int, int> > mnvec;
	mxvec.pb(mp(inf, -1));
	mnvec.pb(mp(-inf, -1));
	long long cans = 0;
	for (int i = 0; i < n; i++) {
		while (val[i] >= mxvec.back().fs) {
			change(1, mxvec[(int) mxvec.size() - 2].sc + 1 + 1, mxvec.back().sc + 1, 1, hrms + 1, val[i] - mxvec.back().fs);
			mxvec.pop_back();
		}
		//change(1, mxvec.back().sc + 1, i, 1, hrms + 1, 
		mxvec.pb(mp(val[i], i));
		while (val[i] <= mnvec.back().fs) {
			change(1, mnvec[(int) mnvec.size() - 2].sc + 1 + 1, mnvec.back().sc + 1, 1, hrms + 1, mnvec.back().fs - val[i]);
			mnvec.pop_back();
		}
		mnvec.pb(mp(val[i], i));
		
		cans = rss(1, 1, i + 1, 1, hrms + 1);
		//cerr << cans << endl;
		int p = hrms + i + 2;
		rmq[p] = cans;
		while (p > 0) {
			p /= 2;
			rmq[p] = max(rmq[p * 2], rmq[p * 2 + 1]) + rmqc[p];
		}
	}

	printf("%I64d\n", cans);
//	printf("%.10lf\n", (clock() + 0.0) / CLOCKS_PER_SEC);

	return 0;
}