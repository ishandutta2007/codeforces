#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, k, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld", &n, &k);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int j;
    for(int i = 0; i < k; i++) {
        j = 0;
        for(; j + 1 < n && a[j] >= a[j+1]; j++);
        if(j == n - 1){
            j = -1;
            break;
        }
        else a[j]++;
    }
    printf("%d\n", (j == -1) ? -1 : j+1);
    if(--t) goto st;
    return 0;
}