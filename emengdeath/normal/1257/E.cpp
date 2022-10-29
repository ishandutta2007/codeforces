#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <queue>
#include <unordered_set>
#include <set>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int T;
int k1, k2, k3;
int n;
int bz[N], sum[N];
int main() {
    {
        scanf("%d %d %d", &k1, &k2, &k3);
        n = k1 + k2 + k3;
        while (k1--){
            int x;
            scanf("%d", &x);
            bz[x] = 1;
        }
        while (k2--){
            int x;
            scanf("%d", &x);
            bz[x] = 2;
        }
        while (k3--){
            int x;
            scanf("%d", &x);
            bz[x] = 3;
        }
        for (int i = 1; i <= n; i ++)
            sum[i] = sum[i - 1] + (bz[i] != 1);
        int v = 0;
        int all3 = 0;
        int ans = 1e9;
        for (int i = n ; i >= 0;i --){
            ans = min(ans, v + sum[i]);
            if (bz[i] != 2) v ++;
            all3 += (bz[i] != 3);
            v =min(v, all3);
        }
        printf("%d\n", ans);
    }
    return 0;
}