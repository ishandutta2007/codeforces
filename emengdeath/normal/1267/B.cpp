#include <bits/stdc++.h>
#define N 300003
using namespace std;
char s[N], t[N];
int c[N];
int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1), m = 0;
    for(int i = 1; i <= n; ++ i)
        if(i == 1 || s[i] != s[i - 1]) t[++ m] = s[i], c[m] = 1;
        else ++ c[m];
    if(m & 1) {
        int k = m / 2 + 1;
        if(c[k] == 1) puts("0");
        else {
            bool flag = 1; 
            for(int i = 1; i < k; ++ i)
                if(t[i] != t[m - i + 1] || c[i] + c[m - i + 1] < 3) { flag = 0; break; }
            if(flag) printf("%d\n", c[k] + 1);
            else puts("0");
        }
    } else puts("0");
}