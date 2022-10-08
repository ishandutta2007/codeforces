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
const long long mx = 777777777777ll;
const long long lm = 3 * 1000 * 1000;

int mex[lm + 1];
int g[lm + 1];

int main() {
	//freopen("problem_c.in", "r", stdin);
	//freopen("problem_c.out", "w", stdout);
	
	/*
	for (int i = 0; i < lm; i++)
		mex[i] = -1;

	int p1 = 0, p2 = 0;
	g[0] = 0;

	for (int i = 1; i < lm; i++) {
		while (p1 * p1 * p1 * p1 < i)
			p1++;
		while ((p2 + 1) * (p2 + 1) <= i)
			p2++;

		for (int j = p1; j <= min(i - 1, p2); j++)
			mex[g[j]] = i;
		int p = 0;
		while (mex[p] == i)
			p++;

		g[i] = p;
		if (i > 0 && g[i] != g[i - 1])
			printf("%d %d\n", i, g[i]);
	}
	*/

	/*
	4 1
	16 2
	82 0
	6724 3
	50626 1
	*/

	vector <pair <int, int> > lms;
	lms.pb(mp(0, 0));
	lms.pb(mp(4, 1));
	lms.pb(mp(16, 2));
	lms.pb(mp(82, 0));
	lms.pb(mp(6724, 3));
	lms.pb(mp(50626, 1));


	for (int i = 0; i < 4; i++)
		g[i] = 0;
	for (int i = 4; i < 16; i++)
		g[i] = 1;
	for (int i = 16; i < 82; i++)
		g[i] = 2;
	for (int i = 82; i < 6724; i++)
		g[i] = 0;
	for (int i = 6724; i < 50626; i++)
		g[i] = 3;
	for (int i = 50626; i < lm; i++)
		g[i] = 1;

	
	int ans = 0;
	int n;

	scanf("%d", &n);
	long long val;
	
	for (int i = 0; i < n; i++) {
		scanf("%I64d", &val);

		for (int j = 0; j < 10; j++)
			mex[j] = -1;

		if (val < lm)
			ans ^= g[val];
		else {
			long long p2 = floor(sqrt(val * 1.0));
			while ((p2 + 1) * (p2 + 1) <= val)
				p2++;
			while (p2 * p2 > val)
				p2--;

			long long p1 = floor(sqrt(p2 * 1.0));
			while (p1 * p1 * p1 * p1 < val)
				p1++;
			while ((p1 - 1) * (p1 - 1) * (p1 - 1) * (p1 - 1) >= val)
				p1--;

			for (int j = 0; j < lms.size(); j++) {
				if (p2 >= lms[j].fs && (p1 < lms[j].fs || ((j < lms.size() - 1) && p1 < lms[j + 1].fs)))
					mex[lms[j].sc] = i;
			}

			for (int j = 0; j < 10; j++)
				if (mex[j] != i) {
					ans ^= j;

					break;
				}
		}
	}

	if (ans)
		cout << "Furlo" << endl;
	else
		cout << "Rublo" << endl;

	return 0;
}