#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int N = 2e5 + 1;
priority_queue<pair<long long, long long> > f;
int n;
struct node{
    long long a, b, t;
}a[N];
int main(){
    scanf("%d", &n);
    for (int i =1 ; i <= n; i ++)
        scanf("%lld %lld %lld", &a[i].a, &a[i].b, &a[i].t);
    long long s = 0, t = 1e18 + 1, e = 1e18;
    long long ans = 0;
    sort(a + 1, a + n + 1, [](const node&a, const node&b) {
        return a.a < b.a || (a.a == b.a && a.t < b.t);
    });
    for (int i = 1; i <= n; i ++) {
        while (!f.empty() && (s + t <= a[i].a || s + t > e || e <= a[i].a)) {
            if (-f.top().first + s > f.top().second) {
                f.pop();
                continue;
            }
            if (s + t > e) {
                t = -f.top().first;
                e = f.top().second;
                continue;
            }
            if (-f.top().first < t) {
                t = -f.top().first;
                e = f.top().second;
                continue;
            }
            long long r = min(e, a[i].a);
            ans += (r - s) / t;
            s += (r - s) / t * t;
        }
        if (f.empty()) {
            f.push(make_pair(-a[i].t, a[i].b));
            s = a[i].a;
            t = a[i].t;
            e = a[i].b;
        } else {
            f.push(make_pair(-a[i].t, a[i].b));
            if (s + t >= a[i].a + a[i].t) {
                s = a[i].a;
                t = a[i].t;
                e = a[i].b;
            } else {
                e = s + t;
                t = s + t - a[i].a;
                s = a[i].a;
            }
        }
    }
    while (!f.empty()) {
        if (-f.top().first + s > f.top().second) {
            f.pop();
            continue;
        }
        if (s + t > e) {
            t = -f.top().first;
            e = f.top().second;
            continue;
        }
        if (-f.top().first < t) {
            t = -f.top().first;
            e = f.top().second;
            continue;
        }
        ans += (e - s) / t;
        s += (e - s) / t * t;
    }
    printf("%lld\n", ans);
    return 0;
}