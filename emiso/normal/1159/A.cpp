#include <bits/stdc++.h>

using namespace std;

int n, mini, now;
char s[101010];

int main() {
    scanf("%d %s", &n, &s);
    for(int i = 0; i < n; i++) {
        now += (s[i] == '+') ? 1 : -1;
        mini = min(mini, now);
    }
    printf("%d\n", now - mini);
    return 0;
}