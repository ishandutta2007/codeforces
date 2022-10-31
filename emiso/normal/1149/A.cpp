#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, x, f1, f2, ans;

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &x);
        if(x == 1) f1++;
        else f2++;
    }

    if(!f1) for(int i = 0; i < n; i++) printf("2 ");
    else if(!f2) for(int i = 0; i < n; i++) printf("1 ");
    else {
        printf("2 1 ");
        f1--; f2--;
        while(f2) {
            f2--;
            printf("2 ");
        }
        while(f1) {
            f1--;
            printf("1 ");
        }
    }
    return 0;
}