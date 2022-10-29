#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <deque>
#include <set>
using namespace std;
const int N = 2e5  + 1;
int a[N], b[N], wz[N];
bool bz[N];
int n;
int main(){
    scanf("%d", &n);
    for (int i  =1; i <= n ; i++)
        scanf("%d", &a[i]), bz[a[i]] = 1;
    int ans = n;
    int s = 0;
    for (int i = 1; i <= n ; i++) {
        scanf("%d", &b[i]);
        wz[b[i]] = i;
        if (b[i] == 1)
            s = i;
    }
    ans += wz[1];
    int mx = wz[1];
    for (int i = 2; i <= n ; i ++) {
        ++mx;
        if (wz[i] > mx)
            ans += wz[i] - mx, mx = wz[i];
    }
    if (s) {
        bool sig = 1;
        for (int i = s + 1; i <= n; i ++)
            if (b[i - 1] != b[i] - 1) {
                sig = 0;
            }
        if (sig) {
            sig = 1;
            for (int i = b[n] + 1; i <=n; i++) {
                if (!bz[i]) sig = 0;
                bz[b[i - b[n]]] = 1;
            }
            if (sig) ans = n - b[n];
        }
    }
    printf("%d\n", ans);
    return 0;
}