#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, sum, a[MN], odd, b[MN];

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if(a[i] % 2 == 0) b[i] = a[i] / 2;
        else {
            if(odd % 2) {
                if(a[i] < 0) b[i] = (a[i] - 1) / 2;
                else b[i] = a[i] / 2;
            } else {
                if(a[i] < 0) b[i] = a[i] / 2;
                else b[i] = (a[i] + 1) / 2;
            }
            odd++;
        }
        printf("%lld\n", b[i]);
    }

    return 0;
}