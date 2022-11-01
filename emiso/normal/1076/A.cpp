#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans = -1;
char s[MN]; string str;

int main() {
    scanf("%lld %s", &n, s);
    str = s;

    for(int i = 1; i < n; i++) {
        if(str[i-1] > str[i]) {
            if(ans == -1) ans = i-1;
            break;
        }
        if(str[i-1] == str[i]) ans = i-1;
        if(str[i-1] < str[i]) ans = -1;
    }
    if(ans == -1) ans = n-1;

    for(int i = 0; i < n; i++) {
        if(i != ans) printf("%c", str[i]);
    } puts("");
    return 0;
}