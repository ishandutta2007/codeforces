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

int nod(int a, int b) {
	if (b == 0)
		return a;
	else
		return nod(b, a % b);
}

int main() {
	//assert(freopen("input.txt", "r", stdin));
//	assert(freopen("output.txt", "w", stdout));
	
	int n;

	scanf("%d", &n);
	int nd = 0;
	int mx = 0;
	int d;
	for (int i = 0; i < n; i++) {
		scanf("%d", &d);
		nd = nod(nd, d);
		mx = max(mx, d);
	}

	if ((mx / nd - n) & 1) {
		cout << "Alice" << endl;
	} else {
		cout << "Bob" << endl;
	}

	return 0;
}