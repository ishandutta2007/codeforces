#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

ll n, a, b, ra = -1, rb = -1;

int main() {
    scanf("%lld %lld %lld", &n, &a, &b);

    for(int i = 0; i < MN; i++) {
        if(i * a > n) break;
        if((n - i*a) % b == 0) {
            ra = i;
            rb = (n - i*a) / b;
        }
    }

    if(ra == -1) {
        printf("-1\n");
        return 0;
    }

    for(int i = 1; i <= n; i++) {
        for(int k = 0; k < ra; k++) {
            for(int j = 1; j <= a; j++, i++) {
                if(j < a) printf("%d ", i + 1);
                else printf("%d ", i - j + 1);
            }
        }

        for(int k = 0; k < rb; k++) {
            for(int j = 1; j <= b; j++, i++) {
                if(j < b) printf("%d ", i + 1);
                else printf("%d ", i - j + 1);
            }
        }
    }

    return 0;
}