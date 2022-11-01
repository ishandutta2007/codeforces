#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN];

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &ans);

        if(ans == 1) puts("-1");
        else if(ans % 3 == 1) {
            for(int j = 0; j + 2 < ans; j++) printf("2");
            printf("33\n");
        } else {
            for(int j = 0; j + 1 < ans; j++) printf("2");
            printf("3\n");
        }
    }
    return 0;
}