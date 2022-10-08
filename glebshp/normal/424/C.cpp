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
const int size = 1000 * 1000 + 100;

int n;
int sum[size];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    int ans = 0;
    int d;
    for (int i = 0; i < n; i++) {
    	scanf("%d", &d);
    	ans ^= d;
    }

    for (int i = 1; i <= n; i++) {
    	sum[i - 1] ^= (n / i) % 2;
    	sum[n % i] ^= 1;
    }
    int cur = 0;
    for (int i = n; i >= 0; i--) {
    	cur ^= sum[i];
    	if (cur)
    		ans ^= i;	
    }

    cout << ans << endl;

    return 0;
}