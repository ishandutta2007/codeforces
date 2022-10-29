#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e6 + 100;
int n, k, l;
pair<long long , long long>f[N];
char s[N];
int a[N];
long long check(int mid) {
    for (int i = 1; i <= n; i ++)
        f[i] = make_pair(1e18,1e18);
    f[0] = make_pair(0, 0);
    for (int i = 0; i < n; i ++) {
        if (f[i + 1] > make_pair(f[i].first + a[i], f[i].second))
            f[i + 1] = make_pair(f[i].first + a[i], f[i].second);
        if (f[min(i + l, n)] > make_pair(f[i].first + mid, f[i].second + 1) )
            f[min(i + l, n)] = make_pair(f[i].first + mid, f[i].second + 1);
    }
    return f[n].second;
}
long long work(){
    long long l = 0,  r = n, mid, s = 0;
    if (check(0) < k) return 0;
    while (l <= r) {
        if (check(mid =  (l + r) / 2) > k) {
            l = mid + 1;
            s = max(s, mid);
        } else {
            r = mid - 1;
        }
    }
    check(s + 1);
    return f[n].first - k * (s + 1);
}
int main(){
    scanf("%d %d %d", &n, &k, &l);
    scanf("%s", s);
    for (int i = 0; i < n; i ++ )
        a[i] = islower(s[i]) > 0;
    long long ans = 1e18;
    ans = min(ans, work());
    for (int i = 0; i < n; i ++ )
        a[i] = isupper(s[i]) > 0;
    ans = min(ans, work());
    printf("%lld\n", ans);
    return 0;
}