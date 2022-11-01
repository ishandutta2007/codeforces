#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN], f[26];
char s[MN]; string str;

int main() {
    scanf("%s", s); str = s;
    for(char c : str) f[c-'a']++;

    for(int i = 0; i < 26; i++) {
        ans = max(ans, f[i]);
        ans = max(ans, f[i] * (f[i]-1) / 2);

        for(int j = 0; j < 26; j++) {
            if(j == i) continue;
            ll tot = 0, tmp = 0;

            for(char &c : str) {
                if(c-'a' == j) tot += tmp;
                if(c-'a' == i) tmp++;
            }

            ans = max(ans, tot);
        }
    }

    printf("%lld\n", ans);
    return 0;
}