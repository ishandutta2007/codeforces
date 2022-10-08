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

const int size = 200 * 1000 + 100;
//const int size = 20;

int n;
int ans[size];

int main () {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    	int d;
    	scanf("%d", &d);
    	for (int j = 1; j * j <= d; j++) {
    		if (d % j == 0) {
    			ans[j]++;
    			if (j * j < d) 
	    			ans[d / j]++;
    //			cerr << d << ' ' << j << endl;
    		}
    	}
    }

    int val = 1;
    for (int i = 2; i < size; i++) {
    	val = max(val, ans[i]);
    //	cerr << i << ' ' << ans[i] << endl;
    }

    printf("%d\n", val);

    return 0;
}