#include <bits/stdc++.h>
using namespace std;

int arr[1005];

int main() {
    int n, best = 0, temp, amount = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        if(arr[temp]++ == 0) {
            amount++;
        }
    }
    for(int i = 0; i < 1005; i++) {
        best = max(best, arr[i]);
    }
    printf("%d %d", best, amount);
    return 0;
}