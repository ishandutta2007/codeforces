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

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	long long n;
	cin >> n;

	while (n % 3 == 0)
		n /= 3;
	cout << (n + 2) / 3 << endl;

	return 0;
}