#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, s1, s2, i1, i2;
char s[MN];

int main() {
    scanf("%lld %s", &n, s);

    for(int i = 0; i < n/2; i++) {
        if(s[i] != '?') s1 += (s[i] - '0');
        i1 += (s[i] == '?');
    }
    for(int i = n/2; i < n; i++) {
        if(s[i] != '?') s2 += (s[i] - '0');
        i2 += (s[i] == '?');
    }

    if(s1 == s2) {
        if(i1 == i2) puts("Bicarp");
        else puts("Monocarp");
    } else {
        if(i1 == i2) puts("Monocarp");
        else if((i1 > i2 && s1 > s2) || (i1 < i2 && s1 < s2)) puts("Monocarp");
        else {
            if(abs(s1 - s2) == (9 * abs(i1 - i2) / 2)) puts("Bicarp");
            else puts("Monocarp");
        }
    }
    return 0;
}

/**
8
???5?000
**/