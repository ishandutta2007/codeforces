#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, k, ans, a[MN], f[26];
char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld", &n, &k);

    memset(f, 0, sizeof f);
    scanf("%s", s);
    for(int i = 0; i < n; i++) {
        f[s[i]-'a']++;
    }
    scanf("%s", s);
    for(int i = 0; i < n; i++) {
        f[s[i]-'a']--;
    }

    int flag = 1;
    for(int i = 0; flag && i < 26; i++) {
        if(f[i] < 0) flag = 0;
        else if(f[i] % k) flag = 0;
        else {
            if(i == 25 && f[i]) flag = 0;
            f[i+1] += f[i];
        }
    }

    printf("%s\n", flag ? "YES" : "NO");
    if(--t) goto st;
    return 0;
}