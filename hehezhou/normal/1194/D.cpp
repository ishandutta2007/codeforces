#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        if(k % 3) puts(n % 3 ? "Alice" : "Bob");
        else if(n % (k + 1) % 3 == 0 && n % (k + 1) != k) puts("Bob");
        else puts("Alice");
    }
    return 0;
}