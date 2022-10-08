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

const int maxn = 200 * 1000 + 100;

int tc;
int n;
int a[maxn];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &tc);
    for (int tnum = 0; tnum < tc; tnum++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        sort(a, a + n);
        long long summin = a[0];
        long long summax = 0ll;
        bool flag = false;
        for (int i = 0; i < (n - 1) / 2; i++) {
            summin += a[i + 1];
            summax += a[n - 1 - i];
            flag = flag || (summin < summax);
        }

        if (flag) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}