#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
const double pi = acos(-1.0);
const int iter = 60;
const double eps = 1e-7;
const int size = 100 * 1000 + 100;
const int rms = (1 << 18) - 1;
const int hrms = rms / 2;
const long long inf = (long long) 1e15;

long long x[size], y[size];
int n;
bool used[size];
long long lefts[rms + 1];
long long rights[rms + 1];

inline long long mabs(long long d) {
	if (d < 0)
		return -d;
	else
		return d;
}

void turnon(int ps, long long m) {
	lefts[ps + hrms + 1] = x[ps] - y[ps] - m;
	rights[ps + hrms + 1] = x[ps] - y[ps] + m;
	ps += hrms + 1;
	long long ov1, ov2;
	while (ps > 1) {
		ps /= 2;
		ov1 = lefts[ps];
		ov2 = rights[ps];
		if (lefts[ps * 2] > lefts[ps * 2 + 1])
			lefts[ps] = lefts[ps * 2];
		else
			lefts[ps] = lefts[ps * 2 + 1];
		if (rights[ps * 2] < rights[ps * 2 + 1])
			rights[ps] = rights[ps * 2];
		else
			rights[ps] = rights[ps * 2 + 1];
		if (lefts[ps] == ov1 && rights[ps] == ov2)
			break;
	}
}

void turnoff(int ps) {
	lefts[ps + hrms + 1] = -inf;
	rights[ps + hrms + 1] = inf;
	ps += hrms + 1;
	long long ov1, ov2;
	while (ps > 1) {
		ps /= 2;
		ov1 = lefts[ps];
		ov2 = rights[ps];
		if (lefts[ps * 2] > lefts[ps * 2 + 1])
			lefts[ps] = lefts[ps * 2];
		else
			lefts[ps] = lefts[ps * 2 + 1];
		if (rights[ps * 2] < rights[ps * 2 + 1])
			rights[ps] = rights[ps * 2];
		else
			rights[ps] = rights[ps * 2 + 1];
		if (lefts[ps] == ov1 && rights[ps] == ov2)
			break;
	}
}

vector <pair <long long, int> > eventOpen, eventClose;

long long eventCloseVal[size];
long long eventCloseNum[size];
long long eventOpenVal[size];
long long eventOpenNum[size];

double check(long long m) {
	for (int i = 0; i <= rms; i++) {
		lefts[i] = -inf;
		rights[i] = inf;
	}
	for (int i = 0; i < n; i++) {
		lefts[i + hrms + 1] = x[i] - y[i] - m;
		rights[i + hrms + 1] = x[i] - y[i] + m;
	}
	for (int i = hrms; i > 0; i--) {
		lefts[i] = max(lefts[i * 2], lefts[i * 2 + 1]);
		rights[i] = min(rights[i * 2], rights[i * 2 + 1]);
	}

	if (lefts[1] <= rights[1])
		return true;
	
	int p = 0, nm;
	for (int i = 0; i < n; i++) {
		turnoff(eventOpenNum[i]);

		while (p < n && eventCloseVal[p] + m < eventOpenVal[i] - m) {
			turnon(eventCloseNum[p], m);
			p++;
		}

		if (lefts[1] <= rights[1])
			return true;
	}

	return false;
}

int main() {
	/*
	freopen("problem_d.in", "w", stdout);
	printf("100000\n");
	for (int i = 0; i < 100000; i++)
		printf("%d %d\n", rand(), rand());
	return 0;
	*/

	//freopen("problem_d.in", "r", stdin);
	//freopen("problem_d.out", "w", stdout);
	
	scanf("%d", &n);

	long long lb = 0;
	long long rb = 0;

	for (int i = 0; i < n; i++) {
		scanf("%I64d%I64d", &x[i], &y[i]);
		x[i] *= 2;
		y[i] *= 2;
		rb = max(rb, max(mabs(x[i] + y[i]), mabs(x[i] - y[i])));
	}

	for (int i = 0; i < n; i++) {
		eventOpen.pb(mp(x[i] + y[i], i));
		eventClose.pb(mp(x[i] + y[i], i));
	}
	sort(eventOpen.begin(), eventOpen.end());
	sort(eventClose.begin(), eventClose.end());
	for (int i = 0; i < n; i++) {
		eventOpenNum[i] = eventOpen[i].sc;
		eventOpenVal[i] = eventOpen[i].fs;
		eventCloseVal[i] = eventClose[i].fs;
		eventCloseNum[i] = eventClose[i].sc;
	}

	while (lb < rb) {	
		long long mid = (lb + rb) / 2;
		cerr << mid << endl;
		if (check(mid))
			rb = mid;
		else
			lb = mid + 1;
	}

	cout.precision(20);
	cout << lb / 2.0 << endl;

	return 0;
}