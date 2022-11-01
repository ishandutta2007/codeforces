#include <bits/stdc++.h>

#define MN 2525

using namespace std;

int n;

int main() {
    scanf("%d", &n);

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            int k = i ^ j;
            if(k < j || k > n) continue;
            if(i + j <= k) continue;
            ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}