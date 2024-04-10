#include <bits/stdc++.h>
using namespace std;
int n;
char s[200010];
int main() {
    scanf("%d%s", &n, s);
    n /= 2;
    int now = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '?') now += 9;
        else now += (s[i] - '0') * 2;
    }
    for(int i = n; i < n + n; i++) {
        if(s[i] == '?') now -= 9;
        else now -= (s[i] - '0') * 2;
    }
    puts(now ? "Monocarp" : "Bicarp");
}