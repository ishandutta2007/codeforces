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

const int size = 1000 * 1000 + 100;
const int inf = 1000 * 1000 * 1000;
const int kSingle = 20;
const int k90 = 50;
const int kDay = 120;

int n;
int t[size];
int ans[size];

int main () {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    t[0] = -inf;
    ans[0] = 0;
    for (int i = 0; i < n; i++) {
    	scanf("%d", &t[i + 1]);

    	ans[i + 1] = ans[i] + kSingle;
    	int p = lower_bound(t, t + i + 1, t[i + 1] - 89) - t;
    	ans[i + 1] = min(ans[i + 1], ans[p - 1] + k90);
    	p = lower_bound(t, t + i + 1, t[i + 1] - 1439) - t;
    	ans[i + 1] = min(ans[i + 1], ans[p - 1] + kDay);

    	printf("%d\n", ans[i + 1] - ans[i]);
   	}

    return 0;
}