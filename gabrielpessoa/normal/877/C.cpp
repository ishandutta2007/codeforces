#include <bits/stdc++.h>
using namespace std;

#define SIZE 5005
#define INF 0x3f3f3f

int main() {
    int n;
    cin >> n;
    printf("%d\n", (n/2)*2 + (n+1)/2);
    for(int i = 2; i <= n; i += 2) {
        printf("%d ", i);
    }
    for(int i = 1; i <= n; i += 2) {
        printf("%d ", i);
    }
    for(int i = 2; i <= n; i += 2) {
        printf("%d ", i);
    }
    return 0;
}