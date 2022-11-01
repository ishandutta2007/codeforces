#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if(a[i] <= 14) puts("NO");
        else {
            a[i] %= 14;
            if(a[i] >= 1 && a[i] <= 6) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}