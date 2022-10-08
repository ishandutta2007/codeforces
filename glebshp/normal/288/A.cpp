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

const int size = 1000 * 1000 * 2;

bool ex[size][26];

int main() {
	int n, k;

	//freopen("problem_a.in", "r", stdin);
	//freopen("problem_a.out", "w", stdout);
	
	cin >> n >> k;
	if (k == 1) {
		if (n == 1)
			printf("a\n");
		else
			printf("-1\n");
	} else {
		if (k > n) 
			printf("-1\n");
		else {
			for (int i = 0; i < n - k + 2; i++)
				printf("%c", "ab"[i % 2]);
			for (int i = 2; i < k; i++)
				printf("%c", char('a' + i));
			printf("\n");
		}
	}

	return 0;
}