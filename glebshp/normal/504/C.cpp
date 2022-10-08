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
const int size = 200 * 1000;

int num[size];
int n;
int cnt[size];
int g1, g2;
int h[size];

bool good(int lb, int rb) {
	for (int i = 0; i < n; i++)
		h[i] = 0;
	for (int i = lb; i <= rb; i++)
		h[num[i]]++;
	for (int i = 0; i < n / 2; i++) {
		int c = 0;
		if (i >= lb && i <= rb)
			c++;
		if (n - i - 1 >= lb && n - i - 1 <= rb)
			c++;
		if (c == 0 && num[i] != num[n - i - 1])
			return false;
		if (c == 1) {
			if (i >= lb && i <= rb)
				h[num[n - i - 1]]--;
			else
				h[num[i]]--;
		}
	}

	int odd = 0;
	for (int i = 0; i < n; i++) {
		if (h[i] < 0)
			return false;
		odd += h[i] & 1;
	}

	return odd <= 1;
}

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		num[i]--;
		cnt[num[i]]++;
	}

	int odd = 0;
	for (int i = 0; i < n; i++)
		odd += cnt[i] & 1;
	if (odd > 1) {
		cout << 0 << endl;
		return 0;
	}

	g1 = 0;
	while (g1 < n && num[g1] == num[n - 1 - g1])
		g1++;
	
	if (g1 == n) {
		cout << n * 1ll * (n + 1) / 2 << endl;
		return 0;
	}

	g2 = 0;
	int mid = n / 2;
	odd ^= 1;
	while (num[mid - odd - g2] == num[mid + g2])
		g2++;

	long long midlen = 2 * g2 - n & 1;
	long long seglen = n - midlen - 2 * g1;

	long long ans = (g1 + 1) * 1ll * (g1 + 1);
	int lb = g1;
	int rb = n - g1 - 1;
	while (lb < rb) {
		int mid = (lb + rb) / 2;
		if (good(g1, mid))
			rb = mid;
		else
			lb = mid + 1;
	}

	ans += (g1 + 1) * 1ll * (n - g1 - 1 - lb);

	lb = g1;
	rb = n - g1 - 1;
	while (lb < rb) {
		int mid = (lb + rb + 1) / 2;
		if (good(mid, n - g1 - 1))
			lb = mid;
		else
			rb = mid - 1;
	}

	ans += (g1 + 1) * 1ll * (lb - g1);

	cout << ans << endl;
	/*
	int ans2 = 0;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			ans2 += good(i, j);
	cout << ans2 << endl;
	*/
	return 0;
}