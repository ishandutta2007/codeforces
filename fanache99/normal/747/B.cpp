#include <cstdio>
//#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 255;

char s[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d\n%s", &n, s + 1);
    if (n % 4) {
        printf("===");
        return 0;
    }
    int a = 0, g = 0, t = 0, c = 0, other = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'A')
            a++;
        if (s[i] == 'G')
            g++;
        if (s[i] == 'T')
            t++;
        if (s[i] == 'C')
            c++;
        if (s[i] == '?')
            other++;
    }
    if (a > n / 4 || g > n / 4 || c > n / 4 || t > n / 4) {
        printf("===");
        return 0;
    }
    for (int i = 1; i <= n; i++)
        if (s[i] != '?')
            printf("%c", s[i]);
        else
            if (a < n / 4) {
                a++;
                printf("A");
            }
            else
                if (c < n / 4) {
                    c++;
                    printf("C");
                }
                else
                    if (t < n / 4) {
                        t++;
                        printf("T");
                    }
                    else
                        printf("G");
    return 0;
}