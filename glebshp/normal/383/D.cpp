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
#define taskname "problem_d"

const double pi = acos(-1.0);
const int size = 25 * 1000;
const int mdl = 1000 * 1000 * 1000 + 7;
const long long mdl2 = mdl * 1ll * mdl;

int a[size];
long long ans = 0;
int cur1[2][size];
int cur2[2][size];
int tot1[size];
int tot2[size];

void calc(int lb, int rb) {
	if (lb >= rb)
		return;
	int mid = (lb + rb) / 2;

	int sum1 = 0;
	for (int i = mid + 1; i <= rb; i++) {
		sum1 += a[i];	
	}
	for (int i = 0; i <= 2 * sum1; i++)
		tot1[i] = 0;

	int cs1 = 0;
	int ptr = 0;
	cur1[ptr][sum1] = 1;
	for (int i = mid + 1; i <= rb; i++) {
		cs1 += a[i];
		for (int j = sum1 - cs1; j <= sum1 + cs1; j++)
			cur1[ptr ^ 1][j] = 0;
		for (int j = sum1 - cs1 + a[i]; j <= sum1 + cs1 - a[i]; j++)
			if (cur1[ptr][j] != 0) {
				cur1[ptr ^ 1][j + a[i]] += cur1[ptr][j];
				if (cur1[ptr ^ 1][j + a[i]] >= mdl)
					cur1[ptr ^ 1][j + a[i]] -= mdl;
				cur1[ptr ^ 1][j - a[i]] += cur1[ptr][j];
				if (cur1[ptr ^ 1][j - a[i]] >= mdl)
					cur1[ptr ^ 1][j - a[i]] -= mdl;
			}
		ptr ^= 1;

		for (int j = sum1 - cs1; j <= sum1 + cs1; j++) {
			tot1[j] += cur1[ptr][j];
			if (tot1[j] >= mdl)
				tot1[j] -= mdl;
		}
	}

	int sum2 = 0;
	for (int i = mid; i >= lb; i--) {
		sum2 += a[i];	
	}
	for (int i = 0; i <= 2 * sum2; i++)
		tot2[i] = 0;

	int cs2 = 0;
	ptr = 0;
	cur2[ptr][sum2] = 1;
	for (int i = mid; i >= lb; i--) {
		cs2 += a[i];
		for (int j = sum2 - cs2; j <= sum2 + cs2; j++)
			cur2[ptr ^ 1][j] = 0;
		for (int j = sum2 - cs2 + a[i]; j <= sum2 + cs2 - a[i]; j++)
			if (cur2[ptr][j] != 0) {
				cur2[ptr ^ 1][j + a[i]] += cur2[ptr][j];
				if (cur2[ptr ^ 1][j + a[i]] >= mdl)
					cur2[ptr ^ 1][j + a[i]] -= mdl;
				cur2[ptr ^ 1][j - a[i]] += cur2[ptr][j];
				if (cur2[ptr ^ 1][j - a[i]] >= mdl)
					cur2[ptr ^ 1][j - a[i]] -= mdl;
			}
		ptr ^= 1;

		for (int j = sum2 - cs2; j <= sum2 + cs2; j++) {
			tot2[j] += cur2[ptr][j];
			if (tot2[j] >= mdl)
				tot2[j] -= mdl;
		}
	}

	for (int i = sum1 - min(cs1, cs2); i <= sum1 + min(cs1, cs2); i++) {
		ans += tot1[i] * 1ll * tot2[sum2 - (i - sum1)];
		if (ans >= mdl2)
			ans -= mdl2;
	}

	ans %= mdl;

	calc(lb, mid);
	calc(mid + 1, rb);
}

int main() {
	int n;

	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	calc(0, n - 1);

	cout << ans << endl;


	return 0;
}