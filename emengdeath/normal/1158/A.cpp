#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <deque>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;
const int N = 1e6;
long long ans;
int a[N];
int b[N];
int n, m, sum;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n ;  i++){
        scanf("%d", &a[i]);
        ans += 1ll * a[i] * m;
    }
    sort(a + 1, a + n + 1);
    sum = m;
    int r = n;
    for (int i = 1; i <= m; i ++){
        int x;
        scanf("%d", &x);
        if (a[n] > x) {
            printf("-1");
            return 0;
        }
        if (a[r] == x)
        {
            int yy;
        } else {
            if (sum == 1) {
                r --, sum = m;
            }
            ans += 1ll * (x - a[r]);
            sum --;
        }
    }
    printf("%lld\n" ,ans);
    return 0;
}