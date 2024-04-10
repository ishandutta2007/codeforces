#include <bits/stdc++.h>
using namespace std;
int len;
char s[1000010];
char ans[1000010];
int anslen;
int buc[200];
int main() {
    scanf("%s", s);
    len = strlen(s);
    int l = 0, r = len - 1;
    while(1) {
        if(r - l + 1 < 4) break;
        buc['a'] = buc['b'] = buc['c'] = 0;
        buc[s[l]]++;
        buc[s[l + 1]]++;
        buc[s[r]]++;
        buc[s[r - 1]]++;
        int lala = 0;
        if(buc['a'] > 1) lala = 'a';
        if(buc['b'] > 1) lala = 'b';
        if(buc['c'] > 1) lala = 'c';
        ans[anslen++] = lala;
        l += 2, r -= 2;
    }
    printf("%s", ans);
    reverse(ans, ans + anslen);
    if(l < r) printf("%c", s[l]);
    puts(ans);
    return 0;
}