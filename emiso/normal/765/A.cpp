#include <bits/stdc++.h>

#define MN 1000100
#define w1 while(1)

using namespace std;

int n, a[MN], ans;
string home, str, from, to;
char s[100];
map<string, int> f;

int main() {
    scanf("%d", &n);

    scanf("%s", s);
    home = s;

    for(int i = 0; i < n; i++) {
        scanf("%s", s);
        str = s;
        from = str.substr(0, 3);
        to = str.substr(5, 3);

        f[from]++;
        f[to]++;
    }

    printf("%s\n", (f[home] % 2) ? "contest" : "home");

    return 0;
}