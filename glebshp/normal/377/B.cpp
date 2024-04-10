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
#define taskname "problem_b"

const double pi = acos(-1.0);
const int size = 200 * 1000;

vector <pair <int, int> > bugs;
vector <pair <int, int> > stud;

int ans[size];
long long wage[size];
int n, m;
long long s;

bool check(int days) {
	int p = 0;
	int q = 0;
	long long sum = 0;
	set <pair <long long, int> > psb;

	while (p < m) {
		while (q < n && stud[q].fs >= bugs[p].fs) {
			int nm = stud[q].sc;
			psb.insert(mp(wage[nm], nm));
			q++;
		}

		if (psb.empty())
			return false;
		sum += psb.begin()->fs;
		int nm = psb.begin()->sc;
		psb.erase(psb.begin());

		for (int i = 0; i < days; i++) {
			if (p < m) {
				ans[bugs[p].sc] = nm;
				p++;
			}
		}
	}

	return sum <= s;
}

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d%d%I64d", &n, &m, &s);

	int d;
	for (int i = 0; i < m; i++) {
		scanf("%d", &d);
		bugs.pb(mp(d, i));
	}
	sort(bugs.rbegin(), bugs.rend());
	for (int i = 0; i < n; i++) {
		scanf("%d", &d);
		stud.pb(mp(d, i));
	}
	sort(stud.rbegin(), stud.rend());

	for (int i = 0; i < n; i++) {
		scanf("%I64d", &wage[i]);
	}

	int lb = 1;
	int rb = m;

	if (!check(rb)) {
		printf("NO\n");
		return 0;
	}

	while (lb < rb) {
		int mid = (lb + rb) / 2;
		if (check(mid))
			rb = mid;
		else
			lb = mid + 1;
	}

	check(lb);

	printf("YES\n");

	for (int i = 0; i < m; i++)
		printf("%d%c", ans[i] + 1, " \n"[i == m - 1]);

	return 0;
}