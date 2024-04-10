#include <bits/stdc++.h>

using namespace std;

int n, m;
char s[200020];
string s1, s2;

int main() {
    scanf("%d %d", &n, &m);
    scanf("%s", s); s1 = s;
    scanf("%s", s); s2 = s;

    if(n > m + 1) {
        puts("NO");
        return 0;
    }

    int i = 0;
    while(i < n && i < m) {
        if(s1[i] != s2[i]) break;
        i++;
    }

    if(i == n && i == m) puts("YES");
    else if(i == n || s1[i] != '*') puts("NO");
    else if(i == m && s1[i] == '*') puts("YES");
    else if(i == m) puts("NO");
    else {
        int j = n-1, k = m-1;
        while(s1[j] == s2[k]) j--, k--;
        if(i != j) puts("NO");
        else puts("YES");
    }
    return 0;
}