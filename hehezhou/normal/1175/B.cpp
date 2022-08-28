#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll int_max = (1ll << 32) - 1;
int n;
ll stx[100010], sty[100010];
int top;
char s[1000];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%s", s);
        if(s[0] == 'a') {
            stx[top]++;
        }
        else if(s[0] == 'f') {
            top++;
            stx[top] = 0;
            scanf("%I64d", sty + top);
        }
        else if(s[0] == 'e') {
            stx[top - 1] += sty[top] * stx[top];
            top--;
            if(stx[top] > int_max) return puts("OVERFLOW!!!"), 0;
        }
    }
    if(stx[top] > int_max) return puts("OVERFLOW!!!"), 0;
    cout << stx[top] << endl;
    return 0;
}