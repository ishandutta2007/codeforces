#include <bits/stdc++.h>

using namespace std;

char s[100010];
string str;
int n, p, q;

int main() {
    scanf("%d %s", &n, s); str = s;

    p = q = (n - 11) / 2;
    for(int i = 0; i < n; i++) {
        if(p && str[i] != '8') {
            p--;
            str[i] = '$';
        }
        else if(q && str[i] == '8') {
            q--;
            str[i] = '$';
        }
    }

    for(int i = 0; i < n; i++) {
        if(str[i] == '$') continue;
        if(str[i] == '8') puts("YES");
        else puts("NO");
        return 0;
    }

    return 0;
}