#include <iostream>
#include <cstdio>

using namespace std;

int M, d, n;

bool inr(int x, int y) {
    return (x + y >= d) and (x + y <= 2*n - d) and (y <= x + d) and (y >= x - d);
}

int main() {
    scanf("%d%d", &n, &d);
    
    scanf("%d", &M);
    
    for(int i = 0;i < M;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(inr(a, b)) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}