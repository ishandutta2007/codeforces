#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a[100005], b[100005];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    b[n-1] = a[n-1];
    for(int i = n -2; i >= 0; i--) {
        b[i] = a[i+1] + a[i];
    }
    for(int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    return 0;
}