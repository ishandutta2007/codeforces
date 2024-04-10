#include <bits/stdc++.h>

#define MN 1000100
#define w1 while(1)

using namespace std;
typedef long long ll;

int n, a[MN], ans;

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    } sort(a, a + n);

    int flag = 0;
    for(int i = 2; i < n; i++) {
        if(a[i] < a[i-1] + a[i-2]) flag = 1;
    }

    printf("%s\n", flag ? "YES" : "NO");

    return 0;
}