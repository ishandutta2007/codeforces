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
const int size = 8;

int crd[size][3];
int crdn[size][3];

inline long long sqr(long long x) {
	return x * x;
}

long long h[8];

bool check() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			long long d = 0;
			for (int k = 0; k < 3; k++)
				d += sqr(crdn[i][k] - crdn[j][k]);
			h[j] = d;
		}
		sort(h, h + 8);
		long long a = h[1];
		if (a == 0)
			return false;
		if (h[2] != a || h[3] != a)
			return false;
        if (h[4] != 2 * a || h[5] != 2 * a || h[6] != 2 * a)
        	return false;
      	if (h[7] != 3 * a)
      		return false; 
	}

	return true;
}

bool rec(int p) {
	if (p == 8) {
		if (check()) {
			cout << "YES" << endl;
			for (int i = 0; i < 8; i++)
				cout << crdn[i][0] << ' ' << crdn[i][1] << ' ' << crdn[i][2] << endl;
			return true;
		} else {
			return false;
		}
	}
	vector <int> pr;
	pr.pb(0);
	pr.pb(1);
	pr.pb(2);
	do {
		for (int i = 0; i < 3; i++)
			crdn[p][i] = crd[p][pr[i]];
		if (rec(p + 1))
			return true;
	} while (next_permutation(pr.begin(), pr.end()));
	
	return false;
}


int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    for (int i = 0; i < 8; i++) {
    	cin >> crd[i][0] >> crd[i][1] >> crd[i][2];
    }

    if (!rec(0)) {
    	cout << "NO" << endl;
    }

//    cerr << (clock() * 1.0) / CLOCKS_PER_SEC << endl;

    return 0;
}