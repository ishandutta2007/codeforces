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
#define taskname "problem_c"

const double pi = acos(-1.0);
const long long inf = (long long) 1e15;

int n, m;
vector <long long> a, b;

bool check(long long k) {
	int p = 0;
	for (int i = 0; i < n; i++) {
		if (abs(a[i] - b[p]) > k)
			continue;
		int hp = p;
		while (hp < m && b[hp] <= a[i])
			hp++;
		while (hp < m && min(abs(a[i] - b[p]) + abs(b[p] - b[hp]), abs(a[i] - b[hp]) + abs(b[hp] - b[p])) <= k)
			hp++;
		p = hp;
	}

	return p == m;
}

int main() {
//	assert(freopen("input.txt", "r", stdin));
//	assert(freopen("output.txt", "w", stdout));
	
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		long long d;
		scanf("%I64d", &d);
		a.pb(d);
	}
	for (int i = 0; i < m; i++) {
		long long d;
		scanf("%I64d", &d);
		b.pb(d);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	long long lb = 0;
	long long rb = inf;
	while (lb < rb) {
		long long mid = (lb + rb) / 2;
		if (check(mid))
			rb = mid;
		else
			lb = mid + 1;
	}

	//if (check(lb))
	cout << lb << endl;

	return 0;
}