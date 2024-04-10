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
#define taskname "task_c"

const double pi = acos(-1.0);
const int size = 300 * 1000 + 100;
int n;

bool prime[size];
bool used[size];
int cur[size];

bool check(int n) {
	for (int i = 0; i < n; i++)
		used[i] = false;
	int c = 1;
	for (int i = 0; i < n; i++) {
		c = (c * 1ll * cur[i]) % n;
		if (used[c])
			return false;
		used[c] = true;
	}

	return true;
}

bool rec(int ps, int n, int val) {
	if (ps == n - 1) {
		for (int i = 0; i < n - 1; i++)
			printf("%d ", cur[i]);
		printf("%d\n", n);

		return true;
	}
	if (ps == 0) {
		cur[ps] = 1;
		used[1] = true;
		return rec(ps + 1, n, 1);
	}
	
}

int pwr(int a, int b, int mdl) {
	if (b == 0)
		return 1;
	int d = pwr(a, b / 2, mdl);
	d = (d * 1ll * d) % mdl;
	if (b & 1)
		d = (d * 1ll * a) % mdl;
	return d;
}

int main() {
//	assert(freopen("input.txt", "r", stdin));
//	assert(freopen("output.txt", "w", stdout));
	
	cin >> n;

	if (n == 4) {
		printf("YES\n");
		printf("1 3 2 4\n");
	
		return 0;
	}
	

	for (int i = 0; i <= n; i++)
		prime[i] = true;
	prime[0] = false;
	prime[1] = true;
	for (int i = 2; i * i <= n; i++) {
		if (prime[i]) {
			for (int j = i; i * j <= n; j++) {
				prime[i * j] = false;
			}
		}
	}

	vector <int> p;
	for (int i = 2; i <= n - 1; i++)
		p.pb(i);

	/*
	do {
		if (check(p, n)) {
			for (int i = 0; i < n; i++)
				printf("%d ", p[i]);
			printf("\n");
		}
	} while (next_permutation(p.begin(), p.end()));
	*/
	//rec(0, n, 1);

	if (prime[n]) {
		printf("YES\n");
		
		cur[0] = 1;
		for (int i = 2; i < n; i++)
			cur[i - 1] = (i * 1ll * pwr(i - 1, n - 2, n)) % n;
		cur[n - 1] = n;

		assert(check(n));

		for (int i = 0; i < n; i++)
			printf("%d ", cur[i]);
		printf("\n");
	} else
		printf("NO\n");

	return 0;
}