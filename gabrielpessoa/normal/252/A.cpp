#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[105], m = 0, n, xo;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            xo = arr[i];
            for(int k = i + 1; k <= j; k++) {
                xo = xo ^ arr[k];
            }
            m = max(m, xo);
        }
    }
    printf("%d", m);
}