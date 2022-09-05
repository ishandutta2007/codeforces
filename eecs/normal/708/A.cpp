#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
char s[maxn];

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int pos = 1;
    while (s[pos] == 'a') pos++;
    if (pos > n) {
        s[n] = 'z';
    } else {
        while (pos <= n && s[pos] != 'a') s[pos]--, pos++;
    }
    printf("%s\n", s + 1);
    return 0;
}