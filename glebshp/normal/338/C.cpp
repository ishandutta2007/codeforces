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
const int size = 8;
const long long inf = (long long) 1e18;
const int sminf = 1000 * 1000 * 1000;

int n;
long long a[size];
int cnt[size];

int calcprimes(long long val) {
	long long hval = val;
	int ans = 0;
	for (long long i = 2; i * i <= val; i++) {
		while (hval % i == 0) {
			ans++;
			hval /= i;
		}
	}

	if (hval > 1)
		ans++;
	return ans;
}

long long getmask(int mask) {
	long long val = 1;
	for (int i = 0; i < n; i++)
		if ((mask >> i) & 1) {
			if (inf / a[i] >= val)
				val *= a[i];
			else
				val = inf;
		}
	return val;
}

//int ans[1 << size][1 << size];
//int jtg[1 << size][1 << size];

vector <long long> vc;
int glans = sminf;
long long cur[size];
int curc[size];
int gt[size];

void rec(int ps) {
	if (ps == n) {
		int sum = n;
		for (int i = 0; i < n; i++)
			sum += curc[i];
		int fg = 0;
		for (int i = 0; i < n; i++)
			if (gt[i] == -1)
				fg++;
		if (fg > 1)
			sum++;
		for (int i = 0; i < n; i++)
			if (cnt[vc[i]] == 1)
				sum--;
		glans = min(glans, sum);
		return;
	}

	gt[ps] = -1;
	rec(ps + 1);
	for (int i = 0; i < ps; i++)
		if (cur[i] % cur[ps] == 0) {
			cur[i] /= cur[ps];
			curc[i] -= curc[ps];
			gt[ps] = i;
			rec(ps + 1);
			gt[ps] = -1;
			curc[i] += curc[ps];
			cur[i] *= cur[ps];
		}
}

int main() {
	double tm = clock();

	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[i] = calcprimes(a[i]);
	}

	for (int i = 0; i < n; i++)
		vc.pb(i);
	//sort(vc.begin(), vc.end());
	do {
		for (int i = 0; i < n; i++) {
			cur[i] = a[vc[i]];
			curc[i] = cnt[vc[i]];
		}
		bool flag = true;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (cur[j] % cur[i] == 0)
					flag = false;
		if (flag)
			rec(0);
	} while (next_permutation(vc.begin(), vc.end()));

	cout << glans << endl;

	/*
	for (int i = 0; i < (1 << n); i++)
		for (int j = 0; j < (1 << n); j++)
			ans[i][j] = sminf;
	*/
	/*
	for (int i = 1; i < (1 << n); i++)
		for (int j = i; j > 0; j = (j - 1) & i) {
			for (int k = 0; k < n; k++)
				if (j == (1 << k)) {
					
				}
		}
	*/
	
	/*
	for (int i = 1; i < (1 << n); i++)
		justtoget[i] = sminf;
	for (int i = 1; i < (1 << n); i++) {
		justtoget[i] = 0;
		for (int j = 0; j < n; j++)
			if ((i >> j) & 1)
				justtoget[i] += cnt[j] + 1;
		for (int j = i; j > 0; j = (j - 1) & i)
			justtoget[i] = min(justtoget[i], justtoget[j] + justtoget[i ^ j]);
		ans[i] = justtoget[i] + 1;
		for (int j = 0; j < n; j++)
			if ((i >> j) & 1) {
				if (a[j] % getmask(i ^ (1 << j)) == 0) {
					int hc = cnt[j];
					for (int k = 0; k < n; k++)
						if (k != j && ((i >> k) & 1))
							hc -= cnt[k];
					ans[i] = min(ans[i], hc + 1 + justtoget[i ^ (1 << j)]);
				}
			}
		justtoget[i] = min(justtoget[i], ans[i]);
		cout << i << ' ' << ans[i] << ' ' << justtoget[i] << endl;
	}

	cout << ans[(1 << n) - 1];
	*/
	cout.precision(20);
	//cout << (clock() - tm) / CLOCKS_PER_SEC << endl;

	return 0;
}