#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, q, x, y, first_odd = 1;
int a[1001000];
int odd, even;

int main()
{
    //ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &q);
    int n2 = n / 2;
    while (q--) {
        scanf("%d", &x);
        if (x == 1) {
            scanf("%d", &y);
            y = (y % n + n) % n;
            if (y % 2 == 0) {
                even += y / 2;
                odd += y / 2;
            } else {
                if (!first_odd) {
                    odd += (y + 1) / 2;
                    even += y / 2;
                } else {
                    even += (y + 1) / 2;
                    odd += y / 2;
                }
                first_odd ^= 1;
            }
            odd %= (n2);
            even %= (n2);
        } else {
            first_odd ^= 1;
        }
    }

    if (first_odd) {
        for (int i = 0; i < n2; ++i) {
            a[(i + odd) * 2 % n] = i * 2 + 1;
        }
        for (int i = 0; i < n2; ++i) {
            a[((i + even) * 2 + 1) % n] = i * 2 + 2;
        }
    } else {
        for (int i = 0; i < n2; ++i) {
            a[(i + even) * 2 % n] = i * 2 + 2;
        }
        for (int i = 0; i < n2; ++i) {
            a[((i + odd) * 2 + 1) % n] = i * 2 + 1;
        }
    }

    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);

    return 0;
}