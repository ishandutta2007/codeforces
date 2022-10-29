#include <ctime>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <set>
#include <cmath>
using namespace std;
const int N = 1e6  +1;
int n, m;
int a[N];
int mn[N], mx[N];
bool check(int l, int r) {
    int mx = 0;
    for (int i = 1; i <= n ;  i++)
        if (l <= a[i] && a[i] <= r) {
            if (a[i] < mx) return 0;
            mx = a[i];
        }
    return 1;
}
long long get(int x){
    return 1ll * x * (x + 1) / 2;
}
int main(){
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m ; i ++)
        mn[i] = n + 1, mx[i] = 0;
    for (int i = 1; i <= n ; i ++) {
        scanf("%d", &a[i]);
        mn[a[i]] = min(mn[a[i]], i);
        mx[a[i]] = max(mx[a[i]], i);
    }
    int l = 1, r = m, mid, s = 1;
    while (l <= r)
        if (check(1, mid = (l+r) / 2))l = mid + 1, s = max(mid, s);
        else
            r = mid - 1;
    int sl = s;
    l = 1, r = m, mid, s = m;
    while (l <= r)
        if (check(mid = (l+r) / 2, m))r = mid - 1, s = min(mid, s);
        else
            l = mid + 1;
    int sr = s;
    for (int i = 2; i <= m ; i++)
        mx[i] = max(mx[i], mx[i - 1]);
    for (int i = m - 1; i >= 1; i --)
        mn[i] = min(mn[i], mn[i + 1]);
    if (sl == m) {
        cout<<1ll * (m + 1) * m / 2;
        return 0;
    }
    long long ans = m - sr + 2;
    for (int i = 1; i <= sl; i ++){
        while (sr <= m && mn[sr] < mx[i]) sr++;
        ans += m - sr + 2;
    }
    cout<<ans;
    return 0;
}