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

const long long inf = 1000ll * 1000 * 1000;

bool check(long long x, long long y, long long p, long long q, long long m) {
	if (q * m < y)
		return false;
	long long h = q * m - y;

	return (x <= p * m && (x + h) >= p * m);
}

int main () {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int tc;
    cin >> tc;
    for (int tnum = 0; tnum < tc; tnum++) {
    	long long a, b, p, q;
    	cin >> a >> b >> p >> q;
    	
    	if ((p == 0 && a > 0) || (p == q && a < b)) {
    		cout << -1 << endl;
    	} else {
    		long long lb = 1;
    		long long rb = inf;

    		while (lb < rb) {
    			long long mid = (lb + rb) / 2;
    			if (check(a, b, p, q, mid)) {
    				rb = mid;
    			} else {
    				lb = mid + 1;
    			}
    		}

    		cout << q * lb - b << endl;
    	}
    }

    return 0;
}