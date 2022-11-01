#include <bits/stdc++.h>

using namespace std;

#define MN 100010
int n, c[MN], t[MN], a[MN], b[MN];

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        if(i) a[i] = c[i] - c[i-1];
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
        if(i) b[i] = t[i] - t[i-1];
    }
    if(c[0] != t[0] || c[n-1] != t[n-1]) puts("No");
    else {
        sort(a + 1, a + n);
        sort(b + 1, b + n);
        for(int i = 1; i < n; i++) {
            if(a[i] != b[i]) {
                puts("No");
                return 0;
            }
        }
        puts("Yes");
    }
    return 0;
}