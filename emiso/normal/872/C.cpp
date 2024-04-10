#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n;
ll ans, a[MN], x;
//char s[MN]; string str;

int main() {
    scanf("%d", &n);

    while(n--) {
        scanf("%lld", &x);
        if(x <= 11) {
            if(x == 4 || x == 6 || x == 9) printf("1\n");
            else if(x == 8 || x == 10) printf("2\n");
            else printf("-1\n");
        }
        else {
            if(x % 4 == 1) {
                printf("%d\n", 1 + (x - 9) / 4);
            }

            else if(x % 4 == 2) {
                printf("%d\n", 1 + (x - 6) / 4);
            }

            else if(x % 4 == 3) {
                printf("%d\n", 2 + (x - 15) / 4);
            }

            else {
                printf("%d\n", x / 4);
            }
        }
    }

    return 0;
}