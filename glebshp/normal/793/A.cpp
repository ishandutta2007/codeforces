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

int n, k;
int a[size];

int main () {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &k);
    
    for (int i = 0; i < n; i++) {
    	scanf("%d", &a[i]);
    }

    int mn = a[0];
    long long ans = 0;

    for (int i = 0; i < n; i++) {
    	mn = min(mn, a[i]);
    }

    bool flag = true;
    for (int i = 0; i < n; i++) {
    	if ((a[i] - mn) % k != 0)
    		flag = false;
    	else
    		ans += (a[i] - mn) / k;
    }

    if (!flag)
    	cout << -1 << endl;
    else
    	cout << ans << endl;
    
    return 0;
}