#include <bits/stdc++.h>

using namespace std;

int n, a[110];

int main() {
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    int ans = 0;
    for(int i=-1; i<n; i++) {
        int c0 = 0, c1 = 0;
        for(int j=0; j<=i; j++) {
            if(a[j] == 0) c0++;
        }

        for(int j=i+1; j<n; j++) {
            if(a[j] == 1) c1++;
        }

        ans = max(ans, c0 + c1);
    }

    printf("%d\n", ans);
    return 0;
}