#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, x;
ll ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%d", &n);
    if(n % 2 == 0)
        x = n / 2 * 3;
    else
        x = n / 2 * 3 + 1;

    printf("%d\n", x);
    for(int i = 2; i <= n; i += 2)
        printf("%d ", i);

    for(int i = 1; i <= n; i += 2)
        printf("%d ", i);

    for(int i = 2; i <= n; i += 2)
        printf("%d ", i);

    return 0;
}