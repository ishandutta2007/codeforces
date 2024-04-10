#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN];
char s[MN]; string str;

int main() {
    scanf("%lld %s", &n, s); str = s;

    if(n == 1) {
        printf("YES\n");
        return 0;
    }

    for(int i = 0; i < n; i++) {
        a[str[i] - 'a']++;
    }

    bool flag = 0;
    for(int i = 0; i < 26; i++) {
        if(a[i] > 1) flag = 1;
    }

    printf("%s\n", flag ? "YES" : "NO");
    return 0;
}