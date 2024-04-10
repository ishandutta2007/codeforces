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

int main () {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int a, b, c;
    int n;

    scanf("%d%d%d", &a, &b, &c);
    scanf("%d", &n);
    int ans = 0;

    for (int i = 0; i < n; i++) {
    	int x;
    	scanf("%d", &x);

    	if (x > b && x < c)
    		ans++;
    }

    printf("%d\n", ans);

    return 0;
}