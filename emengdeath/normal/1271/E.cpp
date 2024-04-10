#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
long long n, k;
long long count(long long x) {
    if (!x) return n;
    long long sum = 0;
    long long v = 1 + !(x & 1);
    while (x <= n) {
        sum += min(n - x, v - 1) + 1;
        v += v;
        x += x;
    }
    return sum;
}
int main(){
    scanf("%lld %lld", &n, &k);
    long long s = 1;
    long long l = 0, r = n / 2 + 1, mid;
    while (l <= r) {
        if (count((mid = (l + r) / 2) * 2) >= k) s = max(s, mid * 2), l = mid + 1;
        else
            r = mid - 1;
    }
    l = 0, r = n / 2 + 1, mid;
    while (l <= r) {
        if (count((mid = (l + r) / 2) * 2 + 1) >= k) s = max(s, mid * 2 + 1), l = mid + 1;
        else
            r = mid - 1;
    }
    printf("%lld\n", s);
    return 0;
}