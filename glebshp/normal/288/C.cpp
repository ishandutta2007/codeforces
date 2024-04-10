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

const int size = 1000 * 1000 * 2 + 10;

int p[size];

int main() {
	int n;
	
	//freopen("problem_cc.in", "r", stdin);
	//freopen("problem_cc.out", "w", stdout);

	cin >> n;
	int on = n;
	while (n > 0) {
		int pw = 1;
		while (pw * 2 - 1 <= n)
			pw *= 2;
		if (pw == n + 1) {
			for (int i = 0; i <= n; i++)
				p[i] = (pw - 1) ^ i;
			break;
		} else {
			for (int i = pw; i <= n; i++) {
				p[i] = (2 * pw - 1) ^ i;
				p[(2 * pw - 1) ^ i] = i;
			}
			n -= (n - pw + 1) * 2;
		}
	}

	n = on;

	long long sum = 0;
	for (int i = 0; i <= n; i++)
		sum += p[i] ^ i;

	printf("%I64d\n", sum);
	for (int i = 0; i <= n; i++)
		printf("%d ", p[i]);
	printf("\n");

	return 0;
}