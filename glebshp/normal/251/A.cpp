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
const int size = 100 * 1000 + 100;

int n, d;
long long ans;
int pts[size];

int main() {
	//freopen("problem_a.in", "r", stdin);
	//freopen("problem_a.out", "w", stdout);
	
	scanf("%d%d", &n, &d);

	int ps = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &pts[i]);
		while (pts[i] - pts[ps] > d)
			ps++;

		ans += max(i - ps, 0) * 1ll * max(i - ps - 1, 0) / 2; 
	}

	cout << ans << endl;

	return 0;
}