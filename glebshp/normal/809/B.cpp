#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int n, k;

bool ask(int x, int y) {
	cout << 1 << ' ' << x << ' ' << y << endl;

	string ans;
	cin >> ans;

	return ans == "TAK";
}

int go(int lb, int rb) {
	if (lb == rb)
		return lb;
	while (lb < rb - 1) {
		int mid = (lb + rb) / 2;

		if (ask(mid, mid + 1))
			rb = mid;
		else
			lb = mid;
	}

	if (ask(lb, rb))
		return lb;
	else
		return rb;
}

bool verify(int x, int y) {
	return ask(x, y) && ask(y, x);
}

int main () {
	cin >> n >> k;    

	int fp = go(1, n);
	int c1 = -1, c2 = -1;
	if (fp > 1)
		c1 = go(1, fp - 1);
	if (fp < n)
		c2 = go(fp + 1, n);

	if (c1 != -1 && verify(c1, fp))
		cout << 2 << ' ' << min(c1, fp) << ' ' << max(c1, fp) << endl;
	else
		cout << 2 << ' ' << min(c2, fp) << ' ' << max(c2, fp) << endl;	

    return 0;
}