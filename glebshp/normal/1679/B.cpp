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

const int maxn = 200 * 1000 + 1;

int n, q;
int a[maxn];
int tsmp[maxn];
long long sum;
int lastv;
int lastt;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    for (int i = 1; i <= q; i++) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            int p, x;
            scanf("%d%d", &p, &x);
            p--;
            if (tsmp[p] < lastt) {
                tsmp[p] = lastt;
                a[p] = lastv;            
            }
            sum = sum - a[p] + x;
            a[p] = x;
            tsmp[p] = i;
        } else {
            int x;
            scanf("%d", &x);
            sum = x * 1ll * n;
            lastt = i;
            lastv = x;
        }

        printf("%lld\n", sum);
    }

    return 0;
}