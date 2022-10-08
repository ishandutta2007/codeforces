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
const int size = 2 * 1000 * 1000 + 1000;

int n, k;
int nx[size];
int prv[size];
bool used[size];
int val[size];

bool check(int val) {
	int lst = 0;
	for (int i = 1; i * val < size; i++) {
		if (prv[i * val - 1] != -1 && prv[i * val - 1] - (i - 1) * val > k)
			return false;
	}

	return true;
}

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d%d", &n, &k);
	int mn = size;
	for (int i = 0; i < n; i++) {
		scanf("%d", &val[i]);
		mn = min(mn, val[i]);
		used[val[i]] = true;
	}

	int lst = -1;
	for (int i = size - 1; i >= 0; i--) {
		if (used[i])
			lst = i;
		nx[i] = lst;
	}
	
	lst = -1;
	for (int i = 0; i < size; i++) {
		if  (used[i])
			lst = i;
		prv[i] = lst;
	}

	int ans = 1;
	for (int i = 2; i <= mn; i++)
		if (check(i))
			ans = i;
	
	cout << ans << endl;
	
	return 0;
}