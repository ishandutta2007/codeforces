#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, x, xo;
//char s[MN]; string str;

int main() {
    scanf("%d %d", &n, &x);

    if(n == 1 && x == 0) {
        printf("YES\n0\n");
        return 0;
    }

    if(n == 2 && x == 0) {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");

    if(n % 4 == 0 && x < 4 && x > 0) {
        printf("%d ", x);
        x = 0;
        n--;
    }

    int flag = 0;
    if(n % 4 == 2) flag = (1 << 17);

    int aux = (1 << 19) + 4;
    while(n > 4) {
        printf("%d %d %d %d ", aux + flag, aux + 1, aux + 2, aux + 3);

        flag = 0;
        aux += 4;
        n -= 4;
        assert(aux <= 1000000);
    }

    if(n == 1) {
        printf("%d\n", x);
    }

    else if(n == 2) {
        printf("%d %d\n", x + (1 << 18) + flag, (1 << 17) + (1 << 18));
    }

    else if(n == 3) {
        printf("%d %d %d\n", x + (1 << 17), (1 << 18), (1 << 17) + (1 << 18));
    }

    else {
        printf("%d %d %d %d\n", (1 << 18) + x, (1 << 18) + 1, (1 << 18) + 2, (1 << 18) + 3);
    }
    return 0;
}