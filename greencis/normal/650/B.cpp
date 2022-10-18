#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,a,b,t,ans,need[500105];
char s[500105];

int main()
{
    scanf("%d%d%d%d%s",&n,&a,&b,&t,s);
    for (int TTT = 0; TTT < 2; ++TTT) {
        for (int i = 0; i < 500105; ++i)
            need[i] = 0;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            ++cur;
            if (s[i] == 'w') cur += b;
            need[i] = t - cur;
            if (cur <= t) ans = max(ans, i + 1);
            if (i != n - 1)
                cur += a;
        }

        cur = 1;
        if (s[0] == 'w') cur += b;
        if (cur <= t) ans = max(ans, 1);
        cur += a;
        for (int i = n - 1; i >= 1; --i) {
            ++cur;
            if (s[i] == 'w') cur += b;
            if (cur <= t) {
                ans = max(ans, 1 + n - i);

                int L = 1, R = n - 1;
                int bs = cur + (n - i) * a - 1 - b * (s[0] == 'w');
                while (L < R) {
                    int mid = (L + R + 1) >> 1;
                    if (need[mid] >= bs) L = mid;
                    else R = mid - 1;
                }
                if (need[R] >= bs) {
                    if (R >= i) ans = max(ans, n);
                    else ans = max(ans, n - (i - R - 1));
                }
            }

            if (i != 1)
                cur += a;
        }
        reverse(s + 1, s + n);
    }
    cout << ans;

    return 0;
}