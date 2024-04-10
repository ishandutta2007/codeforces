#include <bits/stdc++.h>
using namespace std;

int T, x, d;

int main() {
    scanf("%d", &T);
    auto prime = [&](int x) {
        if (x == 1) return 1;
        for (int i = 2; i * i <= x; i++) {
            if (!(x % i)) return 0;
        }
        return 1;
    };
    while (T--) {
        scanf("%d %d", &x, &d);
        int cnt = 0, num = 0;
        while (!(x % d)) x /= d, cnt++;
        // d^cnt * x
        auto chk = [&](int val) {
            if (prime(val)) return num = 1, 0;
            for (int i = 2; i * i <= val; i++) if (!(val % i)) {
                while (!(val % i)) val /= i, num++;
                return val > 1 ? 1 : 0;
            }
            assert(0);
        };
        chk(d);
        int num_d = num;
        num = 0;
        if (cnt > 1 && !prime(x)) {
            puts("YES");
        } else if (cnt > 2 && !prime(d) && (chk(d * x) || num <= (cnt - 1) * (num_d - 1))) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}