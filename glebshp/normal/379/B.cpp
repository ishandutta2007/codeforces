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
const int size = 1000;
const int bsize = 2000 * 1000;

int a[size];
char buf[bsize];
int n;

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (i > 0) {
			buf[cur++] = 'R';
		}
		for (int j = 0; j < a[i]; j++) {
			buf[cur++] = 'P';
			if (i < n - 1) {
				buf[cur++] = 'R';
				buf[cur++] = 'L';
			} else {
				buf[cur++] = 'L';
				buf[cur++] = 'R';
			}
		}
	}

	printf("%s", buf);

	return 0;
}