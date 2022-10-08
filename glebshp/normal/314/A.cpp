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

const int size = 200 * 1000 + 100;

long long a[size];

int main() {
	int n;
	long long k;

	//freopen("problem_a.in", "r", stdin);
	//freopen("problem_a.out", "w", stdout);
	
	scanf("%d%I64d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);

	unsigned long long s1 = 0, s2 = 0;
	unsigned long long cnt = 0;
	unsigned long long tot = n;
	unsigned long long md = -k;
	for (int i = 0; i < n; i++) {
		s2 = (tot - cnt - 1) * (cnt);
		s2 *= a[i];
		if (s1 + md < s2) {
			printf("%d\n", i + 1);
			tot--;
		} else {
			s1 += a[i] * cnt;
			cnt++;
		}
	}

	return 0;
}