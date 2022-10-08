#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
const double pi = acos(-1.0);

int main() {
	//freopen("problem_a.in", "r", stdin);
	//freopen("problem_a.out", "w", stdout);
	
	int n, k;

	cin >> n >> k;

	if (n * (n - 1) / 2 <= k)
		printf("no solution\n");
	else {
		for (int i = 0; i < n; i++)
			printf("0 %d\n", i);
	}

	return 0;
}