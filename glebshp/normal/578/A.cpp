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

const double inf = 1e18;


int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int a, b;
    cin >> a >> b;
    
    if (a < b) {
    	cout << -1 << endl;
    	return 0;
    }

    if (a == b) {
    	cout << b << endl;
    	return 0;
    }

    int d = a - b;
    int k = d / (2 * b);
    double ans1 = inf, ans2 = inf;

    if (k > 0) {
    	ans1 = ((double) (a - b)) / (2 * k);
    }
    
    ans2 = ((double) (a + b)) / (2 * k + 2);
    
    double ans = min(ans1, ans2);
    if (ans > inf / 2)
    	cout << -1 << endl;
    else {
    	cout.precision(20);
    	cout << ans << endl;
    }	

   

        
   	return 0;
}