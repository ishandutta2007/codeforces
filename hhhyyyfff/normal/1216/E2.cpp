#include <cstdio>
#include <cstdlib>

using namespace std;

int q;
long long k, l, r, mid;

long long cl1(long long x) {
    long long bit = 1, power = 10, pre = 0, ans = 0;
    while (x >= power) {
        ans += (power - power / 10) * pre + (power - power / 10) * (power - power / 10 + 1) / 2 * bit;
        pre += bit * (power - power / 10);
        power *= 10;
        ++bit;
    }
    x -= power / 10 - 1;
    return ans + x * pre + x * (x + 1) / 2 * bit;
}

long long cl2(long long x) {
    long long bit = 1, power = 10, ans = 0;
    while (x >= power) {
        ans += bit * (power - power / 10);
        power *= 10;
        ++bit;
    }
    x -= power / 10 - 1;
    return ans + x * bit;
}

void print(long long x) {
    if (x < 10) {
        if (k == 1)
            printf("%d\n", x);
        --k;
        return;
    }
    print(x / 10);
    if (k == 1)
        printf("%d\n", x % 10);
    --k;
}

int main() {
    scanf("%d", &q);
    while (q--) {
        scanf("%I64d", &k);
        l = 1;
        r = 482720320ll;
        while (l < r) {
            mid = (l + r) / 2;
            if (cl1(mid) < k)
                l = mid + 1; else
                r = mid;
        }
        k -= cl1(l - 1);
        r = l;
        l = 1;
        while (l < r) {
            mid = (l + r) / 2;
            if (cl2(mid) < k)
                l = mid + 1; else
                r = mid;
        }
        k -= cl2(l - 1);
        print(l);
    }
    return 0;
}