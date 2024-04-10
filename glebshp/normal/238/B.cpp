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
const int size = 100  * 1000 + 100;

vector <pair <int, int> > num;

int n, h;
int ans;
int anskey;
int ansval[size];

int main() {
	//freopen("problem_bb.in", "r", stdin);
	//freopen("problem_bb.out", "w", stdout);
	
	scanf("%d%d", &n, &h);
	for (int i = 0; i < n; i++) {
		int d;
		scanf("%d", &d);
		num.pb(mp(d, i));
	}

	sort(num.begin(), num.end());

	ans = num[n - 1].fs + num[n - 2].fs - num[0].fs - num[1].fs;
	anskey = -1;
	for (int i = n - 3; i > 0; i--) {
		int mx = max(num[n - 1].fs + num[n - 2].fs, num[n - 1].fs + num[i].fs + h);
		int mn = min(num[i + 1].fs + num[0].fs, num[0].fs + num[1].fs + h);
		if (n >= 3 && i > 1)
			mn = min(mn, num[1].fs + num[2].fs);
		int la = mx - mn;

		if (la < ans) {
			ans = la;

			anskey = i;
		}
	}

	if (n >= 3) {
		int la = max(num[n - 1].fs + num[n - 2].fs, num[n - 1].fs + num[0].fs + h) - min(num[0].fs + num[1].fs + h, num[1].fs + num[2].fs);
		if (la < ans) {
			ans = la;
			anskey = -2;
		}
	}
	
	if (anskey == -2) {
		for (int i = 0; i < n; i++)
			ansval[i] = 1;
		ansval[num[0].sc] = 2;
	} else {
		if (anskey == -1) {
			for (int i = 0; i < n; i++)
				ansval[i] = 1;
		} else {
			for (int i = n - 1; i > anskey; i--)
				ansval[num[i].sc] = 1;
			for (int i = anskey; i > 0; i--)
				ansval[num[i].sc] = 2;
			ansval[num[0].sc] = 1;
		}
	}


	cout << ans << endl;
	for (int i = 0; i < n; i++)
		cout << ansval[i] << " \n"[i + 1 == n];

	return 0;
}