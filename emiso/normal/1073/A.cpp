#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN];
char s[MN]; string str;

int main() {
    scanf("%lld %s", &n, s);
    str = s;

    for(int i = 1; i < n; i++) {
        if(str[i-1] != str[i]) {
            printf("YES\n%c%c\n", str[i-1], str[i]);
            return 0;
        }
    }

    puts("NO");
    return 0;
}