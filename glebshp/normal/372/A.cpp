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
#define taskname "problem_a"

const double pi = acos(-1.0);

bool check(int mid, vector <int>& cgs) {
	int n = cgs.size();
	for (int i = 0; i < mid; i++)
		if (cgs[i] * 2 > cgs[n - mid + i])
			return false;

	return true;
}

int main() {
	int n;

	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d", &n);
	int val;

	vector <int> cgs;
	for (int i = 0; i < n; i++) {
		scanf("%d", &val);
		cgs.pb(val);
	}

	sort(cgs.begin(), cgs.end());
	int lb = 0;
	int rb = n / 2;
	while (lb < rb) {
		int mid = (lb + rb + 1) / 2;
		if (check(mid, cgs))
			lb = mid;
		else
			rb = mid - 1;
	}

	cout << n - lb << endl;

	return 0;
}