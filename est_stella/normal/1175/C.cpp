#include<bits/stdc++.h>
using namespace std;

int t, n, k, m, x;
int a[300000];

int main() {
    scanf("%d", &t);

    for(int i=0; i<t; i++) {
        scanf("%d%d", &n, &k);
        m = 2000000000;

        for(int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }

        for(int i=0; i+k < n; i++) {
            if(m > a[i+k] - a[i]) m = a[i+k] - a[i], x = (a[i+k] + a[i]) / 2;
        }

        printf("%d\n", x);
    }
}