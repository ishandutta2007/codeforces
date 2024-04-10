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

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	int n, m, k;
	int d;

	scanf("%d%d%d", &n, &m, &k);
	vector <int> alice, bob;
	for (int i = 0; i < n; i++) {
		scanf("%d", &d);
		alice.pb(d);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &d);
		bob.pb(d);
	}

	sort(alice.begin(), alice.end());
	sort(bob.begin(), bob.end());

	while (true) {
		if (alice.empty()) {
			cout << "NO" << endl;
			break;
		}
		if (bob.empty()) {
			cout << "YES" << endl;
			break;
		}
		if (alice.back() > bob.back()) {
			cout << "YES" << endl;
			break;
		}
		alice.pop_back();
		bob.pop_back();
	}

	return 0;
}