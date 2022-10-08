#pragma comment(linker, "/STACK:1000000000")
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
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 1000 * 1000;
const int ssize = 10;

int ans[ssize][size];
long long n;
int tg[ssize][size];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	cin >> n;
	for (int j = 0; j < ssize; j++) {
		ans[j][0] = 0;
		tg[j][0] = 0;
		for (int i = 1; i < size; i++) {
			//ans[j][i] = n;
			if (i < j) {
				ans[j][i] = 1;
				tg[j][i] = i - j;
				continue;
			}
			int mx = j;
			int hh = i;
			while (hh > 0) {
				mx = max(mx, hh % 10);
				hh /= 10;
			}
			ans[j][i] = ans[j][i - mx] + 1;
			tg[j][i] = tg[j][i - mx];
		}
	}

	long long cnt = 0;
	while (n > 0) {
		//cerr << n << endl;
		long long hp = n / size;
		int mx = 0;
		while (hp > 0) {
			mx = max((int) hp % 10, mx);
			hp /= 10;
		}
		long long ost = n % size;
		if (ost == 0) {
			n -= mx;
			cnt++;
			continue;
		}
		cnt += ans[mx][ost];
		n -= ost;
		n += tg[mx][ost];
	}

	cout << cnt << endl;
	
    return 0;
}