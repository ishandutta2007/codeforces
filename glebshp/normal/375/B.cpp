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
const int size = 5100;

int cnt[size][size];
int sum[size][size];

char buf[size];
int n, m;

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", buf);
		int p = 0;
		int q = 0;
		while (p < m) {
			while (p < m && buf[p] == '0')
				p++;
			if (p == m)
				break;
			q = p;
			while (q < m && buf[q] == '1')
				q++;
			cnt[p][q - 1]++;
			p = q;
		}
	}

	int ans = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = m; j > 0; j--) {
			sum[i][j] = sum[i - 1][j] + sum[i][j + 1] - sum[i - 1][j + 1] + cnt[i - 1][j - 1];
			if (j >= i)
				ans = max(ans, sum[i][j] * (j - i + 1));
		}
	}

	cout << ans << endl;

	return 0;
}