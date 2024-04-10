#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, f1, f2;
char s[MN]; string str;

int main() {
    scanf("%lld %s", &n, s);
    str = s;

    for(char c : str) {
        if(c == '(') f1++;
        if(c == ')') f2++;
    }

    if((n % 2 == 1) || f1 != f2) {
        puts("-1");
        return 0;
    }

    int b = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') b++;
        else if(s[i] == ')') {
            b--;
            if(b < 0) {
                int j = i + 1;
                for(; j < n && b < 0; j++) {
                    if(s[j] == '(') b++;
                    if(s[j] == ')') b--;
                }
                ans += (j - i);
                i = j - 1;
            }
        }
    }

    printf("%lld\n", ans);
    return 0;
}