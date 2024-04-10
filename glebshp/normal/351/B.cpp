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
const int size = 10 * 1000;
const int lsize = 10 * 1000 * 1000;
int p[size];
double ans[lsize];

int main() {
	int n;

	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	int inv = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			inv += (p[i] > p[j]);

	if (inv == 0)
		cout << 0 << endl;
	else {
		if (inv % 2 == 0)
			cout << inv * 2 << endl;
		else
			cout << inv * 2 - 1 << endl;
	}

	return 0;
}