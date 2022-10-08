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
#define taskname "task_b"

const double pi = acos(-1.0);
const int size = 1000 * 1000 + 100;

int a[size];
int sum[2][size];
int n;

inline int getresult(int lb, int rb) {
	return max(sum[0][rb] - sum[0][lb - 1], sum[1][rb] - sum[1][lb - 1]);
}

int check(int t) {
	int cur = 1;
	int cnta = 0;
	int cntb = 0;
	int last = 0;

	while (cur <= n) {
		int lb = cur;
		int rb = n;
		while (lb < rb) {
			int mid = (lb + rb) / 2;
			if (getresult(cur, mid) < t)
				lb = mid + 1;
			else
				rb = mid;
		}

		if (getresult(cur, lb) < t)
			return -1;
		else {
			if ((sum[0][lb] - sum[0][cur - 1]) == t) {
				cnta++;
				last = cnta;
			} else {
				cntb++;
				last = cntb;
			}
			cur = lb + 1;
		}
	}

	if (cnta == cntb || max(cnta, cntb) != last)
		return -1;
	else
		return last;
}

int main() {
	/*
	freopen("input.txt", "w", stdout);
	int n = 100 * 1000;
	cout << n << endl;
	for (int i = 0; i < n; i++)
		cout << 1 << ' ' ;
	cout << endl;
	return 0;
	*/
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sum[0][0] = 0;
	sum[1][0] = 0;
	for (int i = 1; i <= n; i++) {
		sum[0][i] = sum[0][i - 1];
		sum[1][i] = sum[1][i - 1];
		if (a[i - 1] == 1)
			sum[0][i]++;
		else
			sum[1][i]++;
	}

	vector <pair <int, int> > ans;

	for (int i = 1; i <= n; i++) {
		int p = check(i);
		if (p != -1)
			ans.pb(mp(p, i));
	}

	sort(ans.begin(), ans.end());
	printf("%d\n", (int) ans.size());
	for (int i = 0; i < (int) ans.size(); i++)
		printf("%d %d\n", ans[i].fs, ans[i].sc);

	//cout << (clock() + 0.0) / CLOCKS_PER_SEC << endl;

	return 0;
}