#include <bits/stdc++.h>

#define MN 1000100
#define w1 while(1)

using namespace std;
typedef long long ll;

int n, a[MN], ans[MN], ansrev[MN], co = 1;
set <int> s;

int main() {
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s.insert(a[i]);
    }

    for(int x : s) {
        if(a[x] != x) {
            printf("-1\n");
            return 0;
        }

        ansrev[co] = x;
        ans[x] = co++;
    }

    printf("%d\n", s.size());
    for(int i=1; i<=n; i++) {
        printf("%d ", ans[a[i]]);
    } puts("");
    for(int i=1; i<co; i++) {
        printf("%d ", ansrev[i]);
    }
    return 0;
}