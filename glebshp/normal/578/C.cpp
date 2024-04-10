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
#define double long double

const double pi = acos(-1.0);
const int size = 1000 * 1000 + 100;
const double inf = 1e4;
const int iters = 200;

int n;
int a[size];

double getvalue(double x) {
	double mn = 0;
	double mx = 0;
	
	double cursum = 0.0;
	for (int i = 0; i < n; i++) {
		cursum += a[i] - x;
		mn = min(mn, cursum);
		mx = max(mx, cursum);
	}

	return mx - mn;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    	scanf("%d", &a[i]);
    }

    double lb = -inf;
    double rb = inf;

    for (int it = 0; it < iters; it++) {
    	double k1 = lb + (rb - lb) / 7 * 3;
    	double k2 = lb + (rb - lb) / 7 * 4;

    	double d1 = getvalue(k1);
    	double d2 = getvalue(k2);
    	if (d1 < d2)
    		rb = k2;
    	else
    		lb = k1;
    } 

    cout.precision(20);
    cout << getvalue((lb + rb) / 2) << endl;

    return 0;
}