#include <cstdio>
//#include <iostream>
#include <cmath>

using namespace std;

const int MAXN = 100000;

char s[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, a, b;
    scanf("%d%d%d\n%s", &n, &a, &b, s + 1);
    if (s[a] == s[b]) {
        printf("0\n");
        return 0;
    }
    printf("1\n");
    return 0;
    return 0;
}