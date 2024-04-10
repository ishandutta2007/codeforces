#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
int main() {
    long long k, l, r, t, x, y;
    scanf("%lld %lld %lld %lld %lld %lld", &k, &l, &r, &t, &x, &y);
    k -= l;
    r -= l;
    if (x == y) {
        if (r - k >= y)  {
            puts("Yes");
            return 0;
        }
        if (k < x) {
            puts("No");
            return 0;
        }
        puts("Yes");
        return 0;
    }
    if (x > y) {
        if (r - k >= y) {
            long long cnt = k / (x - y);
            if (cnt >= t) {
                puts("Yes");
            } else puts("No");
            return 0;
        }
        if (k >= x) {
            long long cnt = (k - x) / (x - y) + 1;
            if (cnt >= t) {
                puts("Yes");
            } else puts("No");
            return 0;
        } else
            puts("No");
        return 0;
    }

    if (y > r) {
        long long cnt = k / x;
        if (cnt >= t) {
            puts("Yes");
            return 0;
        }
        puts("No");
        return 0;
    }
    if (r - k >= y) {
        long long cnt = (r - k - y) / (y - x);
        if (cnt + 1 >= t)  {
            puts("Yes");
            return 0;
        }
        t -= cnt + 1;
        k += cnt * (y - x) + y - x;
    }
    set<long long> f;
    while (1) {
        if (f.find(k) != f.end()) {
            puts("Yes");
            return 0;
        }
        f.insert(k);
        if (k + y <= r) {
            t --;
            k = k + y - x;
            if (!t) {
                puts("Yes");
                return 0;
            }
        } else {
            long long cnt = (y - (r - k) + x - 1) / x;
            if (k - x * cnt < 0) {
                cnt --;
                if (cnt >= t) {
                    puts("Yes");
                    return 0;
                }
                puts("No");
                return 0;
            }
            if (cnt + 1 >= t) {
                puts("Yes");
                return 0;
            }
            t -= (cnt + 1);
            k = k - x * cnt + y - x;
        }
    }
    return 0;
}