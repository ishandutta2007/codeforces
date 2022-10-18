#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long double ld;
typedef long long ll;

int n,a,u[100005],cnt[100005];

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        int flag = 1;
        for (int j = 0; a; ++j) {
            if (u[a] == i) {
                u[a] = i + 1;
                cnt[a] += j;
            }
            if (flag) {
                int x = a << 1, foo = 1;
                while (x <= 100000) {
                    if (u[x] == i) {
                        u[x] = i + 1;
                        cnt[x] += j + foo;
                    }
                    x <<= 1;
                    ++foo;
                }
            }
            flag = a & 1;
            a >>= 1;
        }
    }

    int res = 2e9;
    for (int i = 1; i < 100005; ++i)
        if (u[i] == n)
            res = min(res, cnt[i]);
    printf("%d", res);

    return 0;
}