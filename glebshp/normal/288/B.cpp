#pragma comment(linker, "/STACK:1000000000")
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
const long long mdl = 1000 * 1000 * 1000 + 7;
const int size = 1000 + 10;

long long ans = 0;
int p[size];
bool used[size], could[size];

inline bool check(int k) {
	for (int i = 0; i < k; i++) {
		used[i] = false;
	}
	int pt = 0;
	while (!used[pt]) {
		used[pt] = true;
		pt = p[pt];
	}
	if (pt != 0)
		return false;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++) 
			if (used[p[j]]) {
				used[j] = true;
			}

	for (int i = 0; i < k; i++)
		if (!used[i])
			return false;

	return true;
}

inline void rec(int ps, int k) {
	if (ps == k) {
		ans += check(k);
		return;
	}
	if (ps == 0) {
		for (int i = 0; i < k; i++) {
			p[ps] = i;
			rec(ps + 1, k);
		}
	} else {
		for (int i = 1; i < k; i++) {
			p[ps] = (ps + i) % k;
			rec(ps + 1, k);
		}
	}
}

int main() {
	int n, k;
	vector <int> h;
	
	//freopen("problem_b.in", "r", stdin);
	//freopen("problem_b.out", "w", stdout);
	
	cin >> n >> k;
	rec(0, k);

	for (int i = k; i < n; i++)
		ans = (ans * (n - k)) % mdl;

	cout << ans << endl;

	return 0;
}