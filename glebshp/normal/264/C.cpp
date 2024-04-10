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
const int size = 200 * 1000;
const long long inf = (long long) 1e18;

int n, q;
int v[size], c[size];
int a, b;
long long best[size];

int main() {
	//freopen("problem_c.in", "r", stdin);
	//freopen("problem_c.out", "w", stdout);
	
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
		c[i]--;
	}

	for (int i = 0; i < q; i++) {
		scanf("%d%d", &a, &b);
		for (int j = 0; j < n; j++)
			best[j] = -inf;
		pair <long long, int> m1, m2, m3;
		m1 = mp(0, -1);
		m2 = mp(-inf, 0);
		long long bans = 0, mans = 0;
		for (int j = 0; j < n; j++) {
			mans = best[c[j]] + v[j] * 1ll * a;
			if (m1.sc == c[j])
				mans = max(mans, m2.fs + v[j] * 1ll * b);
			else
				mans = max(mans, m1.fs + v[j] * 1ll * b);
			bans = max(bans, mans);
			best[c[j]] = max(best[c[j]], mans);
			m3 = mp(best[c[j]], c[j]);
			if (m3.sc == m1.sc)
				m1 = mp(-inf, 0);
			if (m3.sc == m2.sc)
				m2 = mp(-inf, 0);
			if (m3 > m2)
				swap(m2, m3);
			if (m2 > m1)
				swap(m2, m1);
			if (m3 > m2)
				swap(m2, m3);
		}

		cout << bans << endl;
	}

	return 0;
}