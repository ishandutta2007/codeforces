#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN], gret;
char s[MN]; string str;

int main() {
    scanf("%s", &s); str = s; n = str.size();

    ans = (n + 1) / 2;
    for(int i = 1; i < n; i++) {
        if(str[i] == '1') gret = 1;
    }
    if(!gret && (n % 2)) ans--;

    printf("%lld\n", ans);
    return 0;
}