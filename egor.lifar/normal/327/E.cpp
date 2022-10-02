#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <vector>


using namespace std;


const int MAXN = 24;
const long long Mod = 1000000007;
int n, k;
long long a[1 << MAXN];
long long sum[1 << MAXN], f[1 << MAXN];
long long p[MAXN + 1];


int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[1 << i]);
    }
    scanf("%d", &k);
    for (int i = 0 ; i < k; i++) {
        scanf("%lld", &p[i]);
    }
    for (int i = 0; i < (1 << n); i++) {
        int x = i;
        while (x != 0) {
            int j = x & (-x);
            sum[i] += a[j];
            x -= j;
        }
    }
    f[0] = 1;
    for (int i = 1; i < (1 << n); i++) {
        int j = 0;
        while (j < k) {
            if (p[j] == sum[i]) {
                break;
            }
            j++;
        }
        if (j < k) {
            continue;
        }
        int x = i;
        while (x) {
            int jj = x & (-x);
            f[i] += f[i & ~jj];
            f[i] >= Mod ? f[i] -= Mod : i;
            x -= jj;
        }
  }
  printf("%lld\n",  f[(1 << n) - 1]);
  return 0;
}